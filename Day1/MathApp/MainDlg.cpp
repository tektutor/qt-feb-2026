#include "MainDlg.h"

MainDlg::MainDlg(QWidget *parent)
    : QDialog(parent)
{
    pFirstNumberEdit = new QLineEdit();
    pSecondNumberEdit = new QLineEdit();
    pResultEdit = new QLineEdit();

    pFormLayout = new QFormLayout;
    pFormLayout->addRow( "First Number", pFirstNumberEdit );
    pFormLayout->addRow( "Second Number", pSecondNumberEdit );
    pFormLayout->addRow( "Result", pResultEdit );
    pFormLayout->setFormAlignment( Qt::AlignCenter | Qt::AlignTop );

    pNavigationBttnLayout = new QBoxLayout(QBoxLayout::LeftToRight);

    pAddBttn = new QPushButton("Add");
    pSubtractBttn = new QPushButton("Subtract");
    pMultiplyBttn = new QPushButton("Multiply");
    pDivideBttn = new QPushButton("Divide");
    pExitBttn = new QPushButton("Exit");

    pNavigationBttnLayout->addStretch(); //To right align the buttons
    pNavigationBttnLayout->addWidget(pAddBttn);
    pNavigationBttnLayout->addWidget(pSubtractBttn);
    pNavigationBttnLayout->addWidget(pMultiplyBttn);
    pNavigationBttnLayout->addWidget(pDivideBttn);
    pNavigationBttnLayout->addWidget(pExitBttn);

    pMainLayout = new QVBoxLayout;
    pMainLayout->addLayout( pFormLayout );
    pMainLayout->addLayout(pNavigationBttnLayout);

    setLayout( pMainLayout );

    connect(
        pAddBttn,
        SIGNAL( clicked() ),
        this,
        SLOT ( onAddButtonClicked() )
    );
    connect(
        pSubtractBttn,
        SIGNAL( clicked() ),
        this,
        SLOT ( onSubtractButtonClicked() )
    );
    connect(
        pMultiplyBttn,
        SIGNAL( clicked() ),
        this,
        SLOT ( onMultiplyButtonClicked() )
    );
    connect(
        pDivideBttn,
        SIGNAL( clicked() ),
        this,
        SLOT ( onDivideButtonClicked() )
    );
    connect(
        pExitBttn,
        SIGNAL( clicked() ),
        this,
        SLOT ( onExitButtonClicked() )
    );
}

void MainDlg::onAddButtonClicked() {
    qDebug() << "Add button clicked ...";

    QString strFirstNumber = pFirstNumberEdit->text();
    QString strSecondNumber = pSecondNumberEdit->text();

    firstNumber = strFirstNumber.toDouble();
    secondNumber = strSecondNumber.toDouble();
    result = firstNumber + secondNumber;

    QString strResult;
    strResult.setNum( result );

    pResultEdit->setText ( strResult );
}
void MainDlg::onSubtractButtonClicked() {
    qDebug() << "Subtract button clicked ...";

    QString strFirstNumber = pFirstNumberEdit->text();
    QString strSecondNumber = pSecondNumberEdit->text();

    firstNumber = strFirstNumber.toDouble();
    secondNumber = strSecondNumber.toDouble();
    result = firstNumber - secondNumber;

    QString strResult;
    strResult.setNum( result );

    pResultEdit->setText ( strResult );
}

void MainDlg::onMultiplyButtonClicked() {
    qDebug() << "Multiply button clicked ...";

    QString strFirstNumber = pFirstNumberEdit->text();
    QString strSecondNumber = pSecondNumberEdit->text();

    firstNumber = strFirstNumber.toDouble();
    secondNumber = strSecondNumber.toDouble();
    result = firstNumber * secondNumber;

    QString strResult;
    strResult.setNum( result );

    pResultEdit->setText ( strResult );
}

void MainDlg::onDivideButtonClicked() {
    qDebug() << "Divide button clicked ...";

    QString strFirstNumber = pFirstNumberEdit->text();
    QString strSecondNumber = pSecondNumberEdit->text();

    firstNumber = strFirstNumber.toDouble();
    secondNumber = strSecondNumber.toDouble();
    result = firstNumber / secondNumber;

    QString strResult;
    strResult.setNum( result );

    pResultEdit->setText ( strResult );
}

void MainDlg::onExitButtonClicked() {
    qDebug() << "Exit button clicked ...";
    QDialog::close();
}

MainDlg::~MainDlg() {}
