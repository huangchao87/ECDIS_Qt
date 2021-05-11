#include "byteshelper.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

BytesHelper::BytesHelper()
{

}

void BytesHelper::Load(QString filePath){
    QFile file(filePath);
   bool isOk=file.open(QIODevice::ReadOnly);
    if (!isOk) {
                qDebug()<<"ERROR","file open failed";
                return;
            }

    ENCBytes = file.readAll();
    file.close();
        qDebug()<<ENCBytes;
}
