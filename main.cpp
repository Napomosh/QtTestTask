#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <qquickwindow.h>
#include "DocumentViewerModel.h"
#include "DocumentEditorModel.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    auto docViewerModel = std::make_unique<Models::DocumentViewerModel>();
    auto docEditorModel = std::make_unique<Models::DocumentEditorModel>();
    engine.rootContext()->setContextProperty("docViewerModel", docViewerModel.get());
    engine.rootContext()->setContextProperty("docEditorModel", docEditorModel.get());

    const QUrl view = QUrl::fromLocalFile("Views/DocumentViewer.qml");
    QObject::connect(&engine,&QQmlApplicationEngine::objectCreated, &app,
        [&view](QObject* obj, const QUrl& objUrl) {
            if (!obj && view == objUrl)
                QCoreApplication::exit(-1);
            QObject* fileDialog = obj->findChild<QObject*>("dialog");
            auto k = 0;
        },
        Qt::QueuedConnection);
    engine.load(view);

    return app.exec();
}
