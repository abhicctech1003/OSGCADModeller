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
    void onClearButtonClicked();

private:
    void setupUi();
    void setPlaneButtonsEnabled(bool enabled);
    void setSaveAndClearButtonsEnabled(bool enabled);
    void setPrimitivesButtonsEnabled(bool enabled);
    void setButtonColor(QPushButton* button, const QColor& color);
    void setSquareButton(QPushButton* button);
    QPushButton* createButton(const QString& text, const QColor& color);
    void setPlaneToXY();
    void setXZPlaneToXY();
    void setYZPlaneToXY();
    void renderPrimitiveFile(osg::Node* primitivesNode);
    osg::Node* createPrimitivesNode(const std::vector<osg::ref_ptr<osg::Geode>>& geodes);

    QWidget* mWidget;
    QGridLayout* mGridLayout;
    QPushButton* mSketchButton;
    QPushButton* mViewButton;
    QPushButton* mXYButton;
    QPushButton* mYZButton;
    QPushButton* mXZButton;
    QPushButton* mPointButton;
    QPushButton* mLineButton;
    QPushButton* mCircleButton;
    QPushButton* mEllipseButton;
    QPushButton* mArcButton;
    QPushButton* mSaveButton;
    QPushButton* mClearButton;

    QMainWindow mWindow;
    OpenSceneGraphViewer* mOsgViewer;
    QVBoxLayout* mainLayout;

    bool mYZPlaneEnabled = false;
    bool mXZPlaneEnabled = false;
};
