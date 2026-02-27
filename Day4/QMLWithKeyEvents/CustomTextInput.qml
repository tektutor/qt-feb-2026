import QtQuick.Controls

Rectangle {
	width: 200
	height: 80
	
	border.width: 2

 	property alias inputFocus: textField.focus 	

	TextInput {
		id: textField
		Keys.onPressed:
			handleKeyEvents( event )
	}
}
