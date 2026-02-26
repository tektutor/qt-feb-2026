#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Math.h"

int main(int argc, char **argv) {
	QGuiApplication theApp(argc,argv);

	qmlRegisterType<MyMath>("TekTutor",1,3, "TekTutorMath");

	QQmlApplicationEngine engine("main.qml");

	//MyMath myMath;
	//engine.rootContext()->setContextProperty("MyMath", &myMath);

	return theApp.exec();
}
