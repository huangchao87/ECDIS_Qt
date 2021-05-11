#ifndef BYTESHELPER_H
#define BYTESHELPER_H
#include <QString>

class BytesHelper
{
public:
    QByteArray ENCBytes;
    int Position = 0;
    BytesHelper();
    void Load(QString filePath);
};

#endif // BYTESHELPER_H
