#include "geometry.hpp"

#include <iostream>
#include <vector>

geom3d::Point3D createPoint()
{
    geom3d::Point3D p{0.0, 0.0, 1.0};
    return p;
}

int main()
{
    // geom3d::Point3D A{1.0, 2.0, 3.0};
    // geom3d::Point3D B{std::move(A)}; //move construction
    // geom3d::Point3D C = B;

    std::vector<geom3d::Point3D> points;
    // points.reserve(10);
    //show pushing back two points without reserving!!!
    //show pushing back two with move constructor without noexcept

    points.push_back(createPoint());
    //points.push_back(createPoint());
    //points.push_back(A);
    
    return EXIT_SUCCESS;
}
