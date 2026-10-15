#pragma once //prevents multiple inclusions of a header within a single translation unit

#include <cmath>

using Degrees = double;
using SquareMeters = double;
using Hectares = double;

struct Ellipsoid
{
    double semiMajorAxis;
    double semiMinorAxis;
};

struct Region
{
    Degrees lonBegin{};
    Degrees lonEnd{};    
    Degrees latBegin{};
    Degrees latEnd{};
};

struct AreaEstimator
{
    Ellipsoid ellipsoid;
    
    SquareMeters operator()(const Region& region)
    {
        const auto rho{57.295779513};
        const auto& [a, b] {ellipsoid};
        const auto e{std::sqrt((a*a - b*b)/(a*a))};
        const auto& [L1, L2, B1, B2]{region};
        const auto sinB1{std::sin(B1/rho)};
        const auto sinB2{std::sin(B2/rho)};
        const auto term1 {sinB2-sinB1};
        const auto term2 {(2.0/3.0)*e*e*(std::pow(sinB2,3.0) - std::pow(sinB1,3.0))};
        const auto term3 {(3.0/5.0)*pow(e,4.0)*(std::pow(sinB2,5.0) - std::pow(sinB1,5.0))};
        const auto deltaL {(L2-L1)/rho};
        const auto area{a*a*(1.0-e*e)*deltaL*(term1 + term2 + term3)};
        return area;
    }
};

SquareMeters computeAreaOnSphere(const Region& region);
double squareMetersToHectares(const double squareMeters); //removed inline
double computeArea(const Region& region, SquareMeters(*areaEstimator)(const Region&));