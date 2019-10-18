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

#define D 32
#define R 16

void Widget::paintEvent(QPaintEvent *)
{
    static int op = 0;
    QImage image_all(160,160,QImage::Format_Mono);
    QPainter painter;
    painter.begin(&image_all);
    painter.fillRect(image_all.rect(),QBrush(QColor("#ffffff")));
//    QPixmap set;
//    set.load(":/pic/set.png");
//    painter.drawPixmap(QRect(R,D,D,D),set,set.rect());

    //1
    painter.end();
    QImage image_set(D,D,QImage::Format_Mono);
    painter.begin(&image_set);
    QPen p = painter.pen();
    p.setBrush(QColor("#000000"));
    p.setWidth(2);
    painter.setPen(p);
    painter.fillRect(image_set.rect(),QBrush(QColor("#ffffff")));
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.translate(R,R);
    for(int i = 0; i< 16;i++) {
        if(i%2 == 0) {
            QPainterPath path;
            path.moveTo(-2,10);
            path.lineTo(-2,14);
            path.lineTo(2,14);
            path.lineTo(2,10);
            painter.drawPath(path);
        }else {
            painter.drawArc(QRect(QPoint(-10,-10),QPoint(10,10)),(90+23)*16,10*16);
            painter.rotate(/*22*/45);
        }
    }
    painter.drawEllipse(QPoint(0,0),4,4);
    painter.end();
    painter.begin(&image_all);
    painter.drawImage(QRect(R,D,D,D),image_set);
    painter.end();


    //2
    QImage image_board(D,D,QImage::Format_Mono);
    painter.begin(&image_board);
    QPen pen = painter.pen();
    pen.setBrush(QColor("#000000"));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.fillRect(image_board.rect(),QBrush(QColor("#ffffff")));
    painter.translate(R,R);
    painter.rotate(45);
    static const QPoint points[5] = {
          QPoint(-(R-8), -(R-10)),
          QPoint(-(R-8),R-5),
          QPoint(R-8,R-5),
          QPoint(R-8, -(R-10)),
          QPoint(0, -(R-2)),
      };
    painter.drawPolygon(points,5);
    painter.drawLine(QPoint(-(R-12),2),QPoint(R-12,2));
    painter.drawLine(QPoint(-(R-12),5),QPoint(R-12,5));
    painter.drawLine(QPoint(-(R-12),-1),QPoint(R-12,-1));
    //painter.drawPoint(0,-(R-8));
    painter.drawEllipse(0,-(R-8),1,1);
    painter.end();
    painter.begin(&image_all);
    painter.drawImage(QRect(2*D,D,D,D),image_board);
    painter.end();

    //3
    painter.begin(&image_all);
    QPixmap calendar;
    calendar.load(":/pic/calendar.png");
    painter.drawPixmap(QRect(160-R-D,D,D,D),calendar,calendar.rect());
    painter.end();

    //4
    QImage image_db(D,D,QImage::Format_Mono);
    painter.begin(&image_db);
    pen = painter.pen();
    pen.setBrush(QColor("#000000"));
    pen.setWidth(1);
    painter.setPen(pen);
//    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.fillRect(image_db.rect(),QBrush(QColor("#ffffff")));
    painter.translate(R,R);
    painter.drawLine(QPoint(-(R-5),-(R-7)),QPoint(-(R-5),R-7));
    painter.drawLine(QPoint(R-5,-(R-7)),QPoint(R-5,R-7));
    painter.drawEllipse(QPoint(0,-(R-7)),R-5, 5);
    painter.drawArc(QRect(-(R-5),R-12,D-10,10),180*16,180*16);
    painter.end();
    painter.begin(&image_all);
    painter.drawImage(QRect(R,D*3,D,D),image_db);
    painter.end();

    //5
    QImage image_pc(D,D,QImage::Format_Mono);
    painter.begin(&image_pc);
    pen = painter.pen();
    pen.setBrush(QColor("#000000"));
    pen.setWidth(6);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.fillRect(image_pc.rect(),QBrush(QColor("#ffffff")));
    painter.translate(R,0);
    painter.drawRect(-(R-6),6,D-12,12);
    painter.drawLine(QPoint(-2,18),QPoint(-2,27));
    painter.drawLine(QPoint(2,18),QPoint(2,27));
    painter.drawLine(QPoint(-(R-4),27),QPoint(R-4,27));
    pen = painter.pen();
    pen.setWidth(2);
    pen.setBrush(QColor("#ffffff"));
    painter.setPen(pen);
    painter.drawEllipse(QPoint(0,25),1,1);

    painter.end();
    painter.begin(&image_all);
    painter.drawImage(QRect(2*D,D*3,D,D),image_pc);
    painter.end();


    //6
    QImage image_user(D,D,QImage::Format_Mono);
    painter.begin(&image_user);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.fillRect(image_user.rect(),QBrush(QColor("#ffffff")));
//    QPixmap pixmap_user(":/pic/user1.png");
//    painter.drawPixmap(QRect(2,8,R-2,D-14),pixmap_user,pixmap_user.rect());
    QPixmap pixmap_user(":/pic/user3.bmp");
    painter.drawPixmap(image_user.rect(),pixmap_user,pixmap_user.rect());
    image_user.save("user_tmp.bmp");
    painter.end();
    painter.begin(&image_all);
    painter.drawImage(QRect(160-R-D,D*3,D,D),image_user);
    painter.end();


    //all
    painter.begin(this);
    painter.drawImage(QRect(0,0,160,160),image_all,image_all.rect());

    if(op == 0) {
        op = 1;
        QBitmap bmp = QBitmap::fromImage(image_all,Qt::MonoOnly);
        bmp.save("screen.bmp");
        QImage image_all2("screen.bmp");
        qDebug()<<"depth:"<<image_all2.depth();
        QFile file_bits("bits.txt");
        file_bits.open(QIODevice::WriteOnly |QIODevice::Text | QIODevice::Truncate);
        QTextStream stream_bits(&file_bits);
        for(int y = 0; y<160; y++) {
            for(int x = 0; x < 160; x++) {
                stream_bits<<image_all2.pixelIndex(x, y);
            }
            stream_bits <<"\n";
        }
        file_bits.close();
        QFile file_buffer("frameBuffer.txt");
        file_buffer.open(QIODevice::WriteOnly |QIODevice::Text |QIODevice::Truncate);
        QTextStream stream_buffer(&file_buffer);
        for(int y = 0; y<160; y++) {
            for(int x = 0; x < 20; x++) {
                quint8 c = 0x00;
                for(int i = 0; i < 8; i++) {
                    c |= (image_all2.pixelIndex(x*8+i, y) << (7-i));
                }
               QString strbyte = QString::asprintf("0x%02x",c);
                stream_buffer<<strbyte<<",";
            }
            stream_buffer<<"\n";
        }
        file_buffer.close();

    }
}
