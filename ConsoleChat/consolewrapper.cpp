#include <QSocketNotifier>
#include <QTextStream>

#include "consolewrapper.h"
#include "client.h"
#include "udpback.h"




ConsoleWrapper::ConsoleWrapper(QString name, quint16 localPort, quint16 serverPort, QHostAddress serverIp, QObject *parent):
    QObject(parent)
{
    /*
    m_notifier = new QSocketNotifier{ fileno(stdin), QSocketNotifier::Read, this};
    connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readConsole()));

    udpBack = new UDPBack(name, localPort, serverPort, serverIp, this);

    connect(udpBack, SIGNAL(messageRecieved(QString)),this, SLOT(showMessage(QString)));

    connect(this, SIGNAL(sendMessage(QString)),udpBack, SLOT(sendMessage(QString)));
    connect(this, SIGNAL(disconnect()),udpBack, SLOT(disconnected()));
    connect(this, SIGNAL(sendPing()),udpBack, SLOT(sendPing()));
    */

}

void ConsoleWrapper::readConsole()
{
    QTextStream qtin{stdin};
    QString message;
    message = qtin.readLine();

    if (message == "q") {

        QTextStream{stdout}  << "Good bye!" <<endl;
        emit disconnect();
    }else if (message == "ping") {
        emit sendPing();

    }else{
        emit sendMessage(message);
    }
}

void ConsoleWrapper::showMessage(QString message)
{
    QTextStream{stdout}  << message <<endl;

}
