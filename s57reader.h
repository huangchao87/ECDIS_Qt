#ifndef S57READER_H
#define S57READER_H

#include <QVector>
#include <QPolygonF>

class S57Reader
{
public:
    S57Reader();
    ~S57Reader();
    void Open(QString S57file);
   static QVector<QPolygonF> AreaTest;
};

#endif // S57READER_H
