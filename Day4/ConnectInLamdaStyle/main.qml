import QtQuick 2.12
import QtQuick.Controls 2.12
import MyClass 1.0

ApplicationWindow {
	visible: true
	width: 500
	height: 500

	signal qmlSignal()

	Button {
		text: "Request CPP Signal"
		onClicked: {
			console.log( "Emitting qmlSignal ..." )
			qmlSignal()
		}
	}


	TekTutorMyClass {
		id: myClass
		objectName: "myClassObj"

		onCppSignal:() => {
			console.log("CPP Signal received")
		}
	}		

	/*
	Connections {
		target: myClass
		function qmlSlot() {
			console.log("CPP Signal received - v2")
		}
	}
	*/

}
