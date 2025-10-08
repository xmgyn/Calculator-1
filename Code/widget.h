#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>
#include <climits>
#include <QScrollArea>

inline QLabel *Screen;
inline QScrollArea *ScrollArea;

class Widget : public QWidget
{
    Q_OBJECT

private:
    QString History = "", CurrentNumber = "", AnotherNumber = "", Operator = "" ;
    bool CurrentDecimal = false;
    void handleClick(const QString& text) {
        if (text == "+" || text == "-" || text == "*" || text == "/" ) {
            AnotherNumber = CurrentNumber;
            CurrentNumber = "";
            CurrentDecimal = false;
            Operator = text;

        } else if (text == "AC") {
            CurrentNumber = "";
            History = "";
            AnotherNumber = "";
            CurrentDecimal = false;
            Operator = "";
            Screen->setText("0\t\t");

        } else if (text == "=") {
            if (CurrentNumber.back() == '.') CurrentNumber.append("0");
            if (AnotherNumber.back() == '.') AnotherNumber.append("0");
            double result = 0;

            if (Operator == "+") {
                result = AnotherNumber.toDouble() + CurrentNumber.toDouble();
            } else if (Operator == "-") {
                result = AnotherNumber.toDouble() - CurrentNumber.toDouble();
            } else if (Operator == "*") {
                result = AnotherNumber.toDouble() * CurrentNumber.toDouble();
            } else if (Operator == "/") {
                result = AnotherNumber.toDouble() / CurrentNumber.toDouble();
            }

            History += "\t\t\n" + AnotherNumber + "\t\t\n" + Operator + "\t\t\t\t" + CurrentNumber + "\t\t\n" + "--------------\t\t\n" + QString::number(result) + "\t\t\n══════════════\t\t";


            CurrentNumber = "";
            AnotherNumber = "";
            CurrentDecimal = false;
            Operator = "";
            Screen->setText(History);
        } else if (text == ".") {
            if (!CurrentDecimal) {
                if (CurrentNumber == "") CurrentNumber.append("0");
                CurrentNumber.append(".");
                Screen->setText(CurrentNumber + "0");
                CurrentDecimal = true;
            }
        } else {
            if ((CurrentNumber.toDouble() * 10 + text.toDouble()) <= INT_MAX && CurrentNumber.size() < 12) {
                CurrentNumber.append(text);
                Screen->setText(History + "\t\t\n" + AnotherNumber + "\t\t\n" + Operator + "\t\t\t\t" + CurrentNumber + "\t\t");
            }

        }
    }

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void keyPressEvent(QKeyEvent* event) {
        if (event->key() == Qt::Key_Enter) {
            handleClick("=");
        } else if (event->key() == Qt::Key_Backspace) {

        } else {
            QString textl = event->text();
            QString allowedKeys = "1234567890./*-+=";

            if (!textl.isEmpty() && allowedKeys.contains(textl)) {
                handleClick(textl);
            }
        }
        event->accept();
    }


    class NormalButton : public QObject {
        QPushButton *Button;

    public:
        static Widget *parent;
        NormalButton(const QString& text) {
            Button = new QPushButton();
            Button->setFont(QFont("Consolas", 14));
            Button->setText(text);
            Button->setStyleSheet(R"(
    QPushButton {
        border: 1px solid black;
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
            connect(Button, &QPushButton::clicked, this, [=]() {
                parent->handleClick(text);
            });

        }
        QPushButton *Get() {
            return Button;
        }
        ~NormalButton() {
        }
    };
};
#endif // WIDGET_H
