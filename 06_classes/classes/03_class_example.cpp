#include <iostream>
#include <cmath>

#include "geometry.hpp"

int main()
{
    geom3d::Point3D p1(1.0, 2.0, 3.0);
    geom3d::Point3D p2(4.0, 5.0, 6.0);
    geom3d::Point3D p3; //default constructor

    const auto spherical {p1.toSpherical()};

    p1.print();
    p2.print();
    p3.print();
    std::cout << "Spherical coordinates for p1: radius=" << spherical.radius << ", theta=" << spherical.theta << ", phi=" << spherical.phi << std::endl;
    std::cout << "Distance: " << p1.distance(p2) << std::endl;

    return EXIT_SUCCESS;
}

