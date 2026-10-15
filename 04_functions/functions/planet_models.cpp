#include "planet_models.hpp"


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

double squareMetersToHectares(const double squareMeters)
{
    return squareMeters/10000.0;
}

double computeArea(const Region& region, SquareMeters(*areaEstimator)(const Region&))
{
    return areaEstimator(region);
}
