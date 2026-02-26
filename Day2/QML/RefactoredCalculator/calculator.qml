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
	
		CustomButon { 
			caption: "0"
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButon { 
			caption: "1"
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButon { 
			caption: "2"
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButon { 
			caption: "3"
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButon { 
			caption: "4"
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButon { 
			caption: "5"
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButon { 
			caption: "6"
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButon { 
			caption: "7"
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButon { 
			caption: "8"
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButon { 
			caption: "9"
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButton {
			caption : "."
			onButtonClicked: {
				display.value = display.value + caption
			}
		}
		CustomButton {
			caption: "Ans"
			onButtonClicked:
			  console.log("Ans button clicked")
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
