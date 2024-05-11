#include "stdafx.h"
#include "Primitives.h"
#include <osg/ShapeDrawable>

osg::Geometry* Primitives::createPoint(const osg::Vec3& position)
{
    // Implementation of createPoint function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    vertices->push_back(position);
    geom->setVertexArray(vertices);

    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
    geom->setColorArray(colors, osg::Array::BIND_OVERALL);

    geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, 1));

    return geom.release();
}

osg::Geometry* Primitives::createLine(const osg::Vec3& start, const osg::Vec3& end)
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

    return geom.release();
}

osg::Geometry* Primitives::createCircle(float radius, int numSegments)
{
    // Implementation of createCircle function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    geom->setVertexArray(vertices);

    float angleIncrement = 2.0f * osg::PI / numSegments;
    for (int i = 0; i < numSegments; ++i)
    {
        float angle = angleIncrement * i;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        vertices->push_back(osg::Vec3(x, 0.0f, z));
    }

    geom->setColorBinding(osg::Geometry::BIND_OVERALL);
    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
    geom->setColorArray(colors);

    geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_LOOP, 0, numSegments));

    return geom.release();
}

osg::Geometry* Primitives::createEllipse(float majorRadius, float minorRadius, int numSegments)
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

    geom->setColorBinding(osg::Geometry::BIND_OVERALL);
    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
    geom->setColorArray(colors);

    geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_LOOP, 0, numSegments));

    return geom.release();
}

osg::Geometry* Primitives::createArc(float radius, float startAngle, float endAngle, int numSegments)
{
    // Implementation of createArc function
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    geom->setVertexArray(vertices);

    float angleIncrement = (endAngle - startAngle) / static_cast<float>(numSegments - 1);
    for (int i = 0; i < numSegments; ++i)
    {
        float angle = startAngle + angleIncrement * i;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        vertices->push_back(osg::Vec3(x, 0.0f, z));
    }

    geom->setColorBinding(osg::Geometry::BIND_OVERALL);
    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
    geom->setColorArray(colors);

    geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_STRIP, 0, numSegments));

    return geom.release();
}
