import QtQuick 2.7
import QtQuick.Controls 2.0

ApplicationWindow {
	width: 500
	height: 600
	visible: true

	color: "green"


	Rectangle {
		id: rect
		width: 50
		height: 50
		color: "blue"
		focus: true


		Keys.onPressed: {
			switch( event.key ) {
				case Qt.Key_Left: {
					if ( rect.x > 0 ) { 
						rect.x = rect.x - 5
					}
				}
				break;
				case Qt.Key_Right: {
					if ( rect.x < 550 ) rect.x = rect.x + 5
				}
				break;
				case Qt.Key_Up: {
					if ( rect.y > 0 ) rect.y = rect.y - 5
				}
				break;
				case Qt.Key_Down: {
					if ( rect.y < 550 ) rect.y = rect.y + 5
				}
				break;
			}
		}
	}
}
