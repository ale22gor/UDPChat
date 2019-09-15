#include "widget.h"
#include "login.h"

#include <QApplication>
#include <QHostAddress>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Login login;
    QObject::connect(&login, SIGNAL(dataComplete(QString, quint16 , quint16, QHostAddress)),
                     &w,SLOT(setupConnection(QString, quint16, quint16, QHostAddress)));
    if (login.exec() == QDialog::Accepted)
        w.show();

    return a.exec();
}
