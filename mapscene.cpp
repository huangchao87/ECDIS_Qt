#include "mapscene.h"
#include <QPainter>

MapScene::MapScene(QObject *parent): QGraphicsScene(parent)
{

MapItem *item=new MapItem;
    item->setPos(0,0);
addItem(item);
}
