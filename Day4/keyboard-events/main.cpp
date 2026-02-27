#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char **argv ) {

	QGuiApplication theApp(argc,argv);

	QQmlApplicationEngine engine;
	engine.load ( QUrl ( QStringLiteral("main.qml") ) );

	return theApp.exec();

}
