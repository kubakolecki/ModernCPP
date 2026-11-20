#include "geometry.hpp"

#include <iostream>

int main()
{
    std::filesystem::path pathToFilePoints2d{"D:/dydaktyka/Modern_C++/point_cloud_simulator/src/points_in_line.txt"};
    std::filesystem::path pathToFilePoints3d{"D:/dydaktyka/Modern_C++/point_cloud_simulator/src/points_in_3d.txt"};
    const auto pointsIn2D{geometry::readPointsIn2DFromFile(pathToFilePoints2d)};
    const auto pointsIn3D{geometry::readPointsIn3DFromFile(pathToFilePoints3d)};
    const auto numOfPontsIn2D{pointsIn2D.size()};
    const auto numOfPontsIn3D{pointsIn3D.size()};
    std::cout << "Number of 2D points loaded: " << numOfPontsIn2D  << std::endl;
    // for (const auto& p: pointsIn2D)
    // {
    //     std::cout <<p.x << " "<< p.y <<"\n";
    // }


    std::cout << "Number of 3D points loaded: " << numOfPontsIn3D  << std::endl;
    // for (const auto& p: pointsIn3D)
    // {
    //     std::cout <<p.x << " "<< p.y <<" "<< p.z <<"\n";
    // }
    


    return 0;
}