#include "widget.h"
#include <QImage>
#include <QDebug>
#include <QBitmap>
#include <QPicture>
#include <QPainter>
#include <QBrush>
#include <iostream>

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
    static int op = 0;
    QImage image_all(160,160,QImage::Format_Mono);
    QPainter painter(&image_all);
    painter.fillRect(image_all.rect(),QBrush(QColor("#ffffff")));
    QPixmap set;
    set.load(":/pic/set.png");
    painter.drawPixmap(QRect(16,16,32,32),set,set.rect());
    QPixmap calendar;
    calendar.load(":/pic/calendar.png");
    painter.drawPixmap(QRect(112,16,32,32),calendar,calendar.rect());

    QImage image_board(320,320,QImage::Format_Mono);
    painter.end();
    painter.begin(&image_board);
    QPen pen = painter.pen();
    pen.setBrush(QColor("#000000"));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(QColor("#000000"));
    static const QPoint points[5] = {
          QPoint(110,240),
          QPoint(210,240),
          QPoint(210, 100),
          QPoint(160, 50),
          QPoint(110, 100),
      };
    painter.drawPolygon(points,5);
    painter.end();
    painter.begin(this);
    QPixmap pixmap_board = QPixmap::fromImage(image_board, Qt::MonoOnly);
    //painter.drawImage(QRect(64,16,32,32),image_board);
    pixmap_board = pixmap_board.scaled(32,32);
    painter.drawPixmap(QRect(64,16,32,32), pixmap_board, pixmap_board.rect());


    painter.end();
    painter.begin(this);
    painter.drawImage(QRect(0,0,160,160),image_all,image_all.rect());

    if(op == 0) {
        op = 1;
        QBitmap bmp = QBitmap::fromImage(image_all,Qt::MonoOnly);
        bmp.save("screen.bmp");
        QImage image_all2("screen.bmp");
        qDebug()<<"depth:"<<image_all2.depth();
        const uchar *bits = image_all2.constBits();
        for(int y = 0; y<160; y++) {
            for(int x = 0; x < 160; x++) {
                std::cout<<image_all2.pixelIndex(x, y);
            }
            std::cout <<std::endl;
        }
        QFile file("frameBuffer.txt");
        file.open(QIODevice::WriteOnly |QIODevice::Text |QIODevice::Truncate);
        QTextStream stream(&file);
        for(int y = 0; y<160; y++) {
            for(int x = 0; x < 20; x++) {
                quint8 c = 0x00;
                for(int i = 0; i < 8; i++) {
                    c |= (image_all2.pixelIndex(x*8+i, y) << (7-i));
                }
               QString strbyte = QString::asprintf("0x%02x",c);
                stream<<strbyte<<",";
            }
            stream<<"\n";
        }
        file.close();

    }
}
