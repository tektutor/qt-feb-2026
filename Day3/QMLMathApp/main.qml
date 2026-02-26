import QtQuick.Controls 2.2
import QtQuick 2.9

ApplicationWindow {
	visible: true

	width: 500
	height: 500

	property double firstInput: 0.0
	property double secondInput: 0.0
	property double finalResult: 0.0

	Column {
		anchors.centerIn: parent
		spacing: 20

		Grid {
			rows: 3
			columns: 2
			spacing: 5

			Text {
				text: "First Number"
			}
			Edit {
				id: firstNumber
			}
			Text {
				text: "Second Number"
			}
			Edit {
				id: secondNumber
			}
			Text {
				text: "Result"
			}
			Edit {
				id: result 
			}
		}

		Row {
			spacing: 5
			Button {
				id: addButton
				text: "Add"

				onClicked: {
					firstInput = parseFloat( firstNumber.value )
					secondInput = parseFloat( secondNumber.value )
					finalResult = firstInput + secondInput
					result.value = finalResult
					console.log( firstInput )
					console.log( secondInput )
					console.log( finalResult )
				}
			}
			Button {
				id: subtractButton
				text: "Subtract"

				onClicked: {
					firstInput  = parseFloat( firstNumber.value)
					secondInput = parseFloat( secondNumber.value)
					finalResult = firstInput - secondInput
					result.value= finalResult
					console.log( finalResult )
				}
			}
			Button {
				id: multiplyButton
				text: "Multiply"

				onClicked: {
					firstInput = parseFloat( firstNumber.value)
					secondInput = parseFloat( secondNumber.value)
					finalResult = firstInput * secondInput
					result.value = finalResult
					console.log( finalResult )
				}
			}
			Button {
				id: divideButton
				text: "Divide"

				onClicked: {
					firstInput = parseFloat( firstNumber.value)
					secondInput = parseFloat( secondNumber.value)
					finalResult = firstInput / secondInput
					result.value = finalResult
					console.log( finalResult )
				}
			}
		}
	}
}
