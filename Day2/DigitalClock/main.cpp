#include <QApplication>
#include "ClockDlg.h"

int main(int argc, char **argv) {

	QApplication theApp(argc,argv);

	ClockDlg dlg;
	dlg.show();

	return theApp.exec();

}
