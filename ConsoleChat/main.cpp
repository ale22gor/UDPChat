#include <QCoreApplication>
#include <QTextStream>
#include <QHostAddress>

#include "consolewrapper.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream{stdout} <<"write username"<<endl;
    QTextStream qtin(stdin);

    QString name;
    name = qtin.readLine();

    QTextStream{stdout} <<"write local port"<<endl;
    quint16 localPort;
    localPort = qtin.readLine().toUShort();

    QTextStream{stdout} <<"write server port"<<endl;
    quint16 serverPort;
    serverPort = qtin.readLine().toUShort();

    QTextStream{stdout} <<"write server ip"<<endl;
    QString serverIpString;
    serverIpString = qtin.readLine();
    QHostAddress serverIp{serverIpString};

    ConsoleWrapper consoleWrapper(name,localPort,serverPort,serverIp);
    QObject::connect(&consoleWrapper, SIGNAL(disconnect()), &a, SLOT(quit()));

    return a.exec();
}
