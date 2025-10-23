#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Controller.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Controller controller;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("controller", &controller);
    engine.loadFromModule("AcademyScopeMobile", "Main");

    QObject *rootObject = engine.rootObjects().first();
    QObject *combo = rootObject->findChild<QObject*>("universityComboBox");
    //combo->lineEdit()->setAlignment(Qt::AlignLeft);
    return app.exec();
}
