#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QBoxLayout>
#include <QDebug>

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QPushButton *pBttn1, *pBttn2, *pBttn3, *pBttn4, *pBttn5;
    QBoxLayout *pLayout;
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void onButton1Clicked();
    void onButton2Clicked();
    void onButton3Clicked();
    void onButton4Clicked();
    void onButton5Clicked();

};
#endif // DIALOG_H
