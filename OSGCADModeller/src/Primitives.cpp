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

osg::Geode* Primitives::createPoint(const osg::Vec3& position)
{
     //Implementation of createPoint function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    vertices->push_back(position);
    geom->setVertexArray(vertices);

    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
    geom->setColorArray(colors, osg::Array::BIND_OVERALL);

    geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, 1));

    // Set point size
    osg::StateSet* state = geom->getOrCreateStateSet();
    state->setMode(GL_POINT_SMOOTH, osg::StateAttribute::ON);
    state->setMode(GL_VERTEX_PROGRAM_POINT_SIZE, osg::StateAttribute::ON); // Enable vertex program point size mode
    state->setAttribute(new osg::Point(10.0f), osg::StateAttribute::ON);

    osg::Point* pointAttribute = new osg::Point;
    pointAttribute->setSize(10.0f);
    geom->getOrCreateStateSet()->setAttribute(pointAttribute);

    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable(geom);

    return geode.release();
}

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

osg::Geode* Primitives::createCircle(float radius, int numSegments)
{
    // Implementation of createCircle function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    geom->setVertexArray(vertices);

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

osg::Geode* Primitives::createEllipse(float majorRadius, float minorRadius, int numSegments)
{
    // Implementation of createEllipse function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    geom->setVertexArray(vertices);

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

osg::Geode* Primitives::createArc(float radiusX, float radiusY, float startAngle, float endAngle, int numSegments)
{
    // Implementation of createArc function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    geom->setVertexArray(vertices);

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
