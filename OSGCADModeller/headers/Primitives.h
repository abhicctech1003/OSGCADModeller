#pragma once
#include<iostream>
#include <osg/Geometry>
#include <osg/Vec3>
using namespace std;

class Primitives
{
public:
    Primitives();
    ~Primitives();

    // Default parameter values for primitives
    static osg::Vec3 defaultLineStart;
    static osg::Vec3 defaultLineEnd;
    static float defaultCircleRadius;
    static float defaultEllipseMajorRadius;
    static float defaultEllipseMinorRadius;
    static float defaultArcRadiusX;
    static float defaultArcRadiusY;

    static osg::Geode* createPoint();
    static osg::Geode* createLine(const osg::Vec3& start = defaultLineStart, const osg::Vec3& end = defaultLineEnd);
    static osg::Geode* createCircle(float radius = defaultCircleRadius);
    static osg::Geode* createEllipse(float majorRadius = defaultEllipseMajorRadius, float minorRadius = defaultEllipseMinorRadius);
    static osg::Geode* createArc(float radiusX = defaultArcRadiusX, float radiusY = defaultArcRadiusY);

    // Static member functions to set default values
    static void setDefaultLineStart(const osg::Vec3& start) { defaultLineStart = start; }
    static void setDefaultLineEnd(const osg::Vec3& end) { defaultLineEnd = end; }
    static void setDefaultCircleRadius(float radius) { defaultCircleRadius = radius; }
    static void setDefaultEllipseMajorRadius(float majorRadius) { defaultEllipseMajorRadius = majorRadius; }
    static void setDefaultEllipseMinorRadius(float minorRadius) { defaultEllipseMinorRadius = minorRadius; }
    static void setDefaultArcRadiusX(float radiusX) { defaultArcRadiusX = radiusX; }
    static void setDefaultArcRadiusY(float radiusY) { defaultArcRadiusY = radiusY; }

    static osg::Vec3 getDefaultLineStart();
    static osg::Vec3 getDefaultLineEnd();
    static float getDefaultCircleRadius();
    static float getDefaultEllipseMajorRadius();
    static float getDefaultEllipseMinorRadius();
    static float getDefaultArcRadiusX();
    static float getDefaultArcRadiusY();
};
