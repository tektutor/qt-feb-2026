import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
	width: 500
	height: 500
	visible: true

	StackView {
		id: stackView
		anchors.fill: parent
		initialItem: "Page1.qml"
	}
}

