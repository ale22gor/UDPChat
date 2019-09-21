#ifndef UDPBACK_H
#define UDPBACK_H

#include "udpback_global.h"
#include "client.h"

#include <QUdpSocket>
#include <QTimer>
#include <QObject>


class UDPBACKSHARED_EXPORT UDPBack :public QObject
{
    Q_OBJECT

public:
    UDPBack(QString, quint16, quint16, QString, QObject *parent = nullptr);


    QString m_name;

private:
    void sendData(const qint8, const QByteArray ,const Client *specificClient = nullptr);
    Client getClientInfo(QByteArray&);

    std::list<Client> clients;
    quint16 m_clientPort;
    Client m_server;

    QUdpSocket *udpSocket;

    QTimer *pingTimer;

signals:
    void messageRecieved(QString);
    void clientAdded(QString, bool);
    void clientChanged(QString, bool);

public slots:
    void readMessage();
    void sendPing();
    void disconnected();
    void sendMessage(QString);



};

#endif // UDPBACK_H
