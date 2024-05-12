#include "stdafx.h"
#include "Visualizer.h"
#include "OpenSceneGraphViewer.h"
#include "Primitives.h"
#include "OsgFileWriter.h"
#include <osg/MatrixTransform>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/ReaderWriter>
#include <osgDB/WriteFile>
#include <osg/ShapeDrawable>
#include <osgDB/ReadFile>

Visualizer::Visualizer(QWidget* parent) : QMainWindow(parent)
{
    setupUi();
    // Initially disable the additional buttons
    setPlaneButtonsEnabled(false);
    setSaveAndClearButtonsEnabled(false);
    setPrimitivesButtonsEnabled(false);
}

Visualizer::~Visualizer()
{}

void Visualizer::setupUi()
{
    mWindow.resize(600, 600);
    mainLayout = new QVBoxLayout;
    mOsgViewer = new OpenSceneGraphViewer(&mWindow);

    // Create toggle buttons
    mSketchButton = createButton("Sketch", Qt::white);
    mViewButton = createButton("View", Qt::white);
    mXYButton = createButton("XY", Qt::yellow);
    mYZButton = createButton("YZ", Qt::yellow);
    mXZButton = createButton("XZ", Qt::yellow);

    // Create additional buttons
    mPointButton = createButton("Point", QColor(135, 206, 235)); // Sky blue
    mLineButton = createButton("Line", QColor(135, 206, 235)); // Sky blue
    mCircleButton = createButton("Circle", QColor(135, 206, 235)); // Sky blue
    mEllipseButton = createButton("Ellipse", QColor(135, 206, 235)); // Sky blue
    mArcButton = createButton("Arc", QColor(135, 206, 235)); // Sky blue
    mSaveButton = createButton("Save", Qt::green);
    mClearButton = createButton("Clear", Qt::red);

    // Set size policies to make buttons square-shaped
    setSquareButton(mSketchButton);
    setSquareButton(mViewButton);
    setSquareButton(mXYButton);
    setSquareButton(mYZButton);
    setSquareButton(mXZButton);
    setSquareButton(mPointButton);
    setSquareButton(mLineButton);
    setSquareButton(mCircleButton);
    setSquareButton(mEllipseButton);
    setSquareButton(mArcButton);
    setSquareButton(mSaveButton);
    setSquareButton(mClearButton);

    // Connect toggle buttons to slots
    connect(mSketchButton, &QPushButton::clicked, this, &Visualizer::onSketchButtonClicked);
    connect(mViewButton, &QPushButton::clicked, this, &Visualizer::onViewButtonClicked);
    connect(mXYButton, &QPushButton::clicked, this, &Visualizer::onXYButtonClicked);
    connect(mYZButton, &QPushButton::clicked, this, &Visualizer::onYZButtonClicked);
    connect(mXZButton, &QPushButton::clicked, this, &Visualizer::onXZButtonClicked);

    // Connect additional buttons to slots
    connect(mPointButton, &QPushButton::clicked, this, &Visualizer::onPointButtonClicked);
    connect(mLineButton, &QPushButton::clicked, this, &Visualizer::onLineButtonClicked);
    connect(mCircleButton, &QPushButton::clicked, this, &Visualizer::onCircleButtonClicked);
    connect(mEllipseButton, &QPushButton::clicked, this, &Visualizer::onEllipseButtonClicked);
    connect(mArcButton, &QPushButton::clicked, this, &Visualizer::onArcButtonClicked);
    connect(mSaveButton, &QPushButton::clicked, this, &Visualizer::onSaveButtonClicked);
    connect(mClearButton, &QPushButton::clicked, this, &Visualizer::onClearButtonClicked);

    // Create layout
    mGridLayout = new QGridLayout(this);

    // Add buttons to layout
    mGridLayout->addWidget(mSketchButton, 0, 0);
    mGridLayout->addWidget(mViewButton, 0, 1);
    mGridLayout->addWidget(mXYButton, 0, 2);
    mGridLayout->addWidget(mYZButton, 0, 3);
    mGridLayout->addWidget(mXZButton, 0, 4);
    mGridLayout->addWidget(mPointButton, 0, 5);
    mGridLayout->addWidget(mLineButton, 0, 6);
    mGridLayout->addWidget(mCircleButton, 0, 7);
    mGridLayout->addWidget(mEllipseButton, 0, 8);
    mGridLayout->addWidget(mArcButton, 0, 9);
    mGridLayout->addWidget(mSaveButton, 0, 10);
    mGridLayout->addWidget(mClearButton, 0, 11);

    mainLayout->addLayout(mGridLayout);
    mainLayout->addWidget(mOsgViewer);

    mWidget = new QWidget(this);
    mWidget->setLayout(mainLayout);
    mWindow.setCentralWidget(mWidget);

    mWindow.show();

    mWindow.setWindowTitle(QCoreApplication::translate("Visualiser", "Visualiser", nullptr));
}

QPushButton* Visualizer::createButton(const QString& text, const QColor& color)
{
    QPushButton* button = new QPushButton(text, this);
    setButtonColor(button, color);
    QFont font = button->font();
    font.setPointSize(12); // Adjust the font size as needed
    button->setFont(font);
    return button;
}

void Visualizer::onSketchButtonClicked()
{
    setPlaneButtonsEnabled(true);
    setSaveAndClearButtonsEnabled(true);
    setPrimitivesButtonsEnabled(false);

    mOsgViewer->setViewButtonClicked(false);
}

void Visualizer::onViewButtonClicked()
{
    setPlaneButtonsEnabled(false);
    setSaveAndClearButtonsEnabled(true);
    setPrimitivesButtonsEnabled(false);

    // Set mViewButtonClicked to true
    mOsgViewer->setViewButtonClicked(true);
}

void Visualizer::onXYButtonClicked()
{
    setSaveAndClearButtonsEnabled(true);
    // Implementation for XY button click
    setPrimitivesButtonsEnabled(true);
    setPlaneToXY();
}

void Visualizer::onYZButtonClicked()
{
    setSaveAndClearButtonsEnabled(true);
    // Implementation for YZ button click
    setPrimitivesButtonsEnabled(true);
    setYZPlaneToXY();
}

void Visualizer::onXZButtonClicked()
{
    setSaveAndClearButtonsEnabled(true);
    // Implementation for XZ button click
    setPrimitivesButtonsEnabled(true);
    setXZPlaneToXY();
}

void Visualizer::onPointButtonClicked()
{
    osg::Geode* pointGeode = Primitives::createPoint(osg::Vec3(2.0f, 1.0f, 0.0f));
    mOsgViewer->addDrawable(pointGeode);
    mOsgViewer->update();
}

void Visualizer::onLineButtonClicked()
{
    osg::Geode* lineGeode = Primitives::createLine(osg::Vec3(-1.0f, 0.0f, 0.0f), osg::Vec3(1.0f, 0.0f, 0.0f));
    mOsgViewer->addDrawable(lineGeode);
    mOsgViewer->update();
}

void Visualizer::onCircleButtonClicked()
{
    osg::Geode* circleGeode = Primitives::createCircle(0.05f, 36);
    mOsgViewer->addDrawable(circleGeode);
    mOsgViewer->update();
}

void Visualizer::onEllipseButtonClicked()
{
    osg::Geode* ellipseGeode = Primitives::createEllipse(0.1f, 0.05, 36);
    mOsgViewer->addDrawable(ellipseGeode);
    mOsgViewer->update();
}

void Visualizer::onArcButtonClicked()
{
    osg::Geode* arcGeode = Primitives::createArc(45.0f, 1.0f, osg::PI / 4.0f, 3.0f * osg::PI / 4.0f, 36);
    mOsgViewer->addDrawable(arcGeode);
    mOsgViewer->update();

}

void Visualizer::onSaveButtonClicked()
{
    osg::ref_ptr<osg::Group> sceneGroup = mOsgViewer->getSceneData()->asGroup();
    if (!sceneGroup) {
        std::cerr << "Error: Scene data is not a group" << std::endl;
        return;
    }

    std::vector<osg::ref_ptr<osg::Geode>> geodes;

    for (unsigned int i = 0; i < sceneGroup->getNumChildren(); ++i) 
    {
        osg::ref_ptr<osg::Node> childNode = sceneGroup->getChild(i);
        osg::ref_ptr<osg::Geode> geode = childNode->asGeode();
        if (geode) 
        {
            geodes.push_back(geode);
        }
        else 
        {
            std::cerr << "Error: Child node " << i << " is not a geode" << std::endl;
        }
    }

    // Call createPrimitivesNode with the vector of geodes
    osg::Node* primitivesNode = createPrimitivesNode(geodes);

    // Render primitives
    renderPrimitiveFile(primitivesNode);
}

void Visualizer::onClearButtonClicked()
{
    mOsgViewer->clearDrawables(); // Remove all primitives
}

void Visualizer::setPlaneButtonsEnabled(bool enabled)
{
    mXYButton->setEnabled(enabled);
    mYZButton->setEnabled(enabled);
    mXZButton->setEnabled(enabled);
}

void Visualizer::setSaveAndClearButtonsEnabled(bool enabled)
{
    mSaveButton->setEnabled(enabled);
    mClearButton->setEnabled(enabled);
}

void Visualizer::setPrimitivesButtonsEnabled(bool enabled)
{
    mPointButton->setEnabled(enabled);
    mLineButton->setEnabled(enabled);
    mCircleButton->setEnabled(enabled);
    mEllipseButton->setEnabled(enabled);
    mArcButton->setEnabled(enabled);
}

void Visualizer::setButtonColor(QPushButton* button, const QColor& color)
{
    button->setStyleSheet("background-color: " + color.name() + ";");
}

void Visualizer::setSquareButton(QPushButton* button)
{
    button->setFixedSize(100, 60); // Set size to create square shape
}

void Visualizer::setPlaneToXY()
{
    // Apply the rotation to the children of the original scene data
    osg::Node* originalSceneData = mOsgViewer->getSceneData();
    osg::ref_ptr<osg::MatrixTransform> rotationTransform = new osg::MatrixTransform;
    osg::Matrix rotationMatrix;

    if (mYZPlaneEnabled == true)
    {
        rotationMatrix.makeRotate(osg::DegreesToRadians(90.0), osg::Vec3(1.0, 0.0, 0.0));
    }
    else if (mXZPlaneEnabled == true)
    {
        rotationMatrix.makeRotate(osg::DegreesToRadians(-90.0), osg::Vec3(0.0, 1.0, 0.0));
    }

    rotationTransform->setMatrix(rotationMatrix);
    rotationTransform->addChild(originalSceneData);

    // Create a new scene data with the rotated plane
    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild(rotationTransform);

    // Update the scene data in the viewer
    mOsgViewer->updateSceneData(root);
}

void Visualizer::setYZPlaneToXY()
{
    // Apply the rotation to the children of the original scene data
    osg::Node* originalSceneData = mOsgViewer->getSceneData();
    osg::ref_ptr<osg::MatrixTransform> rotationTransform = new osg::MatrixTransform;
    osg::Matrix rotationMatrix;
    rotationMatrix.makeRotate(osg::DegreesToRadians(90.0), osg::Vec3(1.0, 0.0, 0.0)); // Rotate 90 degrees around X axis
    rotationTransform->setMatrix(rotationMatrix);
    rotationTransform->addChild(originalSceneData);

    // Create a new scene data with the rotated plane
    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild(rotationTransform);

    // Update the scene data in the viewer
    mOsgViewer->updateSceneData(root);

    mYZPlaneEnabled = true;
}

void Visualizer::setXZPlaneToXY()
{
    // Apply the rotation to the children of the original scene data
    osg::Node* originalSceneData = mOsgViewer->getSceneData();
    osg::ref_ptr<osg::MatrixTransform> rotationTransform = new osg::MatrixTransform;
    osg::Matrix rotationMatrix;
    rotationMatrix.makeRotate(osg::DegreesToRadians(-90.0), osg::Vec3(0.0, 1.0, 0.0)); // Rotate -90 degrees around Y axis
    rotationTransform->setMatrix(rotationMatrix);
    rotationTransform->addChild(originalSceneData);

    // Create a new scene data with the rotated plane
    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild(rotationTransform);

    // Update the scene data in the viewer
    mOsgViewer->updateSceneData(root);

    mXZPlaneEnabled = true;
}

osg::Node* Visualizer::createPrimitivesNode(const std::vector<osg::ref_ptr<osg::Geode>>& geodes)
{
    osg::ref_ptr<osg::Group> root = new osg::Group;

    // Create a Geode to hold the primitives
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;

    // Add existing primitives to the geode
    for (const auto& g : geodes) {
        if (g.valid())
            geode->addChild(g);
    }

    root->addChild(geode);

    // Return the root node containing all the primitives
    return root.release();
}

void Visualizer::renderPrimitiveFile(osg::Node* primitivesNode)
{
    osg::ref_ptr<osgDB::ReaderWriter::Options> options = new osgDB::ReaderWriter::Options;
    options->setOptionString("noBinary");
    // Write the node to an .osg file
    bool success = osgDB::writeNodeFile(*primitivesNode, "Primitives.osg", options.get());
    if (success) 
    {
        std::cout << "Primitives saved to Primitives.osg" << std::endl;
    }
    else 
    {
        std::cerr << "Failed to save primitives" << std::endl;
    }
}

