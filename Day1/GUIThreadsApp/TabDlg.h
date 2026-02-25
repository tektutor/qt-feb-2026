#pragma once

#include <QDialog>
#include <QListWidget>
#include <QHBoxLayout>
#include <QString>
#include "Thread.h"

class TabDlg : public QDialog {
Q_OBJECT
private:
	QListWidget *pListWidget;
	QHBoxLayout *pLayout;
	Thread *pThread;
	QString tabTitle;
public:
	TabDlg(QString);
private slots:
	void onStartThread(QString);
	void onStopThread(QString);
};
