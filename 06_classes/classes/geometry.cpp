#include "geometry.hpp"

#include <cmath>
#include <iostream>

namespace geom3d
{

    Point3D::Point3D(double x, double y, double z) : x{x}, y{y}, z{z} 
    {
        std::cout <<"calling constructor" << std::endl;
    } //non-default constructor

    //definitions of special member functions:
    Point3D::Point3D(const Point3D& other) : x{other.x}, y{other.y}, z{other.z} 
    {
        std::cout <<"calling copy constructor" << std::endl;
    } //copy constructor

    Point3D::Point3D(Point3D&& other) noexcept : x{std::move(other.x)}, y{std::move(other.y)}, z{std::move(other.z)} 
    {
        std::cout <<"calling move constructor" << std::endl;
    } //move constructor

    Point3D& Point3D::operator=(const Point3D& other)
    {
        std::cout <<"calling copy assignment operator" << std::endl;
        if (this != &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    } //copy assignment operator

    Point3D& Point3D::operator=(Point3D&& other) noexcept
    {
        std::cout <<"calling move assignment operator" << std::endl;
        if (this != &other)
        {
            x = std::move(other.x);
            y = std::move(other.y);
            z = std::move(other.z);
        }
        return *this;
    } //move assignment operator

    Point3D::~Point3D() 
    {
        std::cout <<"calling destructor" << std::endl;
    } //destructor

    double Point3D::distance(const Point3D& other) const
    {
        const auto dx = x - other.x;
        const auto dy = y - other.y;
        const auto dz = z - other.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    SphericalCoordinates Point3D::toSpherical() const
    {
        SphericalCoordinates spherical;
        spherical.radius = std::sqrt(x * x + y * y + z * z);
        spherical.theta = std::atan2(y, x);
        spherical.phi = std::acos(z / spherical.radius);
        return spherical;
    }

    void Point3D::print() const
    {
        std::cout << "Point3D(" << x << ", " << y << ", " << z << ")" << std::endl;
    }





}