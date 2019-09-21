#include "model.h"
#include "udpback.h"

Model::Model(QObject *parent) : QObject{parent}

{
    m_clientListModel = new ClientListModel{this};
    m_messagesList = new MessagesModel{this};
}

void Model::setupConnection(QString name, int localPort, int serverPort, QString serverIp)
{
    udpBack = new UDPBack(name, localPort, serverPort, serverIp, this);

    connect(udpBack, SIGNAL(messageRecieved(QString)),m_messagesList, SLOT(addMessage(QString)));
    connect(udpBack, SIGNAL(clientAdded(QString, bool)),m_clientListModel, SLOT(addClient(QString, bool)));
    connect(udpBack, SIGNAL(clientChanged(QString, bool)),m_clientListModel, SLOT(changeStatus(QString, bool)));

    connect(this, SIGNAL(sendPing()),udpBack, SLOT(sendPing()));
    connect(this, SIGNAL(sendMessage(QString)),udpBack, SLOT(sendMessage(QString)));

    //connect(this, SIGNAL(disconnect()),udpBack, SLOT(disconnected()));

}

