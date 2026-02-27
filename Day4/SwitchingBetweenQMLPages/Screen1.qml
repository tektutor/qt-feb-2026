import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
	Column {
		anchors.centerIn: parent
		spacing: 20

		Label { text: "This is Page 1" }

		Button {
			text: "Goto Page 2"
			onClicked:
				pageLoader.source = "Screen2.qml"
		}

	}
}
