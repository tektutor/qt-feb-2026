import QtQuick

Rectangle {
	width: 215
	height: 50

	border.width: 2
	radius: 8

	property string value: "0.0"
	color: "lightgreen"

	Text {
		anchors.centerIn: parent
		text: value
	}
}
