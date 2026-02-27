#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MyClass.h"

int main(int argc, char **argv) {

	QGuiApplication theApp(argc,argv);

	qmlRegisterType<MyClass>("MyClass", 1, 0, "TekTutorMyClass");

	QQmlApplicationEngine engine("main.qml");

	return theApp.exec();
}
