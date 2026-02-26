#pragma once

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QTime>
#include <QTimer>
#include <QFont>

class ClockDlg : public QDialog {
Q_OBJECT
private:
	QLabel *pHoursLabel, *pMinutesLabel, *pSecondsLabel;
	QLabel *pHourSeparator, *pMinuteSeparator;
	QHBoxLayout *pLayout;
	int hours,minutes,seconds;
	QTimer *pTimer;
public:
	ClockDlg();
private slots:
	void onTimerTriggered();
};
