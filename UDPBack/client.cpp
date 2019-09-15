#include "client.h"

Client::Client(QHostAddress clientAddress, quint16 clientPort, QString name):
    m_clientAddress{clientAddress},m_clientPort{clientPort},m_name{name},online{true}
{}

Client::Client(Client && client):
    m_clientAddress{std::move(client.m_clientAddress)},
    m_clientPort{std::move(client.m_clientPort)},
    m_name{std::move(client.m_name)},
    online{std::move(client.online)}

{}

Client::Client(const Client & client):
    m_clientAddress{client.m_clientAddress},
    m_clientPort{client.m_clientPort},
    m_name{client.m_name},
    online{client.online}

{}

