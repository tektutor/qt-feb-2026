import QtQuick

Rectangle {
	width: 50
	height: 50
	radius: 10 
	border.color: "black"

	property string caption: ""

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
			color: "black"
		}
	}

	MouseArea {
		anchors.fill: parent
		onClicked: {
			buttonClicked( caption )
			console.log( "Button " + caption + " clicked." )
			if ( display.value == "0.0" )
				display.value = caption
			else if ( caption == "Ans") {
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
			else
				display.value = display.value + caption
		}

	}
}


