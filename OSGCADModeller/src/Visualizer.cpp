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
    setSaveAndDeleteButtonsEnabled(false);
    setPrimitivesButtonsEnabled(false);
}

Visualizer::~Visualizer()
{}

void Visualizer::setupUi()
{
    mWindow.resize(600, 600);
    mainLayout = new QVBoxLayout;
    mOsgViewer = new OpenSceneGraphViewer(&mWindow);

    // Create a splitter to hold the viewer and the primitive list
    QSplitter* splitter = new QSplitter(Qt::Horizontal);
    QVBoxLayout* rightLayout = new QVBoxLayout;

    // Create toggle buttons
    mSketchButton = createToolButton("Sketch", Qt::white);
    mViewButton = createToolButton("View", Qt::white);
    mXYButton = createToolButton("XY", Qt::yellow);
    mYZButton = createToolButton("YZ", Qt::yellow);
    mXZButton = createToolButton("XZ", Qt::yellow);

    // Set checkable property for Sketch and View buttons
    mSketchButton->setCheckable(true);
    mViewButton->setCheckable(true);
    mXYButton->setCheckable(true);
    mYZButton->setCheckable(true);
    mXZButton->setCheckable(true);

    // Create button group for Sketch and View buttons
    QButtonGroup* toggleGroup = new QButtonGroup(this);
    toggleGroup->setExclusive(true);
    toggleGroup->addButton(mSketchButton);
    toggleGroup->addButton(mViewButton);

    // Create button group for Sketch and View buttons
    QButtonGroup* toggleGroup1 = new QButtonGroup(this);
    toggleGroup1->setExclusive(true);
    toggleGroup1->addButton(mXYButton);
    toggleGroup1->addButton(mYZButton);
    toggleGroup1->addButton(mXZButton);

    // Create additional buttons
    mPointButton = createButton("Point", QColor(135, 206, 235)); // Sky blue
    mLineButton = createButton("Line", QColor(135, 206, 235)); // Sky blue
    mCircleButton = createButton("Circle", QColor(135, 206, 235)); // Sky blue
    mEllipseButton = createButton("Ellipse", QColor(135, 206, 235)); // Sky blue
    mArcButton = createButton("Arc", QColor(135, 206, 235)); // Sky blue
    mSaveButton = createButton("Save", Qt::green);
    mDeleteButton = createButton("Delete", Qt::red);

    // Set size policies to make buttons square-shaped
    setToolButtonSize(mSketchButton);
    setToolButtonSize(mViewButton);
    setToolButtonSize(mXYButton);
    setToolButtonSize(mYZButton);
    setToolButtonSize(mXZButton);

    setButtonSize(mPointButton);
    setButtonSize(mLineButton);
    setButtonSize(mCircleButton);
    setButtonSize(mEllipseButton);
    setButtonSize(mArcButton);
    setButtonSize(mSaveButton);
    setButtonSize(mDeleteButton);

    // Connect toggle buttons to slots
    connect(mSketchButton, &QToolButton::clicked, this, &Visualizer::onSketchButtonClicked);
    connect(mViewButton, &QToolButton::clicked, this, &Visualizer::onViewButtonClicked);
    connect(mXYButton, &QToolButton::clicked, this, &Visualizer::onXYButtonClicked);
    connect(mYZButton, &QToolButton::clicked, this, &Visualizer::onYZButtonClicked);
    connect(mXZButton, &QToolButton::clicked, this, &Visualizer::onXZButtonClicked);

    // Connect additional buttons to slots
    connect(mPointButton, &QPushButton::clicked, this, &Visualizer::onPointButtonClicked);
    connect(mLineButton, &QPushButton::clicked, this, &Visualizer::onLineButtonClicked);
    connect(mCircleButton, &QPushButton::clicked, this, &Visualizer::onCircleButtonClicked);
    connect(mEllipseButton, &QPushButton::clicked, this, &Visualizer::onEllipseButtonClicked);
    connect(mArcButton, &QPushButton::clicked, this, &Visualizer::onArcButtonClicked);
    connect(mSaveButton, &QPushButton::clicked, this, &Visualizer::onSaveButtonClicked);
    connect(mDeleteButton, &QPushButton::clicked, this, &Visualizer::onDeleteButtonClicked);

    // Create QLabel for displaying plane text
    mPlaneTextLabel = new QLabel(this);
    mPlaneTextLabel->setAlignment(Qt::AlignRight | Qt::AlignTop);
    QFont font = mPlaneTextLabel->font();
    font.setPointSize(10); // Adjust the font size as needed
    mPlaneTextLabel->setFont(font);
    mPlaneTextLabel->setText("");
    mOsgViewer->addPlaneTextLabel(mPlaneTextLabel);

    // To Add Layout
    mPrimitiveListWidget = new QListWidget(this);
    rightLayout->addWidget(mPrimitiveListWidget);
    QWidget* rightWidget = new QWidget;
    rightWidget->setLayout(rightLayout);

    // Create layout for spin boxes
    QVBoxLayout* spinBoxLayout = new QVBoxLayout;

    // Add all spin boxes to spin box layout
    mSpinBox1 = new QDoubleSpinBox(this);
    mSpinBox2 = new QDoubleSpinBox(this);
    mSpinBox3 = new QDoubleSpinBox(this);
    mSpinBox4 = new QDoubleSpinBox(this);
    mSpinBox5 = new QDoubleSpinBox(this);
    mSpinBox6 = new QDoubleSpinBox(this);
    mSpinBox7 = new QDoubleSpinBox(this);
    mSpinBox8 = new QDoubleSpinBox(this);
    mSpinBox9 = new QDoubleSpinBox(this);
    mSpinBox10 = new QDoubleSpinBox(this);
    mSpinBox11 = new QDoubleSpinBox(this);

    // Set names for the spin boxes
    mSpinBox1->setObjectName("SpinBox1");
    mSpinBox2->setObjectName("SpinBox2");
    mSpinBox3->setObjectName("SpinBox3");
    mSpinBox4->setObjectName("SpinBox4");
    mSpinBox5->setObjectName("SpinBox5");
    mSpinBox6->setObjectName("SpinBox6");
    mSpinBox7->setObjectName("SpinBox7");
    mSpinBox8->setObjectName("SpinBox8");
    mSpinBox9->setObjectName("SpinBox9");
    mSpinBox10->setObjectName("SpinBox10");
    mSpinBox11->setObjectName("SpinBox10");

    // Initially hide all spin boxes
    mSpinBox1->hide();
    mSpinBox2->hide();
    mSpinBox3->hide();
    mSpinBox4->hide();
    mSpinBox5->hide();
    mSpinBox6->hide();
    mSpinBox7->hide();
    mSpinBox8->hide();
    mSpinBox9->hide();
    mSpinBox10->hide();
    mSpinBox11->hide();

    // Additional spin boxes for line start and end points
    mSpinBox1->setValue(Primitives::defaultLineStart.x()); // Default line start point X
    mSpinBox2->setValue(Primitives::defaultLineStart.y()); // Default line start point Y
    mSpinBox3->setValue(Primitives::defaultLineStart.z()); // Default line start point Z
    mSpinBox4->setValue(Primitives::defaultLineEnd.x()); // Default line end point X
    mSpinBox5->setValue(Primitives::defaultLineEnd.y()); // Default line end point Y
    mSpinBox6->setValue(Primitives::defaultLineEnd.z()); // Default line end point Z
    // Set default values for spin boxes
    mSpinBox7->setValue(Primitives::defaultCircleRadius); // Default circle radius
    mSpinBox8->setValue(Primitives::defaultEllipseMajorRadius); // Default ellipse major radius
    mSpinBox9->setValue(Primitives::defaultEllipseMinorRadius); // Default ellipse minor radius
    mSpinBox10->setValue(Primitives::defaultArcRadiusX); // Default arc radius X
    mSpinBox11->setValue(Primitives::defaultArcRadiusY); // Default arc radius X

    spinBoxLayout->addWidget(mSpinBox1);
    spinBoxLayout->addWidget(mSpinBox2);
    spinBoxLayout->addWidget(mSpinBox3);
    spinBoxLayout->addWidget(mSpinBox4);
    spinBoxLayout->addWidget(mSpinBox5);
    spinBoxLayout->addWidget(mSpinBox6);
    spinBoxLayout->addWidget(mSpinBox7);
    spinBoxLayout->addWidget(mSpinBox8);
    spinBoxLayout->addWidget(mSpinBox9);
    spinBoxLayout->addWidget(mSpinBox10);
    spinBoxLayout->addWidget(mSpinBox11);

    // Add spin box layout to right layout
    rightLayout->addLayout(spinBoxLayout);

    //QWidget* rightWidget = new QWidget;
    rightWidget->setLayout(rightLayout);

    mSetButton = createButton("Set", Qt::gray);
    rightLayout->addWidget(mSetButton);

    // Connect spin box signals to slots
    connect(mSpinBox1, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Visualizer::updateDefaultValues);
    connect(mSpinBox2, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Visualizer::updateDefaultValues);
    connect(mSpinBox3, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Visualizer::updateDefaultValues);
    connect(mSpinBox4, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Visualizer::updateDefaultValues);
    connect(mSpinBox5, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Visualizer::updateDefaultValues);
    connect(mSpinBox6, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Visualizer::updateDefaultValues);
    connect(mSpinBox7, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Visualizer::updateDefaultValues);
    connect(mSpinBox8, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Visualizer::updateDefaultValues);
    connect(mSpinBox9, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Visualizer::updateDefaultValues);
    connect(mSpinBox10, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Visualizer::updateDefaultValues);

    // Connect the clicked signal of the QPushButton to a slot in Visualizer class
    connect(mSetButton, &QPushButton::clicked, this, &Visualizer::onSetButtonClicked);

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
    mGridLayout->addWidget(mDeleteButton, 0, 11);

    mainLayout->addLayout(mGridLayout);

    // Add the viewer and the layout to the splitter
    splitter->addWidget(mOsgViewer);
    splitter->addWidget(new QWidget); // Placeholder to maintain spacing
    splitter->addWidget(rightWidget);

    splitter->setStretchFactor(0, 1000); // Viewer
    splitter->setStretchFactor(1, 1); // Buttons

    splitter->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(10);
    // Add the splitter to the main layout
    mainLayout->addWidget(splitter);

    mWidget = new QWidget(this);
    mWidget->setLayout(mainLayout);
    mWindow.setCentralWidget(mWidget);

    mWindow.show();

    mWindow.setWindowTitle(QCoreApplication::translate("OSGCADModeler", "OSGCADModeler", nullptr));
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

QToolButton* Visualizer::createToolButton(const QString& text, const QColor& color)
{
    QToolButton* button = new QToolButton(this);
    button->setText(text);
    setToolButtonColor(button, color);
    QFont font = button->font();
    font.setPointSize(12); // Adjust the font size as needed
    button->setFont(font);
    return button;
}

void Visualizer::onSketchButtonClicked()
{
    setPlaneButtonsEnabled(true);
    setSaveAndDeleteButtonsEnabled(true);
    setPrimitivesButtonsEnabled(false);

    mOsgViewer->setViewButtonClicked(false);
}

void Visualizer::onViewButtonClicked()
{
    setPlaneButtonsEnabled(false);
    setSaveAndDeleteButtonsEnabled(true);
    setPrimitivesButtonsEnabled(false);

    // Set mViewButtonClicked to true
    mOsgViewer->setViewButtonClicked(true);
}

void Visualizer::onXYButtonClicked()
{
    setSaveAndDeleteButtonsEnabled(true);
    // Implementation for XY button click
    setPrimitivesButtonsEnabled(true);
    setPlaneToXY();
    mPlaneTextLabel->setText("XY Plane"); // Update the text
}

void Visualizer::onYZButtonClicked()
{
    setSaveAndDeleteButtonsEnabled(true);
    // Implementation for YZ button click
    setPrimitivesButtonsEnabled(true);
    setYZPlaneToXY();

    mPlaneTextLabel->setText("YZ Plane"); // Update the text
}

void Visualizer::onXZButtonClicked()
{
    setSaveAndDeleteButtonsEnabled(true);
    // Implementation for XZ button click
    setPrimitivesButtonsEnabled(true);
    setXZPlaneToXY();

    mPlaneTextLabel->setText("XZ Plane"); // Update the text
}

void Visualizer::onPointButtonClicked()
{
    osg::Geode* pointGeode = Primitives::createPoint();
    mOsgViewer->addDrawable(pointGeode);
    mOsgViewer->update();

    mPrimitiveListWidget->addItem("Point");
}

void Visualizer::onLineButtonClicked()
{
    mSpinBox1->show();
    mSpinBox2->show();
    mSpinBox3->show();
    mSpinBox4->show();
    mSpinBox5->show();
    mSpinBox6->show();
    mSpinBox1->setPrefix("Start Point x: ");
    mSpinBox2->setPrefix("Start Point y: ");
    mSpinBox3->setPrefix("Start Point z: ");
    mSpinBox4->setPrefix("End Point   x: ");
    mSpinBox5->setPrefix("End Point   y: ");
    mSpinBox6->setPrefix("End Point   z: ");
    mSpinBox7->hide();
    mSpinBox8->hide();
    mSpinBox9->hide();
    mSpinBox10->hide();
    mSpinBox11->hide();

    osg::Geode* lineGeode = Primitives::createLine();
    mOsgViewer->addDrawable(lineGeode);
    mOsgViewer->update();

    mPrimitiveListWidget->addItem("Line");
}

void Visualizer::onCircleButtonClicked()
{
    mSpinBox1->hide();
    mSpinBox2->hide();
    mSpinBox3->hide();
    mSpinBox4->hide();
    mSpinBox5->hide();
    mSpinBox6->hide();
    mSpinBox7->show();
    mSpinBox7->setPrefix("Radius: ");
    mSpinBox8->hide();
    mSpinBox9->hide();
    mSpinBox10->hide();
    mSpinBox11->hide();

    osg::Geode* circleGeode = Primitives::createCircle();
    mOsgViewer->addDrawable(circleGeode);
    mOsgViewer->update();

    mPrimitiveListWidget->addItem("Circle");
}

void Visualizer::onEllipseButtonClicked()
{
    mSpinBox1->hide();
    mSpinBox2->hide();
    mSpinBox3->hide();
    mSpinBox4->hide();
    mSpinBox5->hide();
    mSpinBox6->hide();
    mSpinBox7->hide();
    mSpinBox8->show();
    mSpinBox8->setPrefix("Major Radius: ");
    mSpinBox9->show();
    mSpinBox9->setPrefix("Minor Radius: ");
    mSpinBox10->hide();
    mSpinBox11->hide();

    osg::Geode* ellipseGeode = Primitives::createEllipse();
    mOsgViewer->addDrawable(ellipseGeode);
    mOsgViewer->update();

    mPrimitiveListWidget->addItem("Ellipse");
}

void Visualizer::onArcButtonClicked()
{
    mSpinBox1->hide();
    mSpinBox2->hide();
    mSpinBox3->hide();
    mSpinBox4->hide();
    mSpinBox5->hide();
    mSpinBox6->hide();
    mSpinBox7->hide();
    mSpinBox8->hide();
    mSpinBox9->hide();
    mSpinBox10->show();
    mSpinBox10->setPrefix("Radius X: ");
    mSpinBox11->show();
    mSpinBox11->setPrefix("Radius Y: ");

    osg::Geode* arcGeode = Primitives::createArc();
    mOsgViewer->addDrawable(arcGeode);
    mOsgViewer->update();

    mPrimitiveListWidget->addItem("Arc");

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

void Visualizer::onDeleteButtonClicked()
{
    mOsgViewer->clearDrawables(); // Remove all primitives

    mPrimitiveListWidget->clear();
}

void Visualizer::setPlaneButtonsEnabled(bool enabled)
{
    mXYButton->setEnabled(enabled);
    mYZButton->setEnabled(enabled);
    mXZButton->setEnabled(enabled);
}

void Visualizer::setSaveAndDeleteButtonsEnabled(bool enabled)
{
    mSaveButton->setEnabled(enabled);
    mDeleteButton->setEnabled(enabled);
}

void Visualizer::setPrimitivesButtonsEnabled(bool enabled)
{
    mPointButton->setEnabled(enabled);
    mLineButton->setEnabled(enabled);
    mCircleButton->setEnabled(enabled);
    mEllipseButton->setEnabled(enabled);
    mArcButton->setEnabled(enabled);
}

// To set button color
void Visualizer::setButtonColor(QPushButton* button, const QColor& color)
{
    button->setStyleSheet("background-color: " + color.name() + ";");
}

// To set tool button color
void Visualizer::setToolButtonColor(QToolButton* button, const QColor& color)
{
    button->setStyleSheet("background-color: " + color.name() + ";");
}

// To set button size
void Visualizer::setButtonSize(QPushButton* button)
{
    button->setFixedSize(110, 60); // Set size to create square shape
}

// To set tool button size
void Visualizer::setToolButtonSize(QToolButton* button)
{
    button->setFixedSize(110, 60); // Set size to create square shape
}

// To set XY plane as rendering plane 
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

// To set YZ plane as rendering plane 
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

// To set XZ plane as rendering plane  
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

// For saving the file
osg::Node* Visualizer::createPrimitivesNode(const std::vector<osg::ref_ptr<osg::Geode>>& geodes)
{
    osg::ref_ptr<osg::Group> root = new osg::Group;

    // Create a Geode to hold the primitives
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;

    // Add existing primitives to the geode
    for (const auto& g : geodes)
    {
        if (g.valid())
            geode->addChild(g);
    }

    root->addChild(geode);

    // Return the root node containing all the primitives
    return root.release();
}

// For saving the file
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

// To update the default values of parameter
void Visualizer::updateDefaultValues()
{
    // Update default values for line start and end points
    Primitives::setDefaultLineStart(osg::Vec3(mSpinBox1->value(), mSpinBox2->value(), mSpinBox3->value()));
    Primitives::setDefaultLineEnd(osg::Vec3(mSpinBox4->value(), mSpinBox5->value(), mSpinBox6->value()));

    // Update default values for circle radius
    Primitives::setDefaultCircleRadius(mSpinBox7->value());

    // Update default values for ellipse major and minor radius
    Primitives::setDefaultEllipseMajorRadius(mSpinBox8->value());
    Primitives::setDefaultEllipseMinorRadius(mSpinBox9->value());

    // Update default values for arc radii
    Primitives::setDefaultArcRadiusX(mSpinBox10->value());
    Primitives::setDefaultArcRadiusY(mSpinBox11->value());
}

// Update the default values for primitives based on spin box values
void Visualizer::onSetButtonClicked()
{
    updateDefaultValues();
}
