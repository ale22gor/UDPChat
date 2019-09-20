#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QVariant>
#include <QString>


#include "model.h"


int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();

    Model myModel;

    ctxt->setContextProperty("MessageModel", QVariant::fromValue(myModel.getMessageModel()));
    ctxt->setContextProperty("ClientModel", QVariant::fromValue(myModel.getClientModel()));

    //myModel.setupConnection("loh",1488,3228,QHostAddress{"192.168.0.11"});

    QObject::connect(ctxt, SIGNAL(login()), myModel, SLOT(setupConnection(QString,quint16,quint16,QString)));

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    engine.load(url);

    return app.exec();
}
