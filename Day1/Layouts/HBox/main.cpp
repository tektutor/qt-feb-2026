#include <QApplication>
#include "MyDlg.h"

int main( int argc, char **argv ) {
	QApplication theApp(argc, argv);

	MyDlg dlg;
	dlg.show();

	//start the event handling - event loop
	return theApp.exec();
}
