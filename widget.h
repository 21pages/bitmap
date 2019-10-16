#ifndef WIDGET_H
#define WIDGET_H

#include <QFrame>
#include <QLabel>
#include <QTextEdit>
#include <QPaintEvent>

class Widget : public QFrame
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *) override;
};

#endif // WIDGET_H
