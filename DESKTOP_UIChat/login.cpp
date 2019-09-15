#include "login.h"

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

Login::Login(QWidget *parent) :
    QDialog(parent)
{
    submitButton = new QPushButton{tr("Submit")};
    clientNameEdit = new QLineEdit{tr("Username")};
    clientPortEdit = new QLineEdit{tr("1488")};
    serverPortEdit = new QLineEdit{tr("3228")};
    serverIpEdit = new QLineEdit{tr("192.168.0.100")};

    QVBoxLayout *myLayout = new QVBoxLayout{};
    myLayout->addWidget(clientNameEdit);
    myLayout->addWidget(clientPortEdit);
    myLayout->addWidget(serverPortEdit);
    myLayout->addWidget(serverIpEdit);
    myLayout->addWidget(submitButton);

    setLayout(myLayout);

    connect(submitButton, SIGNAL(released()),this, SLOT(dataEntered()));

}

Login::~Login()
{
}

void Login::dataEntered()
{
    QString name;
    quint16 localPort;
    quint16 serverPort;
    QHostAddress serverIp;
    name = clientNameEdit->text();
    localPort = clientPortEdit->text().toUShort();
    serverPort = serverPortEdit->text().toUShort();
    serverIp = QHostAddress{serverIpEdit->text()};

    emit dataComplete(name, localPort , serverPort, serverIp);

    accept();
}
