#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>
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
    void dataComplete(QString, int , int, QString);
private slots:
    void dataEntered();
};

#endif // LOGIN_H
