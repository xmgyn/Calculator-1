#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QKeyEvent>
#include <QDebug>

inline QLCDNumber *Screen;

class Widget : public QWidget
{
    Q_OBJECT

private:
    double FirstNumber = 0, SecondNumber = 0;
    void handleClick(const QString& text) {
        qInfo() << text << "\n";
        if (text == "+" || text == "-" || text == "*" || text == "/" ) {

        } else if (text == "AC") {
            FirstNumber = 0;
            SecondNumber = 0;
            Screen->display(0);
        } else if (text == "=") {

        } else {
            FirstNumber = FirstNumber * 10 + text.toDouble();
            Screen->display(FirstNumber);
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
