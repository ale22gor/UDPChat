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

    connect(udpBack, &UDPBack::messageRecieved,m_messagesList, &MessagesModel::addMessage);
    connect(udpBack, &UDPBack::clientAdded,m_clientListModel, &ClientListModel::addClient);
    connect(udpBack, &UDPBack::clientChanged,m_clientListModel, &ClientListModel::changeStatus);

    connect(this, &Model::sendPing,udpBack, &UDPBack::sendPing);
    connect(this, &Model::sendMessage,udpBack, &UDPBack::sendMessage);

    connect(this, &Model::disconnect,udpBack, &UDPBack::disconnected);

}

