#include <QSocketNotifier>
#include <QTextStream>

#include "consolewrapper.h"
#include "client.h"
#include "udpback.h"




ConsoleWrapper::ConsoleWrapper(QString name, int localPort, int serverPort, QString serverIp, QObject *parent):
    QObject(parent)
{

    m_notifier = new QSocketNotifier{ fileno(stdin), QSocketNotifier::Read, this};
    connect(m_notifier, &QSocketNotifier::activated, this, &ConsoleWrapper::readConsole);

    udpBack = new UDPBack(name, localPort, serverPort, serverIp, this);

    connect(udpBack, &UDPBack::messageRecieved,this, &ConsoleWrapper::showMessage);

    connect(this, &ConsoleWrapper::sendMessage,udpBack, &UDPBack::sendMessage);
    connect(this, &ConsoleWrapper::disconnect,udpBack, &UDPBack::disconnected);
    //connect(this, SIGNAL(sendPing()),udpBack, SLOT(sendPing()));


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
