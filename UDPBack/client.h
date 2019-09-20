#ifndef CLIENT_H
#define CLIENT_H

#include "udpback_global.h"


#include <QHostAddress>
#include <QString>

class UDPBACKSHARED_EXPORT Client
{
public:
    Client(QHostAddress, quint16, QString);
    Client(Client&& );
    Client(const Client&);

    QHostAddress m_clientAddress;
    quint16 m_clientPort;
    QString m_name;

    void setOnline(){online = !online;}
    bool isOnline() const {return online;}

    Client& operator=(Client other);


private:
    bool online;

};

#endif // CLIENT_H
