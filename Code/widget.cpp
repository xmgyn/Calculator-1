#include "widget.h"

#include <QVBoxLayout>
#include <QLCDNumber>
#include <QScrollBar>

Widget* Widget::NormalButton::parent = nullptr;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Calculator");
    setFixedSize(300,400);
    setWindowIcon(QIcon(":/icon/icons8-calculator-48.png"));
    setFocusPolicy(Qt::StrongFocus);

    NormalButton::parent = this;

    QVBoxLayout *UI = new QVBoxLayout(this);

    QHBoxLayout *Panel1 = new QHBoxLayout();
    QGridLayout *Panel2 = new QGridLayout();

    UI->addLayout(Panel1);
    UI->addLayout(Panel2);

    Screen = new QLabel();
    Screen->setText("0\t\t");
    Screen->setAlignment(Qt::AlignRight);
    Screen->setFont(QFont("DS-Digital", 18));
    Screen->setStyleSheet("background-color : orange; color: white");
    Screen->setWordWrap(true);

    ScrollArea = new QScrollArea();
    ScrollArea->setWidget(Screen);
    ScrollArea->setWidgetResizable(true);
    QScrollBar *Scroll = ScrollArea->verticalScrollBar();
    Scroll->setStyleSheet(R"(
    QScrollBar:vertical {
        background: orange;
        width: 5px;
        margin: 0px;
    }
    QScrollBar::handle:vertical {
        background: white;
    }
    QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
        height: 0px;
    }
    QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
        background: transparent;
    }
)");


    Panel1->addWidget(ScrollArea);

    QPushButton *equalButton = new QPushButton();
    equalButton->setText("=");
    equalButton->setFont(QFont("Consolas", 24));
    equalButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    equalButton->setStyleSheet(R"(
    QPushButton {
        border: 1px solid black;
        background-color : red
    }
    QPushButton:pressed {
        background-color: gray;
        padding-left: 2px;
        padding-top: 2px;
    }
    QPushButton:hover {
        background-color: #dcdcdc;
    }
)");
    connect(equalButton, &QPushButton::clicked, this, [=]() {
        this->handleClick("=");
    });

    NormalButton* plusButton = new NormalButton("+");
    NormalButton* minusButton = new NormalButton("-");
    NormalButton* mulButton = new NormalButton("*");
    NormalButton* divButton = new NormalButton("/");

    Panel2->addWidget(plusButton->Get(), 0,0);
    Panel2->addWidget(minusButton->Get(), 0,1);
    Panel2->addWidget(mulButton->Get(), 0,2);
    Panel2->addWidget(divButton->Get(), 0,3);

    NormalButton* N0Button = new NormalButton("0");
    NormalButton* N1Button = new NormalButton("1");
    NormalButton* N2Button = new NormalButton("2");
    NormalButton* N3Button = new NormalButton("3");
    NormalButton* N4Button = new NormalButton("4");
    NormalButton* N5Button = new NormalButton("5");
    NormalButton* N6Button = new NormalButton("6");
    NormalButton* N7Button = new NormalButton("7");
    NormalButton* N8Button = new NormalButton("8");
    NormalButton* N9Button = new NormalButton("9");

    NormalButton* NDotButton = new NormalButton(".");

    Panel2->addWidget(N7Button->Get(), 1,0);
    Panel2->addWidget(N8Button->Get(), 1,1);
    Panel2->addWidget(N9Button->Get(), 1,2);
    Panel2->addWidget(NDotButton->Get(), 1,3);

    Panel2->addWidget(N4Button->Get(), 2,0);
    Panel2->addWidget(N5Button->Get(), 2,1);
    Panel2->addWidget(N6Button->Get(), 2,2);

    Panel2->addWidget(N1Button->Get(), 3,0);
    Panel2->addWidget(N2Button->Get(), 3,1);
    Panel2->addWidget(N3Button->Get(), 3,2);



    QPushButton *ACButton = new QPushButton();
    ACButton->setText("AC");
    ACButton->setFont(QFont("Consolas", 14));
    ACButton->setStyleSheet(R"(
    QPushButton {
        border: 1px solid black;
        background-color : green
    }
    QPushButton:pressed {
        background-color: gray;
        padding-left: 2px;
        padding-top: 2px;
    }
    QPushButton:hover {
        background-color: #dcdcdc;
    }
)");
    connect(ACButton, &QPushButton::clicked, this, [=]() {
        this->handleClick("AC");
    });

    Panel2->addWidget(N0Button->Get(), 4, 0, 1, 2);
    Panel2->addWidget(ACButton, 4,2);


    Panel2->addWidget(equalButton, 2, 3, 3, 1);
}

Widget::~Widget() {}
