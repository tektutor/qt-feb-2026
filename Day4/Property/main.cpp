#include <QGuiApplication> 
#include <QQmlApplicationEngine>
#include <QUrl>
#include <QStringLiteral>
#include <QQmlContext>

#include "MyClass.h"

int main(int argc, char **argv) {

	QGuiApplication theApp(argc,argv);

	qmlRegisterType<MyClass>("TekTutor",1,3, "TekTutorMyClass");

	QQmlApplicationEngine engine;
	engine.load ( QUrl ( QStringLiteral("main.qml") ) );

	MyClass myClass;
	engine.rootContext()->setContextProperty("MyClass", &myClass);

	return theApp.exec();
}	

