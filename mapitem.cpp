#include "mapitem.h"
#include <QPainter>
#include "s57reader.h"
#include <QVector>
#include <QDebug>
extern QVector<QPolygonF> AreaTest;
MapItem::MapItem(QGraphicsItem *parent): QGraphicsPolygonItem(parent)
{
}


void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    Q_UNUSED(option)
//    Q_UNUSED(widget)


    painter->setRenderHint(QPainter::Antialiasing,true);
    //painter->setPen(QPen(Qt::red,3,Qt::DashDotDotLine,Qt::RoundCap));
    //painter->setBrush(QBrush(Qt::gray,Qt::SolidPattern));
//painter->setPen(QPen(Qt::black,1,Qt::SolidLine,Qt::RoundCap));
    painter->setPen(Qt::NoPen);
painter->setBrush(QBrush(QColor(167,167,167,100),Qt::SolidPattern));


    QVector<QPolygonF> Area=S57Reader::AreaTest;

qDebug() <<"GetFeatureCount=="<<Area.size();
    for (int i = 0; i < Area.size();i++)
    {
        QPainterPath myPath;
    myPath.addPolygon(Area.at(i));
    painter->drawPath(myPath);
    }



//QPainterPath myPath;
//myPath=MyArea(1);
//    painter->drawPath(myPath);
//    myPath=MyArea(0);
//        painter->drawPath(myPath);




//QPolygonF polygon1;
//     polygon1 << QPointF(0, 0) << QPointF(20 , 20) << QPointF(25 , -5) << QPointF(0 , 0);
//     painter->drawPolygon(polygon1, Qt::WindingFill);

}


QPainterPath MapItem::MyArea(int a){
    QPolygonF polygon;
    QPainterPath path;
    if(a==0){
        polygon << QPointF(-124.1 , 73.6121) << QPointF(-130 , 70) << QPointF(-110 , 70) << QPointF(-124.033 , 73.5986);
        path.addPolygon(polygon);
    }else if(a==1){
        polygon << QPointF(0, 0) << QPointF(20 , 20) << QPointF(25 , -5) << QPointF(0 , 0);
        path.addPolygon(polygon);
    }
    return path;
}
