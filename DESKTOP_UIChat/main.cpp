#include <QApplication>
#include <QListView>


#include "widget.h"
#include "login.h"
#include "model.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Login login;
    Model myModel;
    QObject::connect(&login, &Login::dataComplete,&myModel,&Model::setupConnection);

    w.m_clients->setModel(myModel.getClientModel());
    w.m_messages->setModel(myModel.getMessageModel());

    QObject::connect(&w, &Widget::sendMessage,&myModel, &Model::sendMessage);
    QObject::connect(&w, &Widget::sendMessage, myModel.getMessageModel(), &MessagesModel::addMessage);
    QObject::connect(&w, &Widget::sendPing,&myModel, &Model::sendPing);
    QObject::connect(&w, &Widget::disconnect,&myModel, &Model::disconnect);


    if (login.exec() == QDialog::Accepted)
        w.show();
    else
        a.quit();

    return a.exec();
}
