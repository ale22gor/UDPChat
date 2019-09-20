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

Client &Client::operator=(Client other)
{
    if(&other == this)
        return *this;

    std::swap(m_clientAddress, other.m_clientAddress);
    std::swap(m_clientPort, other.m_clientPort);
    std::swap(m_name, other.m_name);
    std::swap(online, other.online);

    return *this;
}

