import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
	visible: true
	width: 500
	height: 500

	function handleKeyEvents( event ) {
		switch ( event.key ) {
			case  Qt.Key_Down: {
				if ( textField1.inputFocus === true ) {
					textField1.inputFocus = false
					textField2.inputFocus = true
				}
				else if ( textField2.inputFocus === true ) {
					textField2.inputFocus = false
					textField3.inputFocus = true
				}
				else if ( textField3.inputFocus === true ) {
					textField3.inputFocus = false
					textField1.inputFocus = true
				}
			}
		}
	}

	Column {
		anchors.centerIn: parent
		spacing: 10

		CustomTextInput {
			id: textField1
			inputFocus: true
		}
		CustomTextInput {
			id: textField2
		}
		CustomTextInput {
			id: textField3
		}
	}
}
