#include "stdafx.h"
#include "OpenSceneGraphViewer.h"
#include "Visualizer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Visualizer w;
    return a.exec();
}
