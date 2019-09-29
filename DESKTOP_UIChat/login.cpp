#include "login.h"

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIntValidator>

Login::Login(QWidget *parent) :
    QDialog(parent)
{

    clientNameEdit = new QLineEdit;
    clientNameEdit->setPlaceholderText(tr("Username"));
    clientNameEdit->setMaxLength(12);
    clientNameEdit->setInputMask("Aaaaaaaaaaaa");

    clientPortEdit = new QLineEdit;
    clientPortEdit->setPlaceholderText(tr("local Port"));

    serverPortEdit = new QLineEdit;
    serverPortEdit->setPlaceholderText(tr("server Port"));

    QRegularExpressionValidator *portValidator = new QRegularExpressionValidator{
                QRegularExpression(
                    "([1-9]|[1-8][0-9]|9[0-9]|[1-8][0-9]{2}|9"
                    "[0-8][0-9]|99[0-9]|[1-8][0-9]{3}|9[0-8][0-9]{2}|"
                    "99[0-8][0-9]|999[0-9]|[1-5][0-9]{4}|6[0-4][0-9]{3}|"
                    "65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])"),this};
    clientPortEdit->setValidator(portValidator);
    serverPortEdit->setValidator(portValidator);

    serverIpEdit = new QLineEdit;
    serverIpEdit->setPlaceholderText(tr("server IP"));
    QString ipRange = "(([ 0]+)|([ 0]*[0-9] *)|([0-9][0-9] )|([ 0][0-9][0-9])|(1[0-9][0-9])|([2][0-4][0-9])|(25[0-5]))";
    // You may want to use QRegularExpression for new code with Qt 5 (not mandatory).
    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");

    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    serverIpEdit->setValidator(ipValidator);
    serverIpEdit->setInputMask("000.000.000.000");

    submitButton = new QPushButton{tr("Submit")};

    QVBoxLayout *myLayout = new QVBoxLayout;
    myLayout->addWidget(clientNameEdit);
    myLayout->addWidget(clientPortEdit);
    myLayout->addWidget(serverPortEdit);
    myLayout->addWidget(serverIpEdit);
    myLayout->addWidget(submitButton);

    setLayout(myLayout);

    connect(submitButton, &QPushButton::released,this, &Login::dataEntered);

}

Login::~Login()
{
}

void Login::dataEntered()
{

    QString name;
    int localPort;
    int serverPort;
    QString serverIp;
    name = clientNameEdit->text();
    localPort = clientPortEdit->text().toUShort();
    serverPort = serverPortEdit->text().toUShort();
    serverIp = serverIpEdit->text();

    emit dataComplete(name, localPort , serverPort, serverIp);

    accept();
}
