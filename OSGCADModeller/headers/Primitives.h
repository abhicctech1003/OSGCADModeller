#pragma once

#include <osg/Geometry>
#include <osg/Vec3>

class Primitives
{
public:
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
    static osg::Geode* createCircle(float radius = defaultCircleRadius, int numSegments = 36);
    static osg::Geode* createEllipse(float majorRadius = defaultEllipseMajorRadius, float minorRadius = defaultEllipseMinorRadius, int numSegments = 36);
    static osg::Geode* createArc(float radiusX = defaultArcRadiusX, float radiusY = defaultArcRadiusY, float startAngle = osg::PI / 4.0f, float endAngle = 3.0f * osg::PI / 4.0f, int numSegments = 36);

    // Static member functions to set default values
    static void setDefaultLineStart(const osg::Vec3& start) { defaultLineStart = start; }
    static void setDefaultLineEnd(const osg::Vec3& end) { defaultLineEnd = end; }
    static void setDefaultCircleRadius(float radius) { defaultCircleRadius = radius; }
    static void setDefaultEllipseMajorRadius(float majorRadius) { defaultEllipseMajorRadius = majorRadius; }
    static void setDefaultEllipseMinorRadius(float minorRadius) { defaultEllipseMinorRadius = minorRadius; }
    static void setDefaultArcRadiusX(float radiusX) { defaultArcRadiusX = radiusX; }
    static void setDefaultArcRadiusY(float radiusY) { defaultArcRadiusY = radiusY; }
};
