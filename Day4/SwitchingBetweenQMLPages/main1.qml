import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
	width: 500
	height: 500
	visible: true

	Loader {
		id: pageLoader
		anchors.fill: parent
		source: "Screen1.qml"
	}

	footer: Row {
		spacing: 20

		Button {
			text: "Page 1"
			onClicked: pageLoader.source = "Screen1.qml"
		}
		Button {
			text: "Page 2"
			onClicked: pageLoader.source = "Screen2.qml"
		}
	}
}
