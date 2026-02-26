import QtQuick.Controls 2.2

Rectangle {
	border.color: "black"
	border.width: 2
	width: 205
	height: 30
	radius: 5

	property alias value: textInput.text 


	TextInput {
		id: textInput

		anchors.centerIn: parent

		width:  parent.width - 5 
		height: parent.height - 5 
		color: "blue"

		horizontalAlignment: TextInput.AlignRight
		verticalAlignment: TextInput.AlignVCenter

		MouseArea {
			anchors.fill: parent

			onClicked:
				parent.focus = true
		}

		validator: DoubleValidator {
			top: 10000.0
			bottom: 0.0 
			decimals: 2
			notation: DoubleValidator.StandardNotation
		}
	}

}
