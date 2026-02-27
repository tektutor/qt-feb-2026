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
