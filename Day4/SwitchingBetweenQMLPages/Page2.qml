import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
	Column {
		anchors.centerIn: parent
		spacing: 20

		Label { text: "This is Page 2" }

		Button {
			text: "Back to Page 1"
			onClicked:
				stackView.pop()
		}

	}
}
