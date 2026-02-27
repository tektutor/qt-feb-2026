#include "MyClass.h"

MyClass::MyClass() {
	qDebug() << "MyClass constructor ...";
	emit cppSignal("CPP Signal triggered");
}

void MyClass::cppFunction() {
	qDebug() << "Inside MyClass cppFunction ...";
}
