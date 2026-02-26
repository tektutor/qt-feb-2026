import QtQuick.Controls
import QtQuick

ApplicationWindow {
	id: topWindow 

	visible: true

	width: 280
	height: 300

	property double firstNumber: 0.0
	property double secondNumber: 0.0
	property double result: 0.0
	property string operator: ""

	Column {
		anchors.centerIn: parent
		spacing: 5
	CustomEdit{id: display }
	Row {
		spacing: 5
	Grid {
		spacing: 5
		rows: 4 
		columns: 3

		Repeater {
			model: 10
			CustomButton {}

			onItemAdded: {
				item.caption = index 
			}
		}

		CustomButton {
			caption : "."
			onButtonClicked:
			  console.log("Button with caption . clicked")
		}
		CustomButton {
			caption: "Ans"
		}
	}

	Column {
		spacing: 5
		OperatorButton { caption: "+" }
		OperatorButton { caption: "-" }
		OperatorButton { caption: "*" }
		OperatorButton { caption: "/" }
	}
	}
	}
}
