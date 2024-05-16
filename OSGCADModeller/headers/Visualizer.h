#pragma once
#include "OpenSceneGraphViewer.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets>


class OpenSceneGraphViewer;

class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWidget* parent = nullptr);
    ~Visualizer();

private slots:
    void onSketchButtonClicked();
    void onViewButtonClicked();
    void onXYButtonClicked();
    void onYZButtonClicked();
    void onXZButtonClicked();
    void onPointButtonClicked();
    void onLineButtonClicked();
    void onCircleButtonClicked();
    void onEllipseButtonClicked();
    void onArcButtonClicked();
    void onSaveButtonClicked();
    void onDeleteButtonClicked();
    void updateDefaultValues();
    void onSetButtonClicked();

private:
    void setupUi();
    void setPlaneButtonsEnabled(bool enabled);
    void setSaveAndDeleteButtonsEnabled(bool enabled);
    void setPrimitivesButtonsEnabled(bool enabled);
    void setButtonColor(QPushButton* button, const QColor& color);
    void setToolButtonColor(QToolButton* button, const QColor& color);
    void setButtonSize(QPushButton* button);
    void setToolButtonSize(QToolButton* button);
    QPushButton* createButton(const QString& text, const QColor& color);
    QToolButton* createToolButton(const QString& text, const QColor& color);
    void setPlaneToXY();
    void setXZPlaneToXY();
    void setYZPlaneToXY();
    void renderPrimitiveFile(osg::Node* primitivesNode);
    osg::Node* createPrimitivesNode(const std::vector<osg::ref_ptr<osg::Geode>>& geodes);


    QWidget* mWidget;
    QGridLayout* mGridLayout;

    QToolButton* mSketchButton;
    QToolButton* mViewButton;
    QToolButton* mXYButton;
    QToolButton* mYZButton;
    QToolButton* mXZButton;
    QPushButton* mPointButton;
    QPushButton* mLineButton;
    QPushButton* mCircleButton;
    QPushButton* mEllipseButton;
    QPushButton* mArcButton;
    QPushButton* mSaveButton;
    QPushButton* mDeleteButton;
    QPushButton* mSetButton;
    QLabel* mPlaneTextLabel;
    QListWidget* mPrimitiveListWidget;
    QVBoxLayout* mRightLayout;

    QDoubleSpinBox* mSpinBox1;
    QDoubleSpinBox* mSpinBox2;
    QDoubleSpinBox* mSpinBox3;
    QDoubleSpinBox* mSpinBox4;
    QDoubleSpinBox* mSpinBox5;
    QDoubleSpinBox* mSpinBox6;
    QDoubleSpinBox* mSpinBox7;
    QDoubleSpinBox* mSpinBox8;
    QDoubleSpinBox* mSpinBox9;
    QDoubleSpinBox* mSpinBox10;
    QDoubleSpinBox* mSpinBox11;

    QMainWindow mWindow;
    OpenSceneGraphViewer* mOsgViewer;
    QVBoxLayout* mainLayout;

    bool mYZPlaneEnabled = false;
    bool mXZPlaneEnabled = false;

};
