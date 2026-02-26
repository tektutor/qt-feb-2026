import QtQuick

Rectangle {
	width: 50
	height: 50
	radius: 10 
	border.color: "black"

	property string caption: "button"

	signal buttonClicked( string caption )

	Text {
		anchors.centerIn: parent
		text: caption
		color: "white"
		font.pointSize: 10 
		font.bold: true
	}
	
	gradient: Gradient {
		GradientStop {
			position: 0
			color: "white"
		}
		GradientStop {
			position: 0.25
			color: "lightgray"
		}
		GradientStop {
			position: 0.5
			color: "gray"
		}
		GradientStop {
			position: 0.75
			color: "darkgray"
		}
		GradientStop {
			position: 1.0
			color: "blue"
		}
	}

	MouseArea {
		anchors.fill: parent
		onClicked: {
			if ( caption == "Ans") {
				topWindow.secondNumber = parseFloat(display.value)  
				display.value = ""
				if ( topWindow.operator == "+" )
					topWindow.result = topWindow.firstNumber + topWindow.secondNumber 
				else if ( topWindow.operator == "-" )
					topWindow.result = topWindow.firstNumber - topWindow.secondNumber 
				else if ( topWindow.operator == "*" )
					topWindow.result = topWindow.firstNumber * topWindow.secondNumber 
				else if ( topWindow.operator == "/" )
					topWindow.result = topWindow.firstNumber / topWindow.secondNumber 
				display.value = topWindow.result
			} 
			else {
				buttonClicked( caption )
				console.log( "Button " + caption + " clicked." )
				topWindow.firstNumber = parseFloat(display.value)  
				display.value = ""
				topWindow.operator = caption
			}
		}
	}
}


