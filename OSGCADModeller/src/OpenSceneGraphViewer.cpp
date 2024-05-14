#include "stdafx.h"
#include "OpenSceneGraphViewer.h"
#include "Visualizer.h"
#include <QPaintEvent>
#include <QPainter>
#include <QOpenGLWidget>
#include <osg/ShapeDrawable>
#include <osgDB/ReadFile>
#include <osgUtil/LineSegmentIntersector>
#include <osg/Material>
#include <osgGA/GUIEventHandler>

OpenSceneGraphViewer::OpenSceneGraphViewer(QWidget* parent)
    : QOpenGLWidget(parent),
    mOsgGraphicsViewer(new osgViewer::GraphicsWindowEmbedded(this->x(), this->y(), this->width(), this->height())),
    mViewer(new osgViewer::Viewer)
{
    if (QGuiApplication::primaryScreen())
    {

        m_scale = QGuiApplication::primaryScreen()->devicePixelRatio();

    }
    else {

        qDebug() << "Primary screen not found.";

        m_scale = 1.0;

    }
    // Configure camera for projection
    osg::Camera* camera = new osg::Camera;
    camera->setViewport(0, 0, this->width(), this->height());
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

    mLayout = new QVBoxLayout;
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
    int newWidth = width * m_scale;
    int newHeight = height * m_scale;
    this->getEventQueue()->windowResize(this->x() * m_scale, this->y() * m_scale, width * m_scale, height * m_scale);
    mOsgGraphicsViewer->resized(this->x() * m_scale, this->y() * m_scale, width * m_scale, height * m_scale);
    osg::Camera* camera = mViewer->getCamera();
    camera->setViewport(1, 1, newWidth, newHeight);
}

void OpenSceneGraphViewer::setViewButtonClicked(bool clicked)
{
    mViewButtonClicked = clicked;
}

void OpenSceneGraphViewer::mouseMoveEvent(QMouseEvent* event)
{
    if (mViewButtonClicked)
    {
        this->getEventQueue()->mouseMotion(event->x() * m_scale, event->y() * m_scale);
    }
}

void OpenSceneGraphViewer::mousePressEvent(QMouseEvent* event)
{
    if (mViewButtonClicked)
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
        this->getEventQueue()->mouseButtonPress(event->x() * m_scale, event->y() * m_scale, button);


    }
}

void OpenSceneGraphViewer::mouseReleaseEvent(QMouseEvent* event)
{
    if (mViewButtonClicked)
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
        this->getEventQueue()->mouseButtonRelease(event->x() * m_scale, event->y() * m_scale, button);
    }

}

void OpenSceneGraphViewer::wheelEvent(QWheelEvent* event)
{
    qreal delta = event->angleDelta().y() / 120.0; // Normalize delta
    osgGA::GUIEventAdapter::ScrollingMotion motion = (delta > 0) ?
        osgGA::GUIEventAdapter::SCROLL_DOWN : osgGA::GUIEventAdapter::SCROLL_UP;
    delta = std::abs(delta);
    this->getEventQueue()->mouseScroll(motion, delta);
}

bool OpenSceneGraphViewer::event(QEvent* event)
{
    bool handled = QOpenGLWidget::event(event);
    this->update();
    return handled;
}

osgGA::EventQueue* OpenSceneGraphViewer::getEventQueue() const
{
    osgGA::EventQueue* eventQueue = mViewer->getEventQueue();
    return eventQueue;
}

void OpenSceneGraphViewer::addDrawable(osg::Node* node)
{
    mViewer->setSceneData(node);
}

void OpenSceneGraphViewer::clearDrawables()
{
    osg::ref_ptr<osg::Group> root = new osg::Group;
    mViewer->setSceneData(root);
}

osg::Node* OpenSceneGraphViewer::getSceneData() const
{
    return mViewer->getSceneData();
}

void OpenSceneGraphViewer::updateSceneData(osg::Node* newSceneData)
{
    // Set the new scene data
    mViewer->setSceneData(newSceneData);
}

osg::Node* OpenSceneGraphViewer::getSceneGraph() const
{
    return mSceneGraph.get();
}

void OpenSceneGraphViewer::addPlaneTextLabel(QLabel* label)
{
    QLayout* viewerLayout = layout(); // Assuming mLayout is the layout of OSG viewer
    if (viewerLayout) {
        viewerLayout->addWidget(label);
        viewerLayout->setAlignment(label, Qt::AlignRight | Qt::AlignTop);
    }
    else {
        QWidget* centralWidget = findChild<QWidget*>(); // Assuming there's only one central widget
        if (centralWidget && centralWidget->layout()) {
            QLayout* centralLayout = centralWidget->layout();
            centralLayout->addWidget(label);
            centralLayout->setAlignment(label, Qt::AlignRight | Qt::AlignTop);
        }
        else {
            QWidget::setLayout(new QVBoxLayout); // Create a layout for the viewer
            viewerLayout = layout();
            viewerLayout->addWidget(label);
            viewerLayout->setAlignment(label, Qt::AlignRight | Qt::AlignTop);
        }
    }
}

