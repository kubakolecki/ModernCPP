
#include <iostream>
#include <cmath>

int main()
{
    //Variable, type, ways to initialize

    int a = 7;
    int b;
    int c(2);
    int d{10}; //thera are 3 differences wrt () initilization
    int e{};
    int n;
    //int f();
    

    std::cout <<"a = " << a << "\n";
    std::cout <<"b = " << b << "\n";
    std::cout <<"c = " << c << "\n";
    std::cout <<"d = " << d << std::endl;
    std::cout <<"e = " << e << std::endl;
    std::cout <<"n = " << n << std::endl;
    //std::cout <<"f = " << f << std::endl; //this is a function declaration!
    //std::cout.flush();

    float pi{3.1415f}; //Explicit literal
    double alphaInDegrees{45.0};
    double alphaInRadians{alphaInDegrees*pi/180.0}; //Initialization with expression
    double betaInDegrees{105.5};
    double betaInRadians {betaInDegrees*pi/180.0};
    betaInRadians = alphaInRadians; //asingment
    //f = 7;

    int etaInDegrees{alphaInDegrees + betaInDegrees}; //narrowing conversion

    std::cout << "alphaInRadians = " << alphaInRadians << "\n";
    std::cout << "betaInRadians = " << betaInRadians << "\n";
    std::cout << "etaInDegrees = " << etaInDegrees << "\n";

    using Degrees = double;
    using Radians = double;
    const double deg2Rad{pi/180.0};  //const variable! Thre is also constexpr but we will come to this later
    
    Degrees theta{75};
    const bool isInFirstQuarter { std::sin(theta*deg2Rad) > 0 && std::cos(theta*deg2Rad) > 0 };

    std::cout << "sinus theta = " <<std::sin(theta*deg2Rad) << "\n";
    std::cout << "theta is in first quarter: " <<  isInFirstQuarter << "\n"; //havnt used boolalpha yet

    //deg2Rad = 12.0; //does not compile!

    enum class Season {WINTER, SPRING, SUMMER, AUTUMN };

    enum class Zodiac
    {
        ARIES=1, TAURUS, GEMINI, //why used 1?
        CANCER, LEO, VIRGO,
        LIBRA, SCORPIO, SAGITTARIUS,
        CAPRICORN, AQUARIUS, PISCES
    };

    Zodiac myZodiac{Zodiac::ARIES};

    //std::cout << myZodiac <<"\n"; //this does not compile!
    const Season currentSeason {Season::AUTUMN};
    bool isAutumn{Season::AUTUMN == currentSeason};
    bool isColdSeason{Season::AUTUMN == currentSeason || Season::WINTER == currentSeason};

    std::cout << "is my zodiak ARIES: " << (myZodiac == Zodiac::ARIES) <<"\n";
    std::cout << "is my zodiak SAGITARIUS: " << (myZodiac == Zodiac::SAGITTARIUS) <<"\n";
    std::cout << "is my zodiak ARIES: " << std::boolalpha << (myZodiac == Zodiac::ARIES) <<"\n";
    std::cout << "is my zodiak SAGITARIUS: " << std::boolalpha << (myZodiac == Zodiac::SAGITTARIUS) <<"\n";

    return EXIT_SUCCESS;
}

/*
- C++ is a strongly typed languge
- main funciton
- inlude directives
- using ;
- Types of variable initializaton
- literals
- most vaxing phrase
- assingment vs initialization
- hot to get a type (hoover coursor over variable)
- narrowing conversion
- const specifier
- type aliases
- bool type
- logical operators &&, ||, ==
- printing variables
- difference between "\n" and std::endl
- scoped enum vaviables
- cmath

*/