#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>
#include <QHostAddress>
class QLineEdit;
class QPushButton;


class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    QLineEdit *clientNameEdit, *clientPortEdit, *serverPortEdit, *serverIpEdit;
    QPushButton *submitButton;
signals:
    void dataComplete(QString, quint16 , quint16, QHostAddress);
private slots:
    void dataEntered();
};

#endif // LOGIN_H
