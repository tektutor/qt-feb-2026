#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>

int main(int argc, char **argv) {

	QGuiApplication theApp(argc,argv);

	QQmlApplicationEngine engine("main.qml");

	QObject *pRootObject = engine.rootObjects().first();
	QObject *pQMLPage1   = pRootObject->findChild<QObject*>("firstQML");
	QObject *pQMLPage2   = pRootObject->findChild<QObject*>("secondQML");

	if ( pQMLPage1 ) 
		QMetaObject::invokeMethod( pQMLPage1, "function1" );

	if ( pQMLPage2 ) 
		QMetaObject::invokeMethod( pQMLPage2, "function1" );
	if ( pQMLPage2 ) 
		QMetaObject::invokeMethod( pQMLPage2, "function2" );

	return theApp.exec();

}
