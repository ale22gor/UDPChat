#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>



class QCloseEvent;
class QPushButton;
class QListView;
class QLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    QListView *m_clients, *m_messages;
    QPushButton *m_pingButton;
    QLineEdit *m_messageInput;

signals:
    void sendMessage(QString);
    void sendPing();
    void disconnect();
private slots:
    void getMessage();
    void closeEvent(QCloseEvent *event);
};

#endif // WIDGET_H
