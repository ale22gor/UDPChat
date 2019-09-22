#include <QPushButton>
#include <QListView>
#include <QLineEdit>
#include <QGridLayout>
#include <QCloseEvent>

#include <QStringListModel>

#include "widget.h"



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

    connect(m_messageInput, &QLineEdit::returnPressed,this, &Widget::getMessage);
    connect(m_pingButton, &QPushButton::released,this, &Widget::sendPing);

}

Widget::~Widget()
{
}

void Widget::getMessage()
{
    QString message{m_messageInput->text()};
    emit sendMessage(m_messageInput->text());
}

void Widget::closeEvent(QCloseEvent *event)
{
    emit disconnect();
    event->accept();
}
