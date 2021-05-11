#ifndef MAPSCENE_H
#define MAPSCENE_H

#include "mapitem.h"
#include <QGraphicsScene>
#include <QMenu>

class MapScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MapScene(QObject *parent = 0);
};

#endif // MAPSCENE_H
