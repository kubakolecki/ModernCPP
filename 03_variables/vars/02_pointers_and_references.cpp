
#include <iostream>
#include <cmath>
#include <complex>
#include <numbers> //C++20!

int main()
{
    //************************************ POINTERS ************************************//
    double price{199.00};
    double *pricePtr; //pointer (don't do this!)
    pricePtr = &price; //assignment
    
    double taxRate{0.23};
    double *taxRatePtr{&taxRate}; //better than above

    std::cout <<"The price is: " << price <<" which is the same as " <<*pricePtr <<"\n";
    std::cout <<"The price variable is stored at: " <<pricePtr << "\n";
    std::cout <<"Netto price is: " << (1.0 - *taxRatePtr)**pricePtr << "\n";

    float* velocityPtr;
    //std::cout <<"velocity: " <<*velocityPtr <<"\n"; //undefined behavour! Prints random address or can crash the app!
    
    float* timePtr{nullptr}; //better
    //std::cout <<"velocity: " <<*timePtr <<"\n";

    //*velocityPtr = 25.0f; //can crash the app!

    //************************************ REFERENCES ************************************//
    std::cout <<"\n\n";
    using namespace std::complex_literals;
    const double pi{std::numbers::pi_v<double>};    
    using Complex = std::complex<double>;
    Complex vectorA{3.0 + 1.0i};
    double alpha{pi/4.0};
    Complex rotatedVectorA{ std::complex{std::cos(alpha),std::sin(alpha)}*vectorA };

    std::cout << "vectorA = "<< vectorA <<", rotatedVectorA = " << rotatedVectorA << std::endl;
    std::cout << "norm of vectorA = "<< std::sqrt(std::norm(vectorA)) <<", norm of rotatedVectorA = " << std::sqrt(std::norm(rotatedVectorA)) << std::endl;

    Complex& vectorB{vectorA}; //reference to vectorA
    vectorB.imag(-1.0);
    std::cout << "vectorA = "<< vectorA <<", vectorB = " << vectorB << std::endl;

    const Complex vectorC{3.0 + 1.0i};
    //Vector& vectorD{vectorC}; //does not compile
    const Complex& vectorD{vectorC};
    std::cout <<std::boolalpha << (vectorC == vectorD) << std::endl;

    // Vector& vectorE; //does not compile

    return EXIT_SUCCESS;
}