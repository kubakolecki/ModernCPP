
#include <iostream>
#include <optional>
#include <cmath>

double sum(const double a, const double b);

//double triangleArea(const double distanceA, const double distanceB, const double distanceC); //not ok 
bool triangleArea(const double distanceA, const double distanceB, const double distanceC, double& area); //not quite ok: side effect!
std::pair<bool, double> triangleArea(const double distanceA, const double distanceB, const double distanceC); //ok
std::optional<double> tryComputeTriangleArea(const double distanceA,const double distanceB,const double distanceC); //ok
bool isThisATriangle(const double distanceA, const double distanceB, const double distanceC);


int main()
{
	auto distanceA{ 6.0 };
	auto distanceB{ 4.0 };
	auto distanceC{ 5.0 };

	double area{};
	auto isAreaValid = triangleArea(distanceA, distanceB, distanceC, area);

	const auto computationResult{ triangleArea(distanceA, distanceB, distanceC) };
	std::cout << "is the result valid: " <<std::boolalpha << computationResult.first << ", area = " << computationResult.second << "\n";


	std::cout << "\nlet's test triangleArea\n";
	for (auto delta{ -6.0 }; delta < 12.0; delta += 1.0)
	{
		const auto[status, area] {triangleArea(distanceA, distanceB, distanceC + delta)};
		std::cout <<"delta = " << delta << ", is the result valid: " << std::boolalpha << status << ", area = " << area << "\n";
	}

	std::cout << "\nlet's test tryComputeTriangleArea\n";
	for (auto delta{ -6.0 }; delta < 12.0; delta += 1.0)
	{
		const auto triangleArea = tryComputeTriangleArea(distanceA, distanceB, distanceC + delta);
		std::cout << "delta = " << delta << ", is the result valid: " << std::boolalpha << triangleArea.has_value() << ", area = " << triangleArea.value_or(-99.99) << "\n";
	}


	auto areaComputationSuccessful{ true };
	auto b{ 2.0 };
	while(areaComputationSuccessful)
	{
		const auto triangleArea = tryComputeTriangleArea(distanceA, b, distanceC);
		b += 0.7;
		std::cout << "b = " << b << ", is the result valid: " << std::boolalpha << triangleArea.has_value() << ", area = " << triangleArea.value_or(-99.99) << "\n";
		areaComputationSuccessful = triangleArea.has_value();
	}


	return 0;
}

bool triangleArea(const double distanceA,const double distanceB,const double distanceC, double& area)
{
	const auto areTheDistancesValid = isThisATriangle(distanceA, distanceB, distanceC);
	
	if (!areTheDistancesValid)
	{
		area = 0.0;
		return false;
	}

	//TODO: use here computeHeronsFormula newly implemented function
	const auto perimeter{ distanceA + distanceB + distanceC };
	const auto halfOfPerimeter{ 0.5* perimeter };
	const auto areaSquared = halfOfPerimeter * (halfOfPerimeter - distanceA) * (halfOfPerimeter - distanceB) * (halfOfPerimeter - distanceC);
	area = std::sqrt(areaSquared);
	return true;
}

std::pair<bool, double> triangleArea(const double distanceA, const double distanceB, const double distanceC)
{
	const auto areTheDistancesValid = isThisATriangle(distanceA, distanceB, distanceC);

	if (!areTheDistancesValid)
	{
		return std::make_pair(false, 0.0);
	}
	else
	{
		//TODO: use here computeHeronsFormula newly implemented function
		const auto perimeter{ distanceA + distanceB + distanceC };
		const auto halfOfPerimeter{ 0.5 * perimeter };
		const auto areaSquared = halfOfPerimeter * (halfOfPerimeter - distanceA) * (halfOfPerimeter - distanceB) * (halfOfPerimeter - distanceC);
		return { areTheDistancesValid, std::sqrt(areaSquared) };
	}
}

std::optional<double> tryComputeTriangleArea(const double distanceA, const double distanceB, const double distanceC)
{
	const auto areTheDistancesValid = isThisATriangle(distanceA, distanceB, distanceC);
	
	if (!areTheDistancesValid)
	{
		return std::nullopt;
	}
	else
	{
		//TODO: use here computeHeronsFormula newly implemented function
		const auto perimeter{ distanceA + distanceB + distanceC };
		const auto halfOfPerimeter{ 0.5 * perimeter };
		const auto areaSquared = halfOfPerimeter * (halfOfPerimeter - distanceA) * (halfOfPerimeter - distanceB) * (halfOfPerimeter - distanceC);
		return std::sqrt(areaSquared);
	}

}

bool isThisATriangle(const double distanceA, const double distanceB, const double distanceC)
{
	if (distanceA <= 0.0 || distanceB <= 0.0 || distanceC <= 0.0)
	{
		return false;
	}

	if (distanceA >= distanceB + distanceC || distanceB >= distanceA + distanceC || distanceC >= distanceA + distanceB)
	{
		return false;
	}

	return true;
}


double sum(const double a, const double b)
{
		return a + b;
}

/*SUMMARY:
1. function declaration vs function definition (body)
2. returning from function by 'return'
3. returning from function by non const reference (not recomended)
4. pair (<> as template specification)
5. optional
6. logical operators (||, &&, !)
7. <=, =>, <, > operators
8. if, if-else
9. classical for loop
10. while loop
11. nested functions
12. more on stream manipulations: eg. std::boolalpha for printing 'true'/'false'
*/