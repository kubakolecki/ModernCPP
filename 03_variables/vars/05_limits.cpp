#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
//#include <chrono>

bool hasQualificationToScholarship(const double yearsAfterPhd);

template <typename T>
void printNumericLimits(const bool useScientificNotation = false)
{
    std::cout << "limits of " << typeid(T).name() << " are: ";
    if (useScientificNotation)
    {
        std::cout << std::scientific << std::setprecision(14);
    }
    std::cout << std::numeric_limits<T>::min() << " <---------------------------> " << std::numeric_limits<T>::max() << "\n";
}

int main()
{
    printNumericLimits<int>();
    printNumericLimits<long>();
    printNumericLimits<long long>();
    printNumericLimits<unsigned int>();
    printNumericLimits<unsigned long long>();
    std::cout << "\n";
    printNumericLimits<float>(true);
    printNumericLimits<double>(true);
    printNumericLimits<long double>(true);
    std::cout << "\n";

    float myBudgetYesterday{5'000'000'003.0f }; //NO WARNING!
    float myBudgetToday{5'000'000'107.0f }; //NO WARNING!
    float myDailyIncome = myBudgetToday - myBudgetYesterday;
    std::cout << "myDailyIncome: " << myDailyIncome << "\n";
    std::cout << "is my todays income zero?:  " << std::boolalpha << (myDailyIncome == 0.0f) <<"\n"; 


    // std::cout << "testing float precision:\n";
    // auto e{ 2.71828182846f };
    // for (auto w{ 0 }; w < 500; w++)
    // {
    //     e *= 2.71828182846f;
    //     std::cout<<"w: "<<std::setw(6) << w <<"  "<< std::fixed << std::setprecision(40) << e << "\n";
    //     if (isinf(e))
    //     {
    //         break;
    //     }
    // }

    std::cout << std::setprecision(17);
    std::cout << std::fixed;
    std::cout << "\n";
    std::cout << "std::nextafter(5.0f, 10.0f): " << std::nextafter(5.0f, 10.0f) << "\n";
    std::cout << "std::nextafter(5'000.0f, 10'000.0f): " << std::nextafter(5'000.0f, 10'000.0f) << "\n";
    std::cout << "std::nextafter(5'000'000.0f, 10'000'000.0f): " << std::nextafter(5'000'000.0f, 10'000'000.0f) << "\n";
    std::cout << "std::nextafter(500'000'000.0f, 1'000'000'000.0f): " << std::nextafter(500'000'000.0f, 1'000'000'000.0f) << "\n";
    std::cout << "\n";
    std::cout << "std::nextafter(5.0, 10.0): " << std::nextafter(5.0, 10.0) << "\n";
    std::cout << "std::nextafter(5'000.0, 10'000.0): " << std::nextafter(5'000.0, 10'000.0) << "\n";
    std::cout << "std::nextafter(500'000.0, 1'000'000.0): " << std::nextafter(500'000.0, 1'000'000.0) << "\n";
    std::cout << "std::nextafter(500'000'000.0, 1'000'000'000.0): " << std::nextafter(500'000'000.0, 1'000'000'000.0) << "\n";
    std::cout << "\n";


    float f{};
    double d{};
    int i{};
    long long int lli{};

    f = d; //WARNING
    d = f; //promotion

    i = lli; //WARNING
    lli = i; //promotion

    f = i; //WARNING
    d = i; //promotion

    i = f; //WARNING
    lli = d; //WARNING
    
    //let's use static_cast

    f = static_cast<float>(d);
    d = static_cast<double>(f);

    i = static_cast<int>(lli);
    lli = static_cast<long long int>(i);

    f = static_cast<float>(i);
    d = static_cast<double>(i);

    i = static_cast<int>(f);
    lli = static_cast<long long int>(d);

    auto evaluationResult{ false };

    evaluationResult = hasQualificationToScholarship(4.0f); //conversion
    std::cout << "can scholarship be granted: " << std::boolalpha << evaluationResult << "\n";
    evaluationResult = hasQualificationToScholarship(10); //conversion
    std::cout << "can scholarship be granted: " << std::boolalpha << evaluationResult << "\n";

    //WHY unsigned types are not very safe?
    unsigned int yaerOfPhdGarduation{ 2021 };
    unsigned int yearOfAppliation{ 2026 };
    evaluationResult = hasQualificationToScholarship(std::fabs(yaerOfPhdGarduation - yearOfAppliation)); //NO WARNING!
    std::cout << "can scholarship be granted: " << std::boolalpha << evaluationResult << "\n";

    // std::cout << "\n";
    // for (auto someIntNumber{ 0 }; someIntNumber < 256; ++someIntNumber)
    // {
    //     std::cout << std::setw(6)<< someIntNumber << "--->" << static_cast<unsigned char>(someIntNumber) << "<---\n";
    // }
    // std::cout << "\n";

    // const std::string someString = "Hello World!";
    // std::cout << "Converting " << someString << " to integeres:\n";
    // for (const auto& character : someString)
    // {
    //     std::cout << static_cast<int>(character);
    // }
    // std::cout << "\n";
   

}

bool hasQualificationToScholarship(const double yearsAfterPhd)
{
    if (yearsAfterPhd > 7.0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*SUMMARY:
1. std::numeric_limits
2. narrowing conversions
3. conversions by promotion
5. static_cast
6. integer overflow
7. 'char' as numeric type
*/