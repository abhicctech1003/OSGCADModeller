#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include "OpenSceneGraphViewer.h"

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
    void setFunctionalityButtonsEnabled(bool enabled);
    void setButtonColor(QPushButton* button, const QColor& color);
    void setSquareButton(QPushButton* button);
    QPushButton* createButton(const QString& text, const QColor& color);

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
};
