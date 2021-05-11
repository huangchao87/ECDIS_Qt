#ifndef MAPITEM_H
#define MAPITEM_H

#include <QGraphicsPixmapItem>

class MapItem: public QGraphicsPolygonItem
{
public:
    MapItem(QGraphicsItem *parent = 0);
    QVector<QPolygonF> Area;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath MyArea(int a);
};

#endif // MAPITEM_H
