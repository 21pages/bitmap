#include "widget.h"
#include <QImage>
#include <QDebug>
#include <QBitmap>
#include <QPicture>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QFrame(parent)
{
//    QImage image;
//    image.load("C:/wisdom/done/55/bitmap/appbar.usb.png");
//    QBitmap map = QBitmap::fromImage(image);
//    QVector<QVector<uchar>> vec;
//    qDebug()<<map.toImage().width()<<map.toImage().height();
//    QImage image2 = map.toImage();
//    const uchar* data =  map.toImage().bits();
//    int x,y,w,h;
//    for(x = 0; x < map.width(); x++) {
//        for(int i =0; i < map.height(); i++) {
//        }
//    }

//    map.save("C:/wisdom/done/55/bitmap/appbar.usb.bmp");


}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter
}
