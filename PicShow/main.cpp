#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "PicShowPanel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //4个参数的含义是，包名，主版本号，此版本好，QML类型名
    qmlRegisterType<PicShowPaintedItem>("tuduweb",1,0,"PicShow");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
