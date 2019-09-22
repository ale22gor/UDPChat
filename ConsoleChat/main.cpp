#include <QCoreApplication>
#include <QTextStream>

#include "consolewrapper.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream{stdout} <<"write username"<<endl;
    QTextStream qtin(stdin);

    QString name;
    name = qtin.readLine();

    QTextStream{stdout} <<"write local port"<<endl;
    int localPort;
    localPort = qtin.readLine().toUShort();

    QTextStream{stdout} <<"write server port"<<endl;
    int serverPort;
    serverPort = qtin.readLine().toUShort();

    QTextStream{stdout} <<"write server ip"<<endl;
    QString serverIp;
    serverIp = qtin.readLine();

    ConsoleWrapper consoleWrapper(name,localPort,serverPort,serverIp);
    QObject::connect(&consoleWrapper, &ConsoleWrapper::disconnect, &a, &QCoreApplication::quit);

    return a.exec();
}
