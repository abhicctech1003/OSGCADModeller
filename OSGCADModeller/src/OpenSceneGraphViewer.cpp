#include "stdafx.h"
#include "OpenSceneGraphViewer.h"
#include <QPaintEvent>
#include <QPainter>
#include <QOpenGLWidget>
#include <osg/ShapeDrawable>
#include <osgDB/ReadFile>

OpenSceneGraphViewer::OpenSceneGraphViewer(qreal scaleX, qreal scaleY, QWidget* parent)
    : QOpenGLWidget(parent), 
    mOsgGraphicsViewer(new osgViewer::GraphicsWindowEmbedded(this->x(), this->y(), this->width(), this->height())),
    mViewer(new osgViewer::Viewer),
    m_scaleX(scaleX), m_scaleY(scaleY)
{
    // Configure camera for projection
    osg::Camera* camera = new osg::Camera;
    camera->setClearColor(osg::Vec4(0.8f, 0.8f, 0.8f, 1.0f));
    float aspectRatio = static_cast<float>(this->width()) / static_cast<float>(this->height());
    camera->setProjectionMatrixAsPerspective(30.0f, aspectRatio, 1.f, 1000.f); // Adjust near and far planes
    camera->setGraphicsContext(mOsgGraphicsViewer);

    mViewer->setCamera(camera);

    // Configure viewer created
    osgGA::TrackballManipulator* manipulator = new osgGA::TrackballManipulator;
    manipulator->setAllowThrow(false);
    this->setMouseTracking(true);
    mViewer->setCameraManipulator(manipulator);
    mViewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);
    mViewer->realize();

    // Create geode to hold primitives
    mGeode = new osg::Geode;
    mViewer->setSceneData(mGeode);
}

OpenSceneGraphViewer::~OpenSceneGraphViewer()
{

}

void OpenSceneGraphViewer::paintGL()
{
    mViewer->frame();
}

void OpenSceneGraphViewer::resizeGL(int width, int height)
{
    int newWidth = width * m_scaleX;
    int newHeight = height * m_scaleY;
    this->getEventQueue()->windowResize(this->x() * m_scaleX, this->y() * m_scaleY, width * m_scaleX, height * m_scaleY);
    mOsgGraphicsViewer->resized(this->x() * m_scaleX, this->y() * m_scaleY, width * m_scaleX, height * m_scaleY);
    osg::Camera* camera = mViewer->getCamera();
    camera->setViewport(0, 0, newWidth, newHeight);
}

void OpenSceneGraphViewer::mouseMoveEvent(QMouseEvent* event)
{
    this->getEventQueue()->mouseMotion(event->x() * m_scaleX, event->y() * m_scaleY);
}

void OpenSceneGraphViewer::mousePressEvent(QMouseEvent* event)
{
    unsigned int button = 0;
    switch (event->button()) {
    case Qt::LeftButton:
        button = 1;
        break;
    case Qt::MiddleButton:
        button = 2;
        break;
    case Qt::RightButton:
        button = 3;
        break;
    default:
        break;
    }
    this->getEventQueue()->mouseButtonPress(event->x() * m_scaleX, event->y() * m_scaleY, button);
}

void OpenSceneGraphViewer::mouseReleaseEvent(QMouseEvent* event)
{
    unsigned int button = 0;
    switch (event->button()) {
    case Qt::LeftButton:
        button = 1;
        break;
    case Qt::MiddleButton:
        button = 2;
        break;
    case Qt::RightButton:
        button = 3;
        break;
    default:
        break;
    }
    this->getEventQueue()->mouseButtonRelease(event->x() * m_scaleX, event->y() * m_scaleY, button);
}

bool OpenSceneGraphViewer::event(QEvent* event)
{
    bool handled = QOpenGLWidget::event(event);
    this->update();
    return handled;
}

osgGA::EventQueue* OpenSceneGraphViewer::getEventQueue() const
{
    osgGA::EventQueue* eventQueue = mOsgGraphicsViewer->getEventQueue();
    return eventQueue;
}

void OpenSceneGraphViewer::addDrawable(osg::Drawable* drawable)
{
    mGeode->addDrawable(drawable);
}
