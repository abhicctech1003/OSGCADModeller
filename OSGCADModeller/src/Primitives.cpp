#include "stdafx.h"
#include "Primitives.h"
#include <osg/ShapeDrawable>
#include <osg/ref_ptr>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include <osg/Vec3>
#include <osg/Vec4>
#include <osg/PrimitiveSet>
#include <osg/Geometry>
#include <osg/Point>
#include <osg/GL>

// Define static member variables
osg::Vec3 Primitives::defaultLineStart = osg::Vec3(-10.0f, 0.0f, 0.0f);
osg::Vec3 Primitives::defaultLineEnd = osg::Vec3(10.0f, 0.0f, 0.0f);
float Primitives::defaultCircleRadius = 1.0f;
float Primitives::defaultEllipseMajorRadius = 1.0f;
float Primitives::defaultEllipseMinorRadius = 0.5f;
float Primitives::defaultArcRadiusX = 45.0f;
float Primitives::defaultArcRadiusY = 1.0f;

Primitives::Primitives()
{
    // Constructor
}

Primitives::~Primitives()
{
    // Destructor
}

// Function To Create a Point
osg::Geode* Primitives::createPoint()
{
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    geom->setVertexArray(vertices);

    float angleIncrement = 2.0f * osg::PI / 36;
    for (int i = 0; i < 36; ++i) {
        float angle = angleIncrement * i;
        float x = 0.00000001 * cos(angle);
        float z = 0.00000001 * sin(angle);
        vertices->push_back(osg::Vec3(x, 0.0f, z));
    }

    osg::ref_ptr<osg::DrawArrays> drawArray = new osg::DrawArrays(osg::PrimitiveSet::LINE_LOOP, 0, 36);
    geom->addPrimitiveSet(drawArray);

    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
    geom->setColorArray(colors, osg::Array::BIND_OVERALL);

    osg::ref_ptr<osg::StateSet> stateSet = new osg::StateSet;
    stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
    geom->setStateSet(stateSet);

    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable(geom);

    return geode.release();
}

// Function To Create a Line
osg::Geode* Primitives::createLine(const osg::Vec3& start, const osg::Vec3& end)
{
    // Implementation of createLine function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    vertices->push_back(start);
    vertices->push_back(end);
    geom->setVertexArray(vertices);

    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
    geom->setColorArray(colors, osg::Array::BIND_OVERALL);

    geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_STRIP, 0, 2));

    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable(geom);

    return geode.release();
}

// Function To Create a Circle
osg::Geode* Primitives::createCircle(float radius)
{
    // Implementation of createCircle function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    geom->setVertexArray(vertices);

    int numSegments = 36;

    float angleIncrement = 2.0f * osg::PI / numSegments;
    for (int i = 0; i < numSegments; ++i) {
        float angle = angleIncrement * i;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        vertices->push_back(osg::Vec3(x, 0.0f, z));
    }

    osg::ref_ptr<osg::DrawArrays> drawArray = new osg::DrawArrays(osg::PrimitiveSet::LINE_LOOP, 0, numSegments);
    geom->addPrimitiveSet(drawArray);

    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
    geom->setColorArray(colors, osg::Array::BIND_OVERALL);

    osg::ref_ptr<osg::StateSet> stateSet = new osg::StateSet;
    stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
    geom->setStateSet(stateSet);

    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable(geom);

    return geode.release();
}

// Function To Create a Ellipse
osg::Geode* Primitives::createEllipse(float majorRadius, float minorRadius)
{
    // Implementation of createEllipse function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    geom->setVertexArray(vertices);

    int numSegments = 36;

    float angleIncrement = 2.0f * osg::PI / numSegments;
    for (int i = 0; i < numSegments; ++i)
    {
        float angle = angleIncrement * i;
        float x = majorRadius * cos(angle);
        float z = minorRadius * sin(angle);
        vertices->push_back(osg::Vec3(x, 0.0f, z));
    }

    // Connect the last point with the first point to close the ellipse
    vertices->push_back(vertices->front());

    // Create a primitive set (line loop)
    osg::ref_ptr<osg::DrawElementsUInt> loop =
        new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP, 0);
    for (unsigned int i = 0; i < numSegments; ++i)
    {
        loop->push_back(i);
    }

    // Add primitive set to geometry
    geom->addPrimitiveSet(loop);

    // Create Geode to hold the geometry
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable(geom);

    return geode.release();
}


osg::Geode* Primitives::createArc(float radiusX, float radiusY)
{
    // Implementation of createArc function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    geom->setVertexArray(vertices);

    float startAngle = osg::PI / 4.0f;
    float endAngle = 3.0f * osg::PI / 4.0f;
    int numSegments = 36;

    // Convert angles to radians
    startAngle = osg::DegreesToRadians(startAngle);
    endAngle = osg::DegreesToRadians(endAngle);

    // Calculate angle increment based on the number of segments
    float angleIncrement = (endAngle - startAngle) / (numSegments - 1);

    // Add points along the arc
    for (int i = 0; i < numSegments; ++i)
    {
        float angle = startAngle + angleIncrement * i;
        float x = radiusX * cos(angle);
        float z = radiusY * sin(angle);
        vertices->push_back(osg::Vec3(x, 0.0f, z));
    }

    // Create a primitive set (line strip)
    osg::ref_ptr<osg::DrawElementsUInt> strip =
        new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP, 0);
    for (unsigned int i = 0; i < numSegments; ++i)
    {
        strip->push_back(i);
    }

    // Add primitive set to geometry
    geom->addPrimitiveSet(strip);

    // Create Geode to hold the geometry
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable(geom);

    return geode.release();
}

osg::Vec3 Primitives::getDefaultLineStart()
{
    return defaultLineStart;
}

osg::Vec3 Primitives::getDefaultLineEnd()
{
    return defaultLineEnd;
}

float Primitives::getDefaultCircleRadius()
{
    return defaultCircleRadius;
}

float Primitives::getDefaultEllipseMajorRadius()
{
    return defaultEllipseMajorRadius;
}

float Primitives::getDefaultEllipseMinorRadius()
{
    return defaultEllipseMinorRadius;
}

float Primitives::getDefaultArcRadiusX()
{
    return defaultArcRadiusX;
}

float Primitives::getDefaultArcRadiusY()
{
    return defaultArcRadiusY;
}
