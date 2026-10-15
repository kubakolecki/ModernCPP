#include <cmath>
#include <iostream>
#include <iomanip>
#include <functional>

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
inline double squareMetersToHectares(const double squareMeters);
double computeArea(const Region& region, SquareMeters(*areaEstimator)(const Region&));

int main()
{
    Region regionNearCracow{19.8, 20.0, 50.0, 50.2};
    Region regionInEthopia{38.7, 38.9, 9.0, 9.2};
    Ellipsoid wgs84{6378137.0, 6356752.314245};
    Ellipsoid grs80{6378137.0, 6356752.314140};
    Ellipsoid hayford{6378388.0, 6356911.946};
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Area near Cracow on sphere: " << squareMetersToHectares(computeAreaOnSphere(regionNearCracow)) << "\n";
    std::cout << "Area in Ethiopia on sphere: " << squareMetersToHectares(computeAreaOnSphere(regionInEthopia)) << "\n";

    AreaEstimator areaEstimatorWGS84{wgs84};
    AreaEstimator areaEstimatorGRS80{grs80};
    AreaEstimator areaEstimatorHayford{hayford};
    std::cout <<"Area near Cracow on WGS84 ellipsoid: "<< squareMetersToHectares(areaEstimatorWGS84(regionNearCracow)) << "\n";
    std::cout <<"Area near Cracow on GRS80 ellipsoid: "<< squareMetersToHectares(areaEstimatorGRS80(regionNearCracow)) << "\n";
    std::cout <<"Area near Cracow on Hayford ellipsoid: "<< squareMetersToHectares(areaEstimatorHayford(regionNearCracow)) << "\n";

    std::cout << std::endl;
    std::cout <<"Area near Cracow on WGS84 ellipsoid: "<< computeArea(regionNearCracow, computeAreaOnSphere) << "\n";

    std::cout << std::endl;
    std::cout <<"Computing using std::function\n"; 
    std::function<SquareMeters(const Region&)> areaEstimator{};
    areaEstimator = areaEstimatorWGS84;
    std::cout <<"Area near Cracow on WGS84 ellipsoid: "<< squareMetersToHectares(areaEstimator(regionNearCracow)) << "\n";
    areaEstimator = computeAreaOnSphere;
    std::cout <<"Area near Cracow on sphere: "<< squareMetersToHectares(areaEstimator(regionNearCracow)) << "\n";

    areaEstimator = [](const Region& region){return (region.latEnd-region.latBegin)*(region.lonEnd-region.lonBegin);};
    std::cout <<"Area near Cracow: "<< areaEstimator(regionNearCracow) <<" [sq deg]" << "\n";

    areaEstimator = [](const auto& region){return (region.latEnd-region.latBegin)*(region.lonEnd-region.lonBegin)/360.0;};
    std::cout <<"Area near Cracow: "<< areaEstimator(regionNearCracow) <<" [sq ']" << "\n";

    return EXIT_SUCCESS;
}

SquareMeters computeAreaOnSphere(const Region& region)
{
    const auto rho{57.295779513};
    const auto earthRadius{6.37814e+06};
    const auto& [L1, L2, B1, B2]{region};
    const auto deltaL{(L2-L1)/rho};
    const auto sinB1{std::sin(B1/rho)};
    const auto sinB2{std::sin(B2/rho)};
    const auto area{earthRadius*earthRadius*deltaL*(sinB2-sinB1)};
    return area;
}

inline double squareMetersToHectares(const double squareMeters)
{
    return squareMeters/10000.0;
}

double computeArea(const Region& region, SquareMeters(*areaEstimator)(const Region&))
{
    return areaEstimator(region);
}
