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
