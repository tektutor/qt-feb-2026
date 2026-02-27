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
