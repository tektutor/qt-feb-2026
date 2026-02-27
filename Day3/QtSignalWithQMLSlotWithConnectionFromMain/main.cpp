#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include "MyClass.h"

int main(int argc, char **argv) {
	QGuiApplication theApp(argc, argv);

	MyClass myClass;

	QQmlApplicationEngine engine("main.qml");

	//This is not possible as QML Javascript function is technically
	//not a Slot as per MOC, hence we won't be able to connect it
	/*
	QObject::connect(
		&myClass,
		SIGNAL(customQtSignal(QString)),
	        engine.rootObjects()[0],
	        SLOT(myQMLFunction(QString))		
	);*/

	QObject *pRootObject = engine.rootObjects().first();
	QMetaObject::invokeMethod( 
		pRootObject, 
		"myQMLFunction", 
		Q_ARG(QVariant, "QML Function invoked from C++ main entry point function" ) 
	); 

	//MyClass myClassObj2(pRootObject);

	return theApp.exec();
}
