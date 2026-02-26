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
	bool isCreated;
	bool isRunning;
public:
	TabDlg(QString);
	bool isThreadCreated();
	bool isThreadRunning();
private slots:
	void onStartThread(QString);
	void onStopThread(QString);
	void onThreadMessage(QString);
};
