import QtQuick.Controls
import QtQuick

Window {
	visible: true
	width: 500; height:500

	function myQMLFunction(message) {
		console.log( message )
	}
}
