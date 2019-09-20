#include "udpback.h"
#include <QNetworkInterface>
#include <QDataStream>
#include <QNetworkDatagram>


enum  MessageTypes{ HelloOnline, HelloOffline , Message , Ping ,
                    SendPingTo ,SomeFeature , AnotherFeature ,
                    UpdateInfo , OffOnLine , ExitChat };

UDPBack::UDPBack(QString name,quint16 clientPort, quint16 serverPort, QHostAddress serverIP, QObject *parent) : QObject(parent),
    m_name{name}, m_clientPort{clientPort}, m_server{serverIP,serverPort,"server"}
{

    udpSocket = new QUdpSocket(this);

    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    QHostAddress localIpAddress;
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
            localIpAddress = address;
    }

    udpSocket->bind(localIpAddress, m_clientPort);
    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(readMessage()));
    connect(udpSocket, SIGNAL(disconnected()),this, SLOT(disconnected()));


    pingTimer = new QTimer(this);
    connect(pingTimer, SIGNAL(timeout()), this, SLOT(sendPing()));
    pingTimer->start(3000);


    QByteArray nameAsBytes;
    nameAsBytes.append(m_name);

    sendData(HelloOnline,nameAsBytes,&m_server);

}

void UDPBack::sendData(const qint8 type, const QByteArray message, const Client *specificClient)
{
    QByteArray data;
    data.append(type);
    data.append(message);

    if(specificClient != nullptr){

        qDebug()<<"send:";
        qDebug()<<"ip:" << specificClient->m_clientAddress;
        qDebug()<<"port:" << specificClient->m_clientPort;
        qDebug()<<"data:" << data;


        udpSocket->writeDatagram(data,specificClient->m_clientAddress, specificClient->m_clientPort);
    }else{
        for (auto client:clients) {

            qDebug()<<"send:";
            qDebug()<<"ip:" << client.m_clientAddress;
            qDebug()<<"port:" << client.m_clientPort;
            qDebug()<<"data:" << data;

            if(client.isOnline())
                udpSocket->writeDatagram(data,client.m_clientAddress, client.m_clientPort);
        }
    }

}

void UDPBack::readMessage()
{
    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        QByteArray data  = datagram.data();
        quint8 type;

        QDataStream dataStream(data);
        dataStream >> type;

        data.remove(0,1);


        qDebug()<<"recieved:";
        qDebug()<<"ip:" << datagram.senderAddress();
        qDebug()<<"port:" << datagram.senderPort();
        qDebug()<<"type:" << type;
        qDebug()<<"message:" << data;




        switch(type){
        case HelloOnline:{

            Client newClient{getClientInfo(data)};
            clients.push_back(newClient);
            emit clientAdded(newClient.m_name, newClient.isOnline());

            break;
        }
        case HelloOffline:{
            Client newClient{getClientInfo(data)};
            newClient.setOnline();
            clients.push_back(newClient);
            emit clientAdded(newClient.m_name, newClient.isOnline());
            break;
        }
        case Message:{
            //QTextStream{stdout}  << message <<endl;
            QString message{data};
            emit messageRecieved(message);

            break;
        }
        case Ping:{

            break;
        }
        case SendPingTo:{
            Client newClient{getClientInfo(data)};
            sendData(Ping,"ping",&newClient);

            break;
        }

        case UpdateInfo:{

            Client updateClient{getClientInfo(data)};
            QString clientName {updateClient.m_name};
            auto oldInfo = std::find_if(clients.begin(),clients.end(),
                                        [&clientName] (Client const& c)
            {return (c.m_name == clientName) ; });
            //check end condition
            oldInfo->m_clientPort = updateClient.m_clientPort;
            oldInfo->m_clientAddress = updateClient.m_clientAddress;
            oldInfo->setOnline();

            emit clientChanged(oldInfo->m_name, oldInfo->isOnline());

            break;
        }
        case OffOnLine:{
            Client updateClient{getClientInfo(data)};
            QString clientName{updateClient.m_name};

            auto oldInfo = std::find_if(clients.begin(),clients.end(),
                                        [&clientName] (Client const& c)
            {return (c.m_name == clientName) ; });

            oldInfo->setOnline();
            emit clientChanged(oldInfo->m_name, oldInfo->isOnline());
            break;
        }
        }
    }

}

void UDPBack::sendPing()
{
    sendData(Ping,"ping",&m_server);
    sendData(Ping,"ping");
}

void UDPBack::disconnected()
{
    QByteArray nameAsBytes;
    nameAsBytes.append(m_name);
    sendData(OffOnLine,nameAsBytes, &m_server);
}

void UDPBack::sendMessage(QString message)
{
    QByteArray meessageWithName;
    meessageWithName.append(m_name);
    meessageWithName.append(':');
    meessageWithName.append(message);

    sendData(Message,meessageWithName);
}

Client UDPBack::getClientInfo(QByteArray &data)
{
    int index{data.indexOf('|')};
    QString ipStr = data.mid(0,index);
    data.remove(0,index+1);
    QHostAddress ip{ipStr};


    index = data.indexOf('|');
    quint16 port = data.mid(0,index).toUShort();
    data.remove(0,index+1);

    QString name{data};
    Client newClient{ip,port,name};
    return newClient;
}
