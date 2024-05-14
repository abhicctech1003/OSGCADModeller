#pragma once

#include <osg/Geometry>
#include <osg/Vec3>

class Primitives
{
public:
    static osg::Geode* createPoint(const osg::Vec3& position);
    static osg::Geode* createLine(const osg::Vec3& start, const osg::Vec3& end);
    static osg::Geode* createCircle(float radius, int numSegments);
    static osg::Geode* createEllipse(float majorRadius, float minorRadius, int numSegments);
    static osg::Geode* createArc(float radiusX, float radiusY, float startAngle, float endAngle, int numSegments);
};
