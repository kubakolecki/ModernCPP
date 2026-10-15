#include <iostream>
#include <expected>
#include <string>
#include <cmath>
#include <exception>

enum class ComputationStatus{SUCCESS, NONPOSITIVE_VALUE, TRIANGLE_INEQUALITY_FAILS};
ComputationStatus isThisATriangle(const double distanceA, const double distanceB, const double distanceC);
std::string computationStatusToString(const ComputationStatus computationStatus);
double computeHeronsFormula(const double distanceA, const double distanceB, const double distanceC);
std::pair<double, ComputationStatus> triangleArea(const double distanceA, const double distanceB, const double distanceC);
std::expected<double, ComputationStatus> tryComputeTriangleArea(const double distanceA, const double distanceB, const double distanceC);
//other posibility is to use complex numbers and shift the responsibility to the clients code

int main()
{
    const auto result1{triangleArea(2.5, 5.0, 5.0)};
    const auto result2{triangleArea(2.5, 15.0, 5.0)};
    const auto result3{tryComputeTriangleArea(30.0, 40.0, 50.0)};
    const auto result4{tryComputeTriangleArea(-2.5, 5.0, 5.0)};

    const auto&[area1, status1]{result1};
    const auto&[area2, status2]{result2}; //structrued binding produces more semantic code
    std::cout << "status1 = " << computationStatusToString(status1) <<" area1: " << area1 <<"\n";
    std::cout << "status2 = " << computationStatusToString(status2) <<" area2: " << area2 <<"\n";
    std::cout << std::endl;

    if (result3.has_value())
    {
        std::cout << "computations for triangel 3 are successful, area = " << result3.value() <<"\n";
    }
    else
    {
        std::cout << "computations for triangel 3 failed because " << computationStatusToString(result3.error()) <<"\n";
        //if has_value() is true than behaviur is undefined!
        std::cout << "we assume the area is: " << result3.value_or(0.0) <<"\n";
    }

    if (result4.has_value())
    {
        std::cout << "computations for triangel 4 are successful, area = " << result4.value() <<"\n";
    }
    else
    {
        std::cout << "computations for triangel 4 failed because " << computationStatusToString(result4.error()) <<"\n";
        std::cout << "we assume the area is: " << result4.value_or(0.0) <<"\n";
    }

    // const auto val{result4.value()};
    // std::cout << "this line will not be reached!" << std::endl;

    try
    {
        const auto val{result4.value()};
    }
    catch(const std::exception& e)
    {
        std::cout << "caught exception: " << e.what() << "\n";
    }

    std::cout << "exiting the program\n";
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

std::expected<double, ComputationStatus> tryComputeTriangleArea(const double distanceA, const double distanceB, const double distanceC)
{
    const auto computationStatus{isThisATriangle(distanceA, distanceB, distanceC)};
    if (computationStatus != ComputationStatus::SUCCESS)
    {
        return std::unexpected(computationStatus);
    }
    const auto area{computeHeronsFormula(distanceA, distanceB, distanceC)};
    return area;
}

