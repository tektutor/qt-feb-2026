#include <QObject>
#include <QString>
#include <QDebug>

class MyClass : public QObject {
Q_OBJECT
public:
	MyClass();
	Q_INVOKABLE void cppFunction();
signals:
	void cppSignal( );
public slots:
	void onQMLSignal();
};
