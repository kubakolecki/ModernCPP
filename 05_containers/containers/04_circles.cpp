#include "geometry.hpp"

#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>

int main()
{
    std::vector<geometry::Circle> circles;

    
    for (double x = -4.1; x < 4.2; x+= 0.61)
    {
        const double y{2*x*x - 0.5*x - 3};
        circles.push_back(geometry::Circle{{x,y},  std::fabs(y) + 1.0 });
    }

    std::cout << "\ngenerated circles:\n";
    for (const auto& c: circles)
    {
        std::cout <<std::fixed <<std::setprecision(2) << c.center.x <<" "<<c.center.y <<" "<<c.radius <<std::endl;
    }

    std::cout << "\ngenerated circles:\n";
    for (auto c {circles.begin()}; c != circles.end(); c++ )
    {
        const auto id {c - circles.begin()};
        std::cout <<std::fixed <<std::setprecision(2)<< id <<" " << c->center.x <<" "<<c->center.y <<" "<<c->radius <<std::endl;
    }

    std::sort(circles.begin(), circles.end(), [](const auto& circle1, const auto& circle2){return circle1.radius < circle2.radius;} );

    std::cout << "\nsorted circles:\n";
    for (const auto& c: circles)
    {
        std::cout <<std::fixed <<std::setprecision(2) << c.center.x <<" "<<c.center.y <<" "<<c.radius <<std::endl;
    }
    
    geometry::Circle myCircle{{0.0, 0.0}, 7.0};

    auto iteratorToFoundCircle = std::lower_bound(circles.begin(), circles.end(), myCircle,  [](const auto& circle1, const auto& circle2){return circle1.radius < circle2.radius;}   );

    std::cout << "\nFound circle:\n";
    std::cout << iteratorToFoundCircle->center.x <<" " << iteratorToFoundCircle->center.y <<" "<< iteratorToFoundCircle->radius <<"\n";



    return EXIT_SUCCESS;
}