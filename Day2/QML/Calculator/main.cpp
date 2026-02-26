#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char **argv) {

	QGuiApplication theApp(argc,argv);

	QQmlApplicationEngine engine("calculator.qml");

	return theApp.exec();

}
