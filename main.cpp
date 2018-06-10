#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "autoSellingSystem/messageCenter.h"
int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    MessageCenter *messageCenter = new MessageCenter();
    //Set the value of the name property on this context.
    engine.rootContext()->setContextProperty("messageCenter", messageCenter);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
