#include <iostream>
#include <complex>

int main ()
{
    auto e{2.7182818f};
    auto i{1};

    const auto j{1};
    auto& iRef{i};

    auto name{"Jan Kowalski"};

    using namespace std::complex_literals;
    const auto pi{std::numbers::pi_v<double>};    
    using Complex = std::complex<double>;
    auto vectorA{3.0 + 1.0i};
    auto vectorB{Complex{3.0 + 1.0i}}; //also works: this is initialization with explicit type 
    auto alpha{pi/4.0};
    auto rotatedVectorA{ std::complex{std::cos(alpha),std::sin(alpha)}*vectorA };

    std::cout << "vectorA = "<< vectorA <<", rotatedVectorA = " << rotatedVectorA << std::endl;
    std::cout << "norm of vectorA = "<< std::sqrt(std::norm(vectorA)) <<", norm of rotatedVectorA = " << std::sqrt(std::norm(rotatedVectorA)) << std::endl;

    return EXIT_SUCCESS;
}

/*
- auto type deduction
- auto type deduciton vs variable type deduction 
- the AAA rule
*/