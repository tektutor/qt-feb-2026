#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QString>
#include <QDebug>

class MyClass : public QObject {
Q_OBJECT
Q_PROPERTY (QString name READ getName WRITE setName)
private:
	QString name;
public:
	explicit MyClass(QObject *parent = nullptr);
	Q_INVOKABLE QString getName();
	Q_INVOKABLE void setName(QString);

	Q_INVOKABLE void onButtonClickedCppMethod();
};

#endif /* MYCLASS_H */	
