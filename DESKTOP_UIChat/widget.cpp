#include <QPushButton>
#include <QListView>
#include <QLineEdit>
#include <QGridLayout>
#include <QCloseEvent>
#include <QStringList>
#include <QStringListModel>

#include "widget.h"
#include "udpback.h"



Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    m_pingButton = new QPushButton{tr("Ping")};
    m_messageInput = new QLineEdit;
    m_clients = new QListView;
    m_messages = new QListView;

    QGridLayout *myLayout = new QGridLayout{};
    myLayout->addWidget(m_messages,0,0,1,3);
    myLayout->addWidget(m_clients,0,3,1,1);

    myLayout->addWidget(m_messageInput,1,0,1,3);
    myLayout->addWidget(m_pingButton,1,3,1,1);

    myLayout->setColumnStretch(0,3);
    myLayout->setColumnStretch(3,1);

    setLayout(myLayout);

    stringList = new QStringList();
    listModel = new QStringListModel(*stringList, this);

    clientsList = new QStringList();
    clientListModel = new QStringListModel(*clientsList, this);

    connect(m_messageInput, SIGNAL(returnPressed()),this, SLOT(sendMessage()));


}

Widget::~Widget()
{
}

void Widget::setupConnection(QString name, quint16 localPort, quint16 serverPort, QHostAddress serverIp)
{
    /*
    udpBack = new UDPBack(name, localPort, serverPort, serverIp, this);

    connect(udpBack, SIGNAL(messageRecieved(QString)),this, SLOT(AddMessage(QString)));
    connect(udpBack, SIGNAL( clientAdded(Client)),this, SLOT(addClient(Client)));
    connect(udpBack, SIGNAL( clientChanged(Client)),this, SLOT(updateClient(Client)));


    connect(this, SIGNAL(disconnect()),udpBack, SLOT(disconnected()));

    connect(m_pingButton, SIGNAL(released()),udpBack, SLOT(sendPing()));
    */

}

void Widget::sendMessage()
{
    QString message{m_messageInput->text()};
    AddMessage(message);
    udpBack->sendMessage(m_messageInput->text());
}

void Widget::addClient(Client newClient)
{
    QString stringToDisplay{newClient.m_name};
    if(newClient.isOnline())
        stringToDisplay.append(":online");
    else
        stringToDisplay.append(":offline");

    clientsList->append(stringToDisplay);
    clientListModel->setStringList(*clientsList);
    m_clients->setModel(clientListModel);
}

void Widget::updateClient(Client freshClient)
{
    QString stringToDisplay{freshClient.m_name};
    if(freshClient.isOnline())
        stringToDisplay.append(":online");
    else
        stringToDisplay.append(":offline");

    clientsList->replaceInStrings(QRegExp(freshClient.m_name+":.+"), stringToDisplay);
    clientListModel->setStringList(*clientsList);
    m_clients->setModel(clientListModel);
}

void Widget::closeEvent(QCloseEvent *event)
{
    emit disconnect();
    event->accept();
}

void Widget::AddMessage(QString message)
{
    stringList->append(message);
    listModel->setStringList(*stringList);
    m_messages->setModel(listModel);

}

