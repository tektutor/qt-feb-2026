# Day 4

## Lab - Component with FocusScope

Normally in QML, objects are created immediately when the file loads
<pre>
Rectangle {
    width: 100
    height: 100
}
</pre>

Components are useful in the below scenarios
<pre>
- You wish to create objects later
- You may create objects multiple times
- You would like to create objects dynamically
- to use with Loader
- to use in ListView delegates
- to use in Repeater
- Memory optimization
</pre>	

main.qml
<pre>
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
	id: topWindow

	width: 1000
	height: 1000
	visible: true

	title: "Components with Focus scope"

	Column {
		anchors.centerIn: parent
		spacing: 20

		Loader { sourceComponent: comp1 }
		Loader { sourceComponent: comp2 }
	}

	Component {
		id: comp1

		FocusScope {
			width: 300
			height: 200

			Rectangle {
				anchors.fill: parent
				radius: 6
				border.width: 2
				color: "#f0f0f0"
				border.color: parent.activeFocus ? "dodgerblue" : "gray"
			}

			Column {
				anchors.centerIn: parent
				spacing: 6

				RadioButton {
					text: "Group A - Option 1"
					checked: true
					focus: true
				}
				RadioButton { text: "Group A - Option 2" }
				RadioButton { text: "Group A - Option 3" }
			}
		}
	}

	Component {
		id: comp2

		FocusScope {
			width: 300
			height: 200

			Rectangle {
				anchors.fill: parent
				radius: 6
				border.width: 2
				color: "#f0f0f0"
				border.color: parent.activeFocus ? "dodgerblue" : "gray"
			}

			Column {
				anchors.centerIn: parent
				spacing: 6

				RadioButton {
					text: "Group B - Option 1"
					checked: true
					focus: true
				}
				RadioButton { text: "Group B - Option 2" }
				RadioButton { text: "Group B - Option 3" }
			}
		}
	}
}  
</pre>

## Lab - QML ListView

main.qml
<pre>
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
	width: 1000
	height: 1000
	visible: true

	ListView {
		width: 300
		height: 400

		ScrollBar.vertical: ScrollBar {
			policy: ScrollBar.AlwaysOn
		}

		model: ListModel {
			id: listModel

			ListElement { name: "Shankar"; age: 30 }
			ListElement { name: "Rafiq"; age: 40 }
			ListElement { name: "Stalin"; age: 50 }
		}

		delegate: Rectangle {
			width: parent.width
			height: 50
			color: index % 2 === 0 ? "red" : "green"

			Row {
				spacing: 10
				anchors.verticalCenter: parent.verticalCenter

				Text { 
					text: name 
					font.bold: true
					font.pointSize: 15
				}
				Text { 
					text: age 
					font.bold: true
					font.pointSize: 15
				}
			}
		}
	}
	
	Timer {
		running: true
		repeat: true
		interval: 1000
		onTriggered: {
			listModel.append( { name: "Test", age: 25 } )	
		}
	}
}	
</pre>


## Lab - QML GridView

main.qml
<pre>
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {

	width: 1000; height: 1000
	visible: true

	GridView {
		width: parent.width
		height: parent.height

		model: ContactsModel {id: model }
		delegate: Column {
			Image {
				width: 50; height: 50
				source: "portrait.png"
				anchors.horizontalCenter: parent.horizontalCenter
			}
			Text {
				text: name
				anchors.horizontalCenter: parent.horizontalCenter
			}
		}
	}

	Timer {
		running: true
		repeat: true
		onTriggered:
			model.append({"name": "New Name","portrait": "portraight.png"})

	}
}	
</pre>

## Lab - QML Loader

MyRectangle.qml
<pre>
import QtQuick 2.15

Rectangle {
	id: myRect

	width: 800
	height: 800

	radius: 50
	color: "steelblue"
}	
</pre>

main.qml
<pre>
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {

	width: 1000
	height: 1000
	visible: true

	title: "Dynamically loading qml"

	Loader {
		id: dynamicQMLLoader
	}

	MouseArea {
		anchors.fill: parent

		onClicked: {
			console.log("Mouse clicked")
			dynamicQMLLoader.source = "MyRectangle.qml"
		}
	}
}	
</pre>

## Lab - QML Q_PROPERTY

MyClass.h
<pre>
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
</pre>

MyClass.cpp
<pre>
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
</pre>

main.cpp
<pre>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "MyClass.h"

int main(int argc, char **argv) {

	QGuiApplication theApp(argc,argv);

	qmlRegisterType<MyClass>("TekTutor",1,3, "TekTutorMyClass");

	QQmlApplicationEngine engine;
	engine.load ( QUrl ( QStringLiteral("main.qml") ) );

	MyClass myClass;
	engine.rootContext()->setContextProperty("MyClass", &myClass);

	return theApp.exec();
}	
</pre>	

main.qml
<pre>
import QtQuick 2.15
import QtQuick.Controls 2.15
import TekTutor 1.3

ApplicationWindow {
	id: topWindow

	width: 500
	height: 500
	visible: true

	title: "QML Signal with Qt Slot"

	property string caption: "Click Me"

	TekTutorMyClass {
		id: myClass
	}

	Connections {
		target: topWindow
	}

	Rectangle {
		width: parent.width - 20
		height: parent.height - 20
		radius: 50
		color: "steelblue"

		Text {
			anchors.centerIn: parent
			text: caption
			font.pointSize: 25

			MouseArea {
				anchors.fill: parent

				onClicked: {
					//Set property
					myClass.name = "MyClass"
					console.log ("Mouse clicked" + myClass.name )
					//Get Property
					caption = myClass.name

					//Invoking C++ method from QML
					myClass.onButtonClickedCppMethod()
					myClass.setName("From QML")
					console.log(myClass.getName())
				}
			}
		}
	}
}	
</pre>

## Lab - QML Keyboard events

main.qml
<pre>
import QtQuick 2.7
import QtQuick.Controls 2.0

ApplicationWindow {
	width: 500
	height: 600
	visible: true

	color: "green"


	Rectangle {
		id: rect
		width: 50
		height: 50
		color: "blue"
		focus: true


		Keys.onPressed: {
			switch( event.key ) {
				case Qt.Key_Left: {
					if ( rect.x > 0 ) { 
						rect.x = rect.x - 5
					}
				}
				break;
				case Qt.Key_Right: {
					if ( rect.x < 550 ) rect.x = rect.x + 5
				}
				break;
				case Qt.Key_Up: {
					if ( rect.y > 0 ) rect.y = rect.y - 5
				}
				break;
				case Qt.Key_Down: {
					if ( rect.y < 550 ) rect.y = rect.y + 5
				}
				break;
			}
		}
	}
}	
</pre>

## Lab - QML Combobox ( Not in your agenda - can be skipped if not interested )

main.qml
<pre>
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
	width: 1000
	height: 1000
	visible: true

	ComboBox {
		model : [ "Mango", "Apple", "Grapes" ] 

		onCurrentTextChanged: {
			console.log("Selected: ", currentText )
		}
	}
}	
</pre>

## Lab - Q_BINDABLE

Notes
<pre>
- QBindable<T> is a class introduced in Qt 6 
- enables native C++ property bindings, similar to how bindings work in QML
- is part of Qt’s property binding system based on QProperty
- Before Qt6
  - Q_PROPERTY + getters/seters + NOTIFY signals were required
  - Property changes were signal-driven
  - No automatic reactive binding between C++ properties
</pre>

Without Q_Bindable MyClassOld.h
<pre>
#include <QObject>

class MyClassOld : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit MyClassOld(QObject *parent = nullptr)
        : QObject(parent), m_value(0) {}

    int value() const
    {
        return m_value;
    }

    void setValue(int v)
    {
        if (m_value == v)
            return;

        m_value = v;
        emit valueChanged();   // ❗ MUST emit manually
    }

signals:
    void valueChanged();       // ❗ Required for QML updates

private:
    int m_value;
};	
</pre>

With QBindable Modern version ( works from Qt6 )
<pre>
#include <QObject>
#include <QProperty>

class MyClassNew : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue
               BINDABLE bindableValue)

public:
    explicit MyClassNew(QObject *parent = nullptr)
        : QObject(parent), m_value(0) {}

    int value() const
    {
        return m_value;
    }

    void setValue(int v)
    {
        m_value = v;   // ❗ No manual signal emit
    }

    QBindable<int> bindableValue()
    {
        return QBindable<int>(&m_value);
    }

private:
    QProperty<int> m_value;
};	
</pre>

## Info - Debugging and Fixing Segmentation and Core Dumps

### Using deleted object
<pre>
QObject *pObj = new QObject;
delete pObj;
pObj->setObjectName("one way to invite crash"); 	
</pre>

How to fix? 
- use QPointer
- QPointer becomes nullptr automatically when object deleted
<pre>
QPointer<QObject> obj;	
</pre>


### Never manually delete child of QObject with parent

<pre>
QObject *child = new QObject(parent);
delete child; //  If parent deletes again → crash	
</pre>

### Accessing GUI from worker threads
<pre>
label->setText("hello"); 	
</pre>

What is the correct way to deal with this scenario?
- consider using signal
- or you can follow the below approach
- However, using signals and slots is the best approach 
<pre>
QMetaObject::invokeMethod(label, "setText",
                          Qt::QueuedConnection,
                          Q_ARG(QString, "hello"));	
</pre>

### May be some signal emitted and the slot provider got deleted already
Fix
<pre>
connect(sender, &Sender::signal,
        receiver, &Receiver::slot,
        Qt::AutoConnection);	
</pre>

### Using a stack allocated object via a global pointer
<pre>
void foo() {
    QObject obj;
    pSomeGlobalPointer = &obj;  // this will crash later
}
</pre>

### Qt/QML Crash debugging
<pre>
QT_LOGGING_RULES="qt.qml.*=true" ./MyApp	
</pre>

### Check for binding loops

### Use QObject Tree ( Very useful while debugging Crash )
<pre>
QObject::dumpObjectTree();	
</pre>

### Update your CMakeLists.txt
<pre>
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")	
</pre>

Rebuild
<pre>
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build	
</pre>

### Use Valgrind
<pre>
valgrind --tool=memcheck ./MyApp	
</pre>
