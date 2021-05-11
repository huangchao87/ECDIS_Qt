#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent /*= 0*/): QOpenGLWidget(parent)
{
    this->setMouseTracking(true);
    this->setFocusPolicy(Qt::ClickFocus);
}

OpenGLWidget::~OpenGLWidget()
{
    // very important
    makeCurrent();
    isRunning = false;
}

void OpenGLWidget::initializeGL(){
    // Set up the rendering context, load shaders and other resources, etc.:
            initializeOpenGLFunctions();
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void OpenGLWidget::resizeGL(int w, int h){

}

void OpenGLWidget::paintGL(){

}
