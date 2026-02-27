# Day 4

## Lab - Component with FocusScope

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
