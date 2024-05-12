#pragma once

#include <osg/Node>
#include <osgDB/WriteFile>

class OsgFileWriter {
public:
    static bool writeNodeToFile(const osg::Node* node, const std::string& filename, const osgDB::ReaderWriter::Options* options = nullptr);

private:
    static void traverseNode(const osg::Node* node, std::ofstream& outFile);
    static void writeGeometryData(const osg::Geometry* geometry, std::ofstream& outFile);
};
