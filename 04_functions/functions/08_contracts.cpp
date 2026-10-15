#include <iostream>
#include <optional>
#include <cmath>
#include <contracts>

double tryComputeTriangleArea(const double distanceA,const double distanceB,const double distanceC)
	pre(distanceA > 0)
    pre(distanceB > 0)
    pre(distanceC > 0)
    pre(distanceA < distanceB + distanceC)
    pre(distanceB < distanceA + distanceC)
    pre(distanceC < distanceA + distanceB)
    post(r: r > 0)
; 

void handle_contract_violation(const std::contracts::contract_violation& violation)
{
    std::cerr << "Contract violation: "
              << violation.comment() << '\n';

    std::cerr << "File: "
              << violation.location().file_name() << '\n';

    std::cerr << "Line: "
              << violation.location().line() << '\n';

    //std::contracts::invoke_default_contract_violation_handler(violation);
}

int main()
{
	const auto distanceA{ -6.0 };
	const auto distanceB{ 4.0 };
	const auto distanceC{ 5.0 };

    const auto area{tryComputeTriangleArea(distanceA, distanceB, distanceC)};

    std::cout <<"area = " << area << "\n";

    return EXIT_SUCCESS;

}


double tryComputeTriangleArea(const double distanceA, const double distanceB, const double distanceC)
{
	const auto perimeter{ distanceA + distanceB + distanceC };
	const auto halfOfPerimeter{ 0.5 * perimeter };
	const auto areaSquared = halfOfPerimeter * (halfOfPerimeter - distanceA) * (halfOfPerimeter - distanceB) * (halfOfPerimeter - distanceC);
	return std::sqrt(areaSquared);
	
}