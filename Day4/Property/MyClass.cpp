#include "MyClass.h"

MyClass::MyClass(QObject *parent): QObject(parent) {
}

QString MyClass::getName() {
	qDebug() << "C++ MyClass getName method invoked ... ";
	return name;
}

void MyClass::setName(QString name) {
	qDebug() << "C++ MyClass setName method invoked ...";

	this->name = name;
}

void MyClass::onButtonClickedCppMethod() {
	qDebug() << "MyClass C++ slot method invoked ...";
}	
