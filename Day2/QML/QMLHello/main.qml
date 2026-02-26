import QtQuick.Controls 2.12 
import QtQuick

ApplicationWindow {
	id: topWindow

	visible: true

	property int windowWidth: 500

	width: windowWidth 
	height: 500

	Rectangle {
		id: myRect

		anchors.centerIn: parent

		width: 400
		height: 100
		
		radius: 50
		border.color: "red"
		border.width: 5

		color: "gray"

		Text {
			anchors.centerIn: parent 
			text: "Hello QML !"
			color: "white"
			font.pointSize: 20
			font.bold: true
		}

		MouseArea {
			anchors.fill: parent
			hoverEnabled: true

			onClicked: {
				console.log("Rectangle clicked")
				myRect.color = "blue"
				windowWidth = 1000
		        }

			onEntered: {
				parent.scale = 1.2
				parent.border.color = "green"
				windowWidth = 1000

			}
			onExited: {
				parent.scale = 1.0
				parent.border.color = "red"
				windowWidth = 400
			}

		}

	}

}
