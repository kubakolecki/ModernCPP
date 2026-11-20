#pragma once

#include <vector>
#include <filesystem>

namespace geometry
{

struct Point2d
{
    double x{0.0};
    double y{0.0};
};

struct Point3d
{
    double x{0.0};
    double y{0.0};
    double z{0.0};
};

struct Circle
{
    Point2d center;
    double radius;
};

using PointsIn2D = std::vector<Point2d>;
using PointsIn3D = std::vector<Point3d>;

PointsIn2D readPointsIn2DFromFile(const std::filesystem::path pathToFile);
PointsIn3D readPointsIn3DFromFile(const std::filesystem::path pathToFile);
std::vector<std::vector<double>> readDataOfPoints(const std::filesystem::path& pathToFile);


}