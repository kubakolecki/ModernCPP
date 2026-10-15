#include "planet.hpp"

#include <iostream>
#include <iomanip>
#include <functional>

int main()
{
    using SqM = planet::SquareMeters;
    
    planet::Region regionNearCracow{19.8, 20.0, 50.0, 50.2};
    planet::Region regionInEthopia{38.7, 38.9, 9.0, 9.2};
    planet::Ellipsoid wgs84{6378137.0, 6356752.314245};
    planet::Ellipsoid grs80{6378137.0, 6356752.314140};
    planet::Ellipsoid hayford{6378388.0, 6356911.946};
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Area near Cracow on sphere: " << planet::squareMetersToHectares(computeAreaOnSphere(regionNearCracow)) << "\n";
    std::cout << "Area in Ethiopia on sphere: " << planet::squareMetersToHectares(computeAreaOnSphere(regionInEthopia)) << "\n";

    planet::AreaEstimator areaEstimatorWGS84{wgs84};
    planet::AreaEstimator areaEstimatorGRS80{grs80};
    planet::AreaEstimator areaEstimatorHayford{hayford};
    std::cout <<"Area near Cracow on WGS84 ellipsoid: "<< planet::squareMetersToHectares(areaEstimatorWGS84(regionNearCracow)) << "\n";
    std::cout <<"Area near Cracow on GRS80 ellipsoid: "<< planet::squareMetersToHectares(areaEstimatorGRS80(regionNearCracow)) << "\n";
    std::cout <<"Area near Cracow on Hayford ellipsoid: "<< planet::squareMetersToHectares(areaEstimatorHayford(regionNearCracow)) << "\n";

    std::cout << std::endl;
    std::cout <<"Area near Cracow on WGS84 ellipsoid: "<< computeArea(regionNearCracow, planet::computeAreaOnSphere) << "\n";

    std::cout << std::endl;
    std::cout <<"Computing using std::function\n"; 
    std::function<SqM(const planet::Region&)> areaEstimator{};
    areaEstimator = areaEstimatorWGS84;
    std::cout <<"Area near Cracow on WGS84 ellipsoid: "<< planet::squareMetersToHectares(areaEstimator(regionNearCracow)) << "\n";
    areaEstimator = planet::computeAreaOnSphere;
    std::cout <<"Area near Cracow on sphere: "<< planet::squareMetersToHectares(areaEstimator(regionNearCracow)) << "\n";

    areaEstimator = [](const planet::Region& region){return (region.latEnd-region.latBegin)*(region.lonEnd-region.lonBegin);};
    std::cout <<"Area near Cracow: "<< areaEstimator(regionNearCracow) <<" [sq deg]" << "\n";

    areaEstimator = [](const auto& region){return (region.latEnd-region.latBegin)*(region.lonEnd-region.lonBegin)/360.0;};
    std::cout <<"Area near Cracow: "<< areaEstimator(regionNearCracow) <<" [sq ']" << "\n";

    return EXIT_SUCCESS;
}