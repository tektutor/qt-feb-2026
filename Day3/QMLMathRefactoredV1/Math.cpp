#include "Math.h"

MyMath::MyMath(QObject *parent): QObject(parent) {
	qDebug() << "MyMath constructor ...";
}

MyMath::~MyMath() {
	qDebug() << "MyMath destructor ...";
}

double MyMath::add( double firstNumber, double secondNumber ) {
	qDebug() << "Qt C++ MyMath add method invoked ...";
	return firstNumber + secondNumber;
}

double MyMath::subtract( double firstNumber, double secondNumber ) {
	qDebug() << "Qt C++ MyMath subtract method invoked ...";
	return firstNumber - secondNumber;
}

double MyMath::multiply( double firstNumber, double secondNumber ) {
	qDebug() << "Qt C++ MyMath multiply method invoked ...";
	return firstNumber * secondNumber;
}

double MyMath::divide( double firstNumber, double secondNumber ) {
	qDebug() << "Qt C++ MyMath divide method invoked ...";
	return firstNumber / secondNumber;
}
