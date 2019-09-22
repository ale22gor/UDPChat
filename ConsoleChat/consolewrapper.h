#ifndef CONSOLEWRAPPER_H
#define CONSOLEWRAPPER_H

#include <QObject>
#include <QHostAddress>


class UDPBack;


class QSocketNotifier;

class ConsoleWrapper:public QObject
{
    Q_OBJECT

public:
    ConsoleWrapper(QString , int , int , QString , QObject *parent = nullptr);

signals:
    void disconnect();
    void sendPing();
    void sendMessage(QString);



private slots:
    void readConsole();
    void showMessage(QString);

private:
    UDPBack *udpBack;

    QSocketNotifier *m_notifier;
};

#endif // CONSOLEWRAPPER_H
