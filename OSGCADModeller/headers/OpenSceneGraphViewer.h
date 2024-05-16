#pragma once

#include "ui_OSGCADModeller.h"
#include <QtWidgets/QWidget>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <QOpenGLWidget>

class OpenSceneGraphViewer : public QOpenGLWidget
{
    Q_OBJECT

public:
    OpenSceneGraphViewer(QWidget* parent = 0);
    ~OpenSceneGraphViewer();

    //void addDrawable(osg::Drawable* drawable);
    void setViewButtonClicked(bool clicked);
    void addDrawable(osg::Node* node);
    void clearDrawables();
    osg::Node* getSceneData() const;
    void updateSceneData(osg::Node* newSceneData);
    osg::Node* getSceneGraph() const;
    void addPlaneTextLabel(QLabel* label);

protected:
    void paintGL();
    void resizeGL(int width, int height);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    virtual void wheelEvent(QWheelEvent* event) override;
    bool event(QEvent* event);
    osgGA::EventQueue* getEventQueue() const;

private:

    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> mOsgGraphicsViewer;
    osg::ref_ptr<osgViewer::Viewer> mViewer;
    osg::ref_ptr<osg::Geode> mGeode;
    qreal m_scale;
    bool mViewButtonClicked = false;
    osg::ref_ptr<osg::Node> mSceneGraph;
    QVBoxLayout* mLayout; // Add this line for the layout
};
