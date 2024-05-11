#pragma once

#include <osg/Geometry>
#include <osg/Vec3>

class Primitives
{
public:
    static osg::Geometry* createPoint(const osg::Vec3& position);
    static osg::Geometry* createLine(const osg::Vec3& start, const osg::Vec3& end);
    static osg::Geometry* createCircle(float radius, int numSegments);
    static osg::Geometry* createEllipse(float majorRadius, float minorRadius, int numSegments);
    static osg::Geometry* createArc(float radius, float startAngle, float endAngle, int numSegments);
};
