#include "geometry.hpp"

#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>
#include <ranges>
#include <fstream>
#include <iomanip>

int main()
{
    std::filesystem::path pathToPoints{"D:/dydaktyka/Modern_C++/point_cloud_simulator/src/points_3d_dataset/points_in_3d_28.txt"};
    auto points{geometry::readPointsIn3DFromFile(pathToPoints)};
    double radius{8.0+28*0.01};

    auto cartesianToSperical = [](const auto& p){
        const auto radius = std::sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
        const auto theta = std::acos(p.z/radius);
        const auto phi = std::atan2(p.y, p.x);
        return geometry::SphericalCoordinates{radius, theta, phi};
    };

    auto sphericalToCartesian = [](const auto& p){
        const auto x = p.radius*std::sin(p.theta)*std::cos(p.phi);
        const auto y = p.radius*std::sin(p.theta)*std::sin(p.phi);
        const auto z = p.radius*std::cos(p.theta);
        return geometry::Point3d{x,y,z};
    };
    
    std::vector<geometry::SphericalCoordinates> sphericalCoordinates;
    std::ranges::transform(points, std::back_inserter(sphericalCoordinates), cartesianToSperical);

    auto pointsCloseToSphere = sphericalCoordinates |
    std::views::filter([radius = radius](const auto& sphCoords){return std::fabs(sphCoords.radius - radius) < 1.0; });

    std::vector<geometry::SphericalCoordinates> projectionsToSphereSpherical;
    auto closePointsProjectedOnTheSpere = sphericalCoordinates |
    std::views::filter([radius = radius](const auto& sphCoords){return std::fabs(sphCoords.radius - radius) < 1.0; }) |
    std::views::transform([radius = radius](const auto& sphCoords){auto p = sphCoords; p.radius = radius;  return p;}) |
    std::views::transform(sphericalToCartesian) |
    std::ranges::to<std::vector>();

    std::cout <<"number of points on sphere = " << closePointsProjectedOnTheSpere.size() <<std::endl;

    std::filesystem::path outputFile("points_on_sphere.txt");
    auto file = std::ofstream(outputFile);
    file << std::fixed;
    file << std::setprecision(5);
    for (const auto& p: closePointsProjectedOnTheSpere)
    {
        file << p.x <<" "<<p.y<<" "<<p.z <<"\n";
    }

    return EXIT_SUCCESS;
}