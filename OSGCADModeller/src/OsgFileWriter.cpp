#include "stdafx.h"
#include "OsgFileWriter.h"
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Array>
#include <fstream>

bool OsgFileWriter::writeNodeToFile(const osg::Node* node, const std::string& filename, const osgDB::ReaderWriter::Options* options)
{
    if (!node) return false;

    // Open the file for writing
    std::ofstream outFile(filename, std::ios::out | std::ios::binary);
    if (!outFile.is_open()) return false;

    // Write the header
    outFile << "#OSG ASCII Scene" << std::endl;

    // Traverse the node to extract geometry information
    traverseNode(node, outFile);

    // Close the file
    outFile.close();

    return true;
}

void OsgFileWriter::traverseNode(const osg::Node* node, std::ofstream& outFile)
{
    if (!node) return;

    const osg::Group* group = node->asGroup();
    if (group)
    {
        for (unsigned int i = 0; i < group->getNumChildren(); ++i)
        {
            traverseNode(group->getChild(i), outFile);
        }
    }

    const osg::Geode* geode = node->asGeode();
    if (geode)
    {
        for (unsigned int i = 0; i < geode->getNumDrawables(); ++i)
        {
            const osg::Geometry* geometry = dynamic_cast<const osg::Geometry*>(geode->getDrawable(i));
            if (geometry)
            {
                writeGeometryData(geometry, outFile);
            }
        }
    }
}

void OsgFileWriter::writeGeometryData(const osg::Geometry* geometry, std::ofstream& outFile)
{
    if (!geometry) return;

    const osg::Vec3Array* vertices = dynamic_cast<const osg::Vec3Array*>(geometry->getVertexArray());
    if (vertices)
    {
        outFile << "# Vertices: " << std::endl;
        for (size_t i = 0; i < vertices->size(); ++i)
        {
            const osg::Vec3& vertex = (*vertices)[i];
            outFile << "   " << vertex.x() << " " << vertex.y() << " " << vertex.z() << std::endl;
        }
    }

    const osg::Vec4Array* colors = dynamic_cast<const osg::Vec4Array*>(geometry->getColorArray());
    if (colors)
    {
        outFile << "# Colors: " << std::endl;
        for (size_t i = 0; i < colors->size(); ++i)
        {
            const osg::Vec4& color = (*colors)[i];
            outFile << "   " << color.r() << " " << color.g() << " " << color.b() << " " << color.a() << std::endl;
        }
    }
}
