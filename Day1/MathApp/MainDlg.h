#ifndef MAINDLG_H
#define MAINDLG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDebug>

class MainDlg : public QDialog
{
    Q_OBJECT
private:
    QPushButton *pAddBttn, *pSubtractBttn, *pMultiplyBttn, *pDivideBttn, *pExitBttn;
    QLineEdit *pFirstNumberEdit, *pSecondNumberEdit, *pResultEdit;
    QBoxLayout *pNavigationBttnLayout;
    QFormLayout *pFormLayout;
    QVBoxLayout *pMainLayout;

    double firstNumber, secondNumber, result;
public:
    MainDlg(QWidget *parent = nullptr);
    ~MainDlg();
private slots:
    void onAddButtonClicked();
    void onSubtractButtonClicked();
    void onMultiplyButtonClicked();
    void onDivideButtonClicked();
    void onExitButtonClicked();
};
#endif // MAINDLG_H
