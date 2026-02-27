import QtQuick.Controls
import QtQuick

Window {
	visible: true

	width: 300
	height: 500

	Flow {
		width: parent.width
		height: parent.height
		Repeater {
			model: 100
			Button{}

			onItemAdded:
				item.text = "Button " + index
		}
	}
}
