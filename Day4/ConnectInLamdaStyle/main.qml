import QtQuick 2.12
import QtQuick.Controls 2.12
import MyClass 1.0

ApplicationWindow {
	visible: true
	width: 500
	height: 500

	TekTutorMyClass {
		id: myClass

		onCppSignal:(message) => {
			console.log(message)
		}
	}		

}
