#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include<QString>
#include<QHostAddress>

#include "messagesmodel.h"
#include "clientlistmodel.h"

class UDPBack;




class Model : public QObject
{
    Q_OBJECT

    UDPBack *udpBack;

    ClientListModel* m_clientListModel;
    MessagesModel* m_messagesList;

public:
    explicit Model(QObject *parent = nullptr);
    ClientListModel * getClientModel(){return m_clientListModel;}
    MessagesModel * getMessageModel(){return m_messagesList;}


signals:
    void disconnect();

public slots:
    void setupConnection(QString, quint16 , quint16, QHostAddress);

};

#endif // MODEL_H
