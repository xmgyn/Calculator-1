#include "widget.h"

#include <QVBoxLayout>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Calculator");
    setFixedSize(300,400);
    setWindowIcon(QIcon(":/icon/icons8-calculator-48.png"));

    QVBoxLayout *UI = new QVBoxLayout(this);

    QHBoxLayout *Panel1 = new QHBoxLayout();
    QGridLayout *Panel2 = new QGridLayout();

    UI->addLayout(Panel1);
    UI->addLayout(Panel2);

    Screen = new QLCDNumber();
    Screen->display(0);
    Screen->setFont(QFont("Times", 18));
    Screen->setStyleSheet("background-color : orange; color: white");

    Panel1->addWidget(Screen);

    QPushButton *equalButton = new QPushButton();
    equalButton->setText("=");
    equalButton->setFont(QFont("Times", 24));
    equalButton->setStyleSheet("background-color : red");

    NormalButton* plusButton = new NormalButton("+", Screen);
    NormalButton* minusButton = new NormalButton("-", Screen);
    NormalButton* mulButton = new NormalButton("*", Screen);
    NormalButton* divButton = new NormalButton("/", Screen);

    Panel2->addWidget(plusButton->Get(), 0,0);
    Panel2->addWidget(minusButton->Get(), 0,1);
    Panel2->addWidget(mulButton->Get(), 0,2);
    Panel2->addWidget(divButton->Get(), 0,3);

    NormalButton* N0Button = new NormalButton("0", Screen);
    NormalButton* N1Button = new NormalButton("1", Screen);
    NormalButton* N2Button = new NormalButton("2", Screen);
    NormalButton* N3Button = new NormalButton("3", Screen);
    NormalButton* N4Button = new NormalButton("4", Screen);
    NormalButton* N5Button = new NormalButton("5", Screen);
    NormalButton* N6Button = new NormalButton("6", Screen);
    NormalButton* N7Button = new NormalButton("7", Screen);
    NormalButton* N8Button = new NormalButton("8", Screen);
    NormalButton* N9Button = new NormalButton("9", Screen);

    NormalButton* NDotButton = new NormalButton(".", Screen);
    NormalButton* NSqButton = new NormalButton("x²", Screen);

    Panel2->addWidget(N7Button->Get(), 1,0);
    Panel2->addWidget(N8Button->Get(), 1,1);
    Panel2->addWidget(N9Button->Get(), 1,2);
    Panel2->addWidget(NDotButton->Get(), 1,3);

    Panel2->addWidget(N4Button->Get(), 2,0);
    Panel2->addWidget(N5Button->Get(), 2,1);
    Panel2->addWidget(N6Button->Get(), 2,2);
    Panel2->addWidget(NSqButton->Get(), 2,3);

    Panel2->addWidget(N1Button->Get(), 3,0);
    Panel2->addWidget(N2Button->Get(), 3,1);
    Panel2->addWidget(N3Button->Get(), 3,2);



    QPushButton *ACButton = new QPushButton();
    ACButton->setText("AC");
    ACButton->setFont(QFont("Consolas", 14));
    ACButton->setStyleSheet("background-color : green");

    Panel2->addWidget(N0Button->Get(), 4, 0, 1, 2);
    Panel2->addWidget(ACButton, 4,2);


    Panel2->addWidget(equalButton, 3, 3, 2, 1);
}

Widget::~Widget() {}
