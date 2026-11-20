#include <iostream>
#include <random>
#include <array>

int getRandomNumber()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}


int main()
{
    int diceNumbers[6]{1, 2, 3, 4, 5, 6}; //Aggregate initialization

    double someNumbers[4];

    std::cout << "diceNumbers[3] = " << diceNumbers[3] <<"\n";
    std::cout << "diceNumbers[10] = " << diceNumbers[10] <<"\n"; //undefined
    std::cout << "someNumbers[0] = " << someNumbers[0] <<"\n";  //undefined

    for (auto i{0}; i<4; i++)
    {
        someNumbers[i] = static_cast<double>(i);
    }

    std::cout << "someNumbers[1] = " << someNumbers[0] <<"\n";  //undefined


    enum class Seasons{WINTER, SPRING, SUMMER, AUTUMN};
    
    //VLAs are not part of standard C++
    //The code below does not compie. If we enable VLAs this code will compie!
    /*
    int numberOfSeasons{4};
    Seasons seasons[numberOfSeasons]{Seasons::WINTER, Seasons::SPRING, Seasons::SUMMER, Seasons::AUTUMN};

    int randomArray[getRandomNumber()];
    */

    constexpr int numberOfSeasons{4};
    Seasons seasons[numberOfSeasons]{Seasons::WINTER, Seasons::SPRING, Seasons::SUMMER, Seasons::AUTUMN};

    //pre C++11 to have it in a semmantic fashion:
    #define NUM_OF_SEASONS 4
    Seasons seasonsOfAYear[NUM_OF_SEASONS]{Seasons::WINTER, Seasons::SPRING, Seasons::SUMMER, Seasons::AUTUMN};

    //Dynamic arrays with old-fashioned memmory allocaiton

    const auto randomSize{getRandomNumber()};
    double * arrayOfRandomSize;
    arrayOfRandomSize = new double[randomSize]; //we can combine theses two linse in a single line
    
    //do something with this array

    delete[] arrayOfRandomSize; //we have to remember to free the memmory with delte[]
    arrayOfRandomSize = nullptr; //we have to remember to set the pointer to nullptr after freeing the memmory


    //Modern C++ Arrays

    std::array<int, 6> dice{1, 2, 3, 4, 5, 6};
    std::cout << "dice has " <<dice.size() << " sides";

    //Range based for loops:
    std::cout << "the numbers: ";
    for (const auto number: dice)
    {
        std::cout << number <<" ";
    }
    std::cout <<std::endl;

    for (auto& number: dice)
    {
        number = dice.size() - number + 1;
    }

    std::cout << "the numbers: ";
    for (const auto number: dice)
    {
        std::cout << number <<" ";
    }

    std::cout <<std::endl;

    std::array<double, 3> myArray{};
    std::cout << "elements in my array: ";
    for (const auto element: myArray)
    {
        std::cout << element <<" ";
    }
    std::cout <<std::endl;

   
    return EXIT_SUCCESS;
}