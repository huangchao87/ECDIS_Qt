#include "mainwindow.h"
#include "s57reader.h"
#include "byteshelper.h"
#include "mapscene.h"
#include "mapview.h"
#include <QDebug>

#include <QLayout>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    onOpenGeoS57file();
    mapshow();
    //paint_test();
    //createWidgets();
    //setupLayout();

}

MainWindow::~MainWindow()
{
}

void MainWindow::onOpenGeoS57file(){

    S57Reader *txt1=new S57Reader();
    txt1->Open("E:\\python_gdal\\enc_qt\\enc\\data\\C1112310.000");
    txt1->Open("E:\\python_gdal\\enc_qt\\enc\\data\\C1112348.000");
    txt1->Open("E:\\python_gdal\\enc_qt\\enc\\data\\C1112349.000");
//    BytesHelper *file=new BytesHelper();
//    file->Load("E:\\python_gdal\\enc_qt\\enc\\data\\C1112310.000");
}

void MainWindow::createWidgets(){
    openGLWidget = new OpenGLWidget(this);
}

void MainWindow::setupLayout() {
    QWidget *centerWidget = new QWidget();
    this->setCentralWidget(centerWidget);

    QHBoxLayout *mainLayout = new QHBoxLayout(centerWidget);
    mainLayout->setSpacing(6);
    mainLayout->addWidget(openGLWidget);
    mainLayout->setContentsMargins(11, 11, 11, 11);
    mainLayout->setStretch(0, 0);
    mainLayout->setStretch(1, 3);
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing,true);
        painter.setPen(QPen(Qt::red,3,Qt::DashDotDotLine,Qt::RoundCap));
        painter.setBrush(QBrush(Qt::blue,Qt::SolidPattern));

        QPolygonF polygon;
         polygon << QPointF(-124.1 , 73.6121) << QPointF(-124.104 , 73.5931) << QPointF(-124.065 , 73.595) << QPointF(-124.033 , 73.5986);
         painter.drawPolygon(polygon, Qt::WindingFill);
}

void MainWindow::mapshow(){

    MapScene *mapscene=new MapScene(this);
    mapview=new QGraphicsView(mapscene);
    mapview->scale(1, -1);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(mapview);
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    mapview->scale(1/m_scale, 1/m_scale);
    if(event->delta() > 0){
        if(m_scale < 10){
            m_scale += 0.2;
        }else{
            m_scale = 10;
        }
    }else{
        if(m_scale > 0.2){
            m_scale -= 0.2;
        }else{
            m_scale = 0.2;
        }
    }
    mapview->scale(m_scale, m_scale);
    qDebug()<<m_scale;
}
