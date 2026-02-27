#include "MyClass.h"

MyClass::MyClass() {
	qDebug() << "MyClass constructor ...";
	emit cppSignal();
}

void MyClass::cppFunction() {
	qDebug() << "Inside MyClass cppFunction ...";
}

void MyClass::onQMLSignal() {
	qDebug() << "QML Signal received ...";
	emit cppSignal();
	qDebug() << "Emitted cppSignal ...";
}
