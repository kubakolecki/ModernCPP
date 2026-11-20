#include <iostream>

struct Point2D
{
    double x{};
    double y{};
};

class Point3D
{
    double x{};
    double y{};
    double z{};
};

int main()
{
    Point2D A{};
    Point3D B{};

    std::cout <<"A: "<< A.x <<" "<<A.y <<std::endl;
    std::cout <<"B: "<< B.x <<" "<<B.y <<" "<<B.z <<std::endl; //does not compile!

    Point2D C{3.0, -3.0};
    Point3D D{3.0, -3.0, 5.0}; //does not compile!

}