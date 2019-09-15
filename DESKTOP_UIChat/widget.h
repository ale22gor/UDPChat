#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHostAddress>
#include <QString>
#include "client.h"


class QStringList;
class QStringListModel;
class QCloseEvent;
class UDPBack;
class QPushButton;
class QListView;
class QLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *m_pingButton;
    QLineEdit *m_messageInput;
    QListView *m_clients, *m_messages;

    UDPBack *udpBack;

    QStringList *stringList;
    QStringListModel *listModel;

    QStringList *clientsList;
    QStringListModel *clientListModel;

public slots:
    void setupConnection(QString, quint16 , quint16, QHostAddress);
private slots:
    void sendMessage();
    void AddMessage(QString);


    void addClient(Client);
    void updateClient(Client);

    void closeEvent(QCloseEvent *event);

signals:
    void disconnect();
};

#endif // WIDGET_H
