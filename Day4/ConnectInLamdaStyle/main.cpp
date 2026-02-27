#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MyClass.h"

int main(int argc, char **argv) {

	QGuiApplication theApp(argc,argv);

	qmlRegisterType<MyClass>("MyClass", 1, 0, "TekTutorMyClass");

	QQmlApplicationEngine engine;

	//MyClass myClass;
	engine.load( QUrl(QStringLiteral("qrc:/main.qml")));

	QObject *pRootObject  = engine.rootObjects().first();

	QObject *pMyClass = pRootObject->findChild<QObject*>("myClassObj");

	QObject::connect(
		pRootObject,
		SIGNAL( qmlSignal() ),
		pMyClass,
		SLOT( onQMLSignal() )
	);

	return theApp.exec();
}
