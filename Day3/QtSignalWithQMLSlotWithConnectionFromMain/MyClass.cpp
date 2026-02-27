#include "MyClass.h"

MyClass::MyClass() {
	qDebug() << "MyClass constructor ...";
	emit customQtSignal("MyClass custom Qt signal");
}

MyClass::~MyClass() {
	qDebug() << "MyClass destructor ...";
}

