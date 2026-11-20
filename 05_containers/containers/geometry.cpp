
#include "geometry.hpp"

#include <fstream>

namespace geometry
{

PointsIn2D readPointsIn2DFromFile(const std::filesystem::path pathToFile)
{
    PointsIn2D points;
    const auto coordinatesOfAllPoints{readDataOfPoints(pathToFile)};
    for (const auto& coordinates: coordinatesOfAllPoints)
    {
        if (coordinates.size() != 2 )
        {
            throw std::runtime_error("Fatal Error. File with 2D point data is missformated");
        }

        points.push_back(Point2d{coordinates[0], coordinates[1]});
    }

    return points;
}

PointsIn3D readPointsIn3DFromFile(const std::filesystem::path pathToFile)
{
    PointsIn3D points;
    const auto coordinatesOfAllPoints{readDataOfPoints(pathToFile)};
    for (const auto& coordinates: coordinatesOfAllPoints)
    {
        if (coordinates.size() != 3 )
        {
            throw std::runtime_error("Fatal Error. File with 3D point data is missformated");
        }

        points.push_back(Point3d{coordinates[0], coordinates[1], coordinates[2]});
    }
    return points;
}

std::vector<std::vector<double>> readDataOfPoints(const std::filesystem::path& pathToFile)
{
    if (!std::filesystem::exists(pathToFile))
    {
        throw std::invalid_argument("Fatal Error. File with point observations does not exist!");
    }

    auto file{std::ifstream{pathToFile}};
    std::string header;
    std::getline(file, header, '\n');
    std::vector<std::vector<double>> coordinatesOfAllPoints;
    coordinatesOfAllPoints.reserve(1024);

    for (std::string line; std::getline(file, line, '\n');)
    {
        std::istringstream dataRecord;
        dataRecord.str(line);
        std::vector<double> pointData;

        for (std::string entry; std::getline(dataRecord, entry, ',');)
        {
            pointData.push_back(std::stod(entry));
        }
        coordinatesOfAllPoints.push_back(pointData);     
    }
    coordinatesOfAllPoints.shrink_to_fit();
    return coordinatesOfAllPoints;
}


}