#include "MainDlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDlg dlg;
    dlg.show();
    return a.exec();
}
