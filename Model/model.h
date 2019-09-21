#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QString>

#include "messagesmodel.h"
#include "clientlistmodel.h"

class UDPBack;

#include "model_global.h"



class MODELSHARED_EXPORT Model : public QObject
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
    void sendMessage(QString);
    void sendPing();

public slots:
    void setupConnection(QString, int , int, QString);
};

#endif // MODEL_H

