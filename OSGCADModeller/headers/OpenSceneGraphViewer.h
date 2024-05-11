#pragma once

#include <QtWidgets/QWidget>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <QOpenGLWidget>
#include "ui_OSGCADModeller.h"

class OpenSceneGraphViewer : public QOpenGLWidget
{
    Q_OBJECT

public:
    OpenSceneGraphViewer(qreal scaleX, qreal scaleY, QWidget* parent = 0);
    ~OpenSceneGraphViewer();

    void addDrawable(osg::Drawable* drawable);

protected:
    void paintGL();
    void resizeGL(int width, int height);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    bool event(QEvent* event);
    

private:
    osgGA::EventQueue* getEventQueue() const;

    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> mOsgGraphicsViewer;
    osg::ref_ptr<osgViewer::Viewer> mViewer;
    osg::ref_ptr<osg::Geode> mGeode;
    qreal m_scaleX;
    qreal m_scaleY;
};
