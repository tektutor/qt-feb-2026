#pragma once

#include <QObject>
#include <QDebug>

class MyMath : public QObject {
Q_OBJECT
public:
	MyMath(QObject *parent = nullptr);
	~MyMath();
	
	Q_INVOKABLE double add(double,double);
	Q_INVOKABLE double subtract(double,double);
	Q_INVOKABLE double multiply(double,double);
	Q_INVOKABLE double divide(double,double);
};
