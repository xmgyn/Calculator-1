#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>

class Valuables {
public:
    double FirstNumber = 0, SecondNumber = 0;

    double FirstNumberGet() { return FirstNumber; };
    void FirstNumberSet(double value) { FirstNumber = value; };
    double SecondNumberGet() { return SecondNumber; };
    void SecondNumberSet(double value) { SecondNumber = value; };

};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QLCDNumber *Screen;
    static Valuables* Resource;

    class NormalButton : public QObject {
        QPushButton *Button;

    public:
        NormalButton(const QString& text, QLCDNumber* LocalScreen) {
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
                if (text == "+" || text == "-" || text == "*" || text == "/" ) {

                } else if (text == "AC") {

                } else if (text == "=") {

                } else {
                    Resource->FirstNumberSet(Resource->FirstNumberGet() * 10 + text.toDouble());
                    LocalScreen->display(Resource->FirstNumberGet());
                }
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
