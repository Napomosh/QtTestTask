#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "DocumentViewerModel.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    auto docViewerModel = std::make_unique<Models::DocumentViewerModel>();
    engine.rootContext()->setContextProperty("docViewerModel", docViewerModel.get());

    const QUrl url = QUrl::fromLocalFile("Views/DocumentViewer.qml");
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
