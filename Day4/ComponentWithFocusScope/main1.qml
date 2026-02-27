import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
	id: topWindow

	width: 1000
	height: 1000
	visible: true

	title: "Components"

	Column {
		anchors.centerIn: parent
		spacing: 20

		Loader { sourceComponent: comp1 }
		Loader { sourceComponent: comp2 }
	}
	Component {
        	id: comp1 

		Column {
			RadioButton {
				text: "Group A - Option 1"
				checked: true
				focus: true
			}
			RadioButton { text: "Group A - Option 2" }
			RadioButton { text: "Group A - Option 3" }
		}
    	}	
	Component {
        	id: comp2 

		Column {
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
