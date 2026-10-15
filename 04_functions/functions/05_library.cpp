#include "planet_models.hpp"

#include <iostream>
#include <iomanip>
#include <functional>

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