#pragma once

namespace geom3d
{

struct SphericalCoordinates
{
    double radius{};
    double theta{};
    double phi{};
};

class Point3D
{
    public:
        Point3D() = default; //default constructor
        Point3D(double x, double y, double z); //non-default constructor

        //declarations of special member functions:
        Point3D(const Point3D& other); //copy constructor
        Point3D(Point3D&& other) noexcept; //move constructor
        Point3D& operator=(const Point3D& other); //copy assignment operator
        Point3D& operator=(Point3D&& other) noexcept; //move assignment operator
        ~Point3D(); //destructor

        double distance(const Point3D& other) const;
        SphericalCoordinates toSpherical() const;
        void print() const;

    private:
        double x{};
        double y{};
        double z{};

};


}
