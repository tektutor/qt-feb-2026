#include <QApplication>
#include "MyDlg.h"

int main(int argc, char **argv) {
	QApplication theApp(argc, argv);

	MyDlg dlg;
	dlg.show();

	//this will start event loop to support event handling
	//this keeps your Qt widgets GUI Application running forever
	//event loop keeps waiting for user events
	return theApp.exec();
}
