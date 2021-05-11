#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OpenGLWidget:public QOpenGLWidget,protected QOpenGLFunctions
{
public:
    explicit OpenGLWidget(QWidget* parent = nullptr);
    ~OpenGLWidget();
protected:
    /* override */
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;
private:
    bool isRunning = true;
};

#endif // OPENGLWIDGET_H
