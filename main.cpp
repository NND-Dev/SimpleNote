#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "model.h"
#include <QQmlContext>
#include <QQuickStyle>
#include <QIcon>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");
    app.setWindowIcon(QIcon("qrc:/img/pencil.png"));
    app.setApplicationName("Ghi chú");
    app.setApplicationVersion("1.1");


    qmlRegisterType<Model>("NND.Model",1,0,"Model");


    QQmlApplicationEngine engine;


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
