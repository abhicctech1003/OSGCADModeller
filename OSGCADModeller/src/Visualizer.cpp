#include "stdafx.h"
#include "Visualizer.h"
#include "OpenSceneGraphViewer.h"
#include "Primitives.h"

Visualizer::Visualizer(QWidget* parent) : QMainWindow(parent)
{
    setupUi();
    // Initially disable the additional buttons
    setPlaneButtonsEnabled(false);
    setFunctionalityButtonsEnabled(false);
}

Visualizer::~Visualizer()
{}

void Visualizer::setupUi()
{

    mWindow.resize(600, 600);


    mainLayout = new QVBoxLayout;

    mOsgViewer = new OpenSceneGraphViewer(1, 1, &mWindow);

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
    setFunctionalityButtonsEnabled(false);
}

void Visualizer::onViewButtonClicked()
{
    setPlaneButtonsEnabled(false);
    setFunctionalityButtonsEnabled(false);
}

void Visualizer::onXYButtonClicked()
{
    // Implementation for XY button click
    setFunctionalityButtonsEnabled(true);
}

void Visualizer::onYZButtonClicked()
{
    // Implementation for YZ button click
    setFunctionalityButtonsEnabled(true);
}

void Visualizer::onXZButtonClicked()
{
    // Implementation for XZ button click
    setFunctionalityButtonsEnabled(true);
}

void Visualizer::onPointButtonClicked()
{

    mOsgViewer->addDrawable(Primitives::createPoint(osg::Vec3(4.0f, 1.0f, 0.0f))); // Call createPoint function
}

void Visualizer::onLineButtonClicked()
{
    mOsgViewer->addDrawable(Primitives::createLine(osg::Vec3(0.0f, 0.0f, 0.0f), osg::Vec3(6.0f, 0.0f, 0.0f))); // Call createLine function
}

void Visualizer::onCircleButtonClicked()
{
    mOsgViewer->addDrawable(Primitives::createCircle(3.0f, 36)); // Call createCircle function
}

void Visualizer::onEllipseButtonClicked()
{
    mOsgViewer->addDrawable(Primitives::createEllipse(4.0f, 2.0f, 36)); // Call createEllipse function
}

void Visualizer::onArcButtonClicked()
{
    mOsgViewer->addDrawable(Primitives::createArc(3.0f, osg::PI / 4.0f, 3.0f * osg::PI / 4.0f, 36)); // Call createArc function
}

void Visualizer::onSaveButtonClicked()
{
    
}

void Visualizer::onClearButtonClicked()
{
    
}

void Visualizer::setPlaneButtonsEnabled(bool enabled)
{
    mXYButton->setEnabled(enabled);
    mYZButton->setEnabled(enabled);
    mXZButton->setEnabled(enabled);
}

void Visualizer::setFunctionalityButtonsEnabled(bool enabled)
{
    mPointButton->setEnabled(enabled);
    mLineButton->setEnabled(enabled);
    mCircleButton->setEnabled(enabled);
    mEllipseButton->setEnabled(enabled);
    mArcButton->setEnabled(enabled);
    mSaveButton->setEnabled(enabled);
    mClearButton->setEnabled(enabled);
}

void Visualizer::setButtonColor(QPushButton* button, const QColor& color)
{
    button->setStyleSheet("background-color: " + color.name() + ";");
}

void Visualizer::setSquareButton(QPushButton* button)
{
    button->setFixedSize(100, 60); // Set size to create square shape
}

