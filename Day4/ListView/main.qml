import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
	width: 1000
	height: 1000
	visible: true

	ListView {
		id: myList
		width: 300
		height: 400

		anchors.centerIn: parent

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
			width: myList.width
			height: 50
			color: index % 2 === 0 ? "lightgray" : "green"

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
