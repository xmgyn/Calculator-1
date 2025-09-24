#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QLCDNumber *Screen;

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
                LocalScreen->display(text);
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
