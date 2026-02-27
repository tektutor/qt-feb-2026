import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
	id: secondQML 
	objectName: "secondQML"

	function function1() {
		console.log( "Function 1 invoked from Second QML")
	}

	function function2() {
		console.log( "Function 2 invoked from Second QML")
	}

}
