#include <QDialog>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include "TabDlg.h"

class MainDlg : public QDialog {
Q_OBJECT
private:
	QTabWidget *pTabWidget;
	QHBoxLayout *pTopLayout;
	QHBoxLayout *pBottomLayout;
	QVBoxLayout *pMainLayout;

	QPushButton *pNewThreadBttn, *pStartBttn, *pStopBttn, *pExitBttn;
	int tabIndex;
public:
	MainDlg();
	~MainDlg();
signals:
	void startThread(QString);
	void stopThread(QString);
private slots:
	void onNewThreadButtonClicked();
	void onStartThreadButtonClicked();
	void onStopThreadButtonClicked();
	void onExitAppButtonClicked();
	void onTabSwitched(int);
};
