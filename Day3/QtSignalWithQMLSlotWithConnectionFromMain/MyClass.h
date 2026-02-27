#include <QObject>
#include <QDebug>
#include <QString>

class MyClass : public QObject {
Q_OBJECT
public:
	MyClass();
	~MyClass();
signals:
	void customQtSignal(QString);
};
