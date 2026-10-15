#include <iostream>
#include <string>
#include <cmath>
#include <exception>

enum class ComputationStatus{SUCCESS, NONPOSITIVE_VALUE, TRIANGLE_INEQUALITY_FAILS};
ComputationStatus isThisATriangle(const double distanceA, const double distanceB, const double distanceC);
std::string computationStatusToString(const ComputationStatus computationStatus);
double computeHeronsFormula(const double distanceA, const double distanceB, const double distanceC);
std::pair<double, ComputationStatus> triangleArea(const double distanceA, const double distanceB, const double distanceC);

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <distanceA> <distanceB> <distanceC>\n";
        return EXIT_FAILURE;
    }

    try
    {
        const auto distanceA{ std::stod(argv[1]) };
        const auto distanceB{ std::stod(argv[2]) };
        const auto distanceC{ std::stod(argv[3]) };
        const auto[area, computationStatus] = triangleArea(distanceA, distanceB, distanceC);
        std::cout << "computation status: " << computationStatusToString(computationStatus) << ", area = " << area << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << "program ended with exception: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


std::string computationStatusToString(const ComputationStatus computationStatus)
{
    switch (computationStatus)
    {
        case ComputationStatus::SUCCESS:
            return "SUCCESS";
        case ComputationStatus::NONPOSITIVE_VALUE:
            return "NONPOSITIVE_VALUE";
        case ComputationStatus::TRIANGLE_INEQUALITY_FAILS:
            return "TRIANGLE_INEQUALITY_FAILS";
        default:
            return "UNKNOWN_STATUS";
    }
}

ComputationStatus isThisATriangle(const double distanceA, const double distanceB, const double distanceC)
{
	if (distanceA <= 0.0 || distanceB <= 0.0 || distanceC <= 0.0)
	{
		return ComputationStatus::NONPOSITIVE_VALUE;
	}

	if (distanceA >= distanceB + distanceC || distanceB >= distanceA + distanceC || distanceC >= distanceA + distanceB)
	{
		return ComputationStatus::TRIANGLE_INEQUALITY_FAILS;
	}

	return ComputationStatus::SUCCESS;
}

double computeHeronsFormula(const double distanceA, const double distanceB, const double distanceC)
{
    const auto perimeter{ distanceA + distanceB + distanceC };
    const auto halfOfPerimeter{ 0.5 * perimeter };
    const auto areaSquared = halfOfPerimeter * (halfOfPerimeter - distanceA) * (halfOfPerimeter - distanceB) * (halfOfPerimeter - distanceC);
    return std::sqrt(areaSquared);
}

std::pair<double, ComputationStatus> triangleArea(const double distanceA, const double distanceB, const double distanceC)
{
	const auto computationStatus{isThisATriangle(distanceA, distanceB, distanceC)};
	if (computationStatus != ComputationStatus::SUCCESS)
	{
		return { 0.0, computationStatus};
	}
	const auto area{computeHeronsFormula(distanceA, distanceB, distanceC)};
	return {area, computationStatus};  //RVO
}