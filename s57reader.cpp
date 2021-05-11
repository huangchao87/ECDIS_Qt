#include "s57reader.h"
#include "QDebug"
#include "QString"
#include <vector>
#include "ogrsf_frmts.h"
#include <iostream>
#include <math.h>

using namespace std;
QVector<QPolygonF> S57Reader::AreaTest;
S57Reader::S57Reader()
{
    GDALAllRegister();//注册所有的驱动
}



void S57Reader::Open(QString filepath){
    QByteArray bytes = filepath.toLocal8Bit();
    const char* path = bytes.data();
    GDALDataset* poDS;
  // GDALAllRegister();
    poDS = (GDALDataset*) GDALOpenEx( path, GDAL_OF_READONLY, NULL, NULL, NULL );
    if( poDS == NULL )
    {
        printf( "Open failed.\n" );
        exit( 1 );
    }
 qDebug() <<"GetLayerCount=="<< poDS->GetLayerCount();
    QVector<QString> LayerName;
    for(int i=0;i<poDS->GetLayerCount();i++){
        LayerName.append(poDS->GetLayer(i)->GetName());
    }

    qDebug() <<"LayerName=="<< LayerName;


    OGRLayer  *poLayer=poDS->GetLayer(3);

    OGRFeature *poFeature;
    poLayer->ResetReading();
    qDebug() <<"GetFeatureCount=="<<poLayer->GetFeatureCount();
    while( (poFeature = poLayer->GetNextFeature()) != NULL )
    {
        OGRFeatureDefn *poFDefn = poLayer->GetLayerDefn();
//        for( int iField = 0; iField < poFDefn->GetFieldCount(); iField++ )
//        {
//            OGRFieldDefn *poFieldDefn = poFDefn->GetFieldDefn( iField );
//qDebug() <<"GetType=="<<poFieldDefn->GetType();

//   qDebug() <<"GetNameRef=="<<poFieldDefn->GetNameRef();
//qDebug() <<"GetNameRef=="<<poFeature->GetFieldAsString(iField);
//            switch( poFieldDefn->GetType() )
//            {
//                case OFTInteger:
//                    printf( "%d,", poFeature->GetFieldAsInteger( iField ) );
//                    break;
//                case OFTInteger64:
//                    printf( CPL_FRMT_GIB ",", poFeature->GetFieldAsInteger64( iField ) );
//                    break;
//                case OFTReal:
//                    printf( "%.3f,", poFeature->GetFieldAsDouble(iField) );
//                    break;
//                case OFTString:
//                    printf( "%s,", poFeature->GetFieldAsString(iField) );
//                    break;
//                default:
//                    printf( "%s,", poFeature->GetFieldAsString(iField) );
//                    break;
//            }
//        }

        //qDebug() <<"duandiann=="<<;
        OGRGeometry *poGeometry;
if(poFeature->GetFieldAsString(3)==QString::fromLocal8Bit("71")){
        poGeometry = poFeature->GetGeometryRef();
        if( poGeometry != NULL && wkbFlatten(poGeometry->getGeometryType()) == wkbPolygon )
        {
        #if GDAL_VERSION_NUM >= GDAL_COMPUTE_VERSION(2,3,0)
            OGRPolygon *poPolygon = poGeometry->toPolygon();
        #else
            OGRPolygon *poPolygon = (OGRPolygon *) poGeometry;
        #endif

            //printf( "%.3f\n", poPolygon->clone() );
            //qDebug() <<"poPolygon=="<<poPolygon->clone();
            OGRLinearRing* boundary=poPolygon->getExteriorRing();
            int pointcount = boundary->getNumPoints();
            QPolygonF singleArea;
            for (int i = 0; i < pointcount; i++)

            {
                double gx = boundary->getX(i);
                double gy = boundary->getY(i);
                //qDebug() <<"point=="<<gx<<","<<gy;
                //huangchao   tianjiadao vector<qpolygonf>zhongshi qpolygonf QPointF

            singleArea<<QPointF(gx,gy);

            }
            AreaTest.append(singleArea);
            //OGRLinearRing * poLR=pPolygon->getExteriorRing();
        }
        else
        {
            printf( "no point geometry\n" );
        }



    }


    }

    //zhushicankao
//    qDebug() << poDS->GetLayerCount();

//    for(int i=0;i<poDS->GetLayerCount();i++){
//    OGRLayer  *poLayer = poDS->GetLayer(i); //读取层
//    OGRFeatureDefn *poFDefn = poLayer->GetLayerDefn();

//            OGRFeature *poFeature;
//            while ((poFeature = poLayer->GetNextFeature()) != NULL)
//            {
//                            OGRFeatureDefn *poFDefn = poLayer->GetLayerDefn();
//                            int n = poFDefn->GetFieldCount(); //获得字段的数目，不包括前两个字段（FID,Shape);
//                            qDebug() << "My name is"<<n;
//                            for (int iField = 0; iField <n; iField++)
//                            {
//                                //输出每个字段的值
//                                cout << poFeature->GetFieldAsString(iField) << endl;
//                            }
//                            cout << "25555222"<<endl;

//                            OGRFeature::DestroyFeature(poFeature);
//            }
//          cout <<endl;

//    }






       GDALClose( poDS );
       poDS = nullptr;
//qDebug() << poFeature;
    qDebug() << "My name is ";
}




/*import math
#经纬度转墨卡托坐标
def ls(lat,lng):
    # list=ll_wl.split(',')
    lat=float(lat)
    lng=float(lng)
    x =  lng* 20037508.34 / 180
    y = math.log(math.tan((90 + lat) * math.pi / 360)) / (math.pi / 180)
    y = y * 20037508.34 / 180
    print str(x),str(y)
#墨卡托坐标转经纬度坐标
def ll(x,y):
    x=float(x)
    y=float(y)
    x=x/20037508.34*180
    y=y/20037508.34*180
    y=180/math.pi*(2*math.atan(math.exp(y*math.pi/180))-math.pi/2)
    print x,y
if __name__ == '__main__':
    ls('30.697218','104.073694')
    ll('12985924.36','4789962.05')
*/
