#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "openglwidget.h"
#include <QPainter>
#include <QGraphicsView>
#include <QWheelEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    qreal m_scale = 1;
QGraphicsView *mapview;
    QWidget paint_widget;
void wheelEvent(QWheelEvent *event);
    void mapshow();
    void paintEvent(QPaintEvent *);
    void createWidgets();
    void setupLayout();
    void onOpenGeoS57file();

private:
    Ui::MainWindow *ui;
    OpenGLWidget* openGLWidget;
};
#endif // MAINWINDOW_H
