#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <exception>

template <typename T>
void printVector(const std::vector<T>& vector)
{
    const auto size{vector.size()};
    for (const auto& val: vector)
    {
        std::cout <<val<<" ";
    }
    std::cout <<std::endl;
}


int main()
{
    std::random_device randomDevice;
    std::mt19937 randomNumberGenerator(randomDevice());
    std::normal_distribution<> distribution(0.0, 1.0);

    std::vector<int> vect1(3, 0);
    std::vector<int> vect2{1, 2};
    std::vector<int> vect3{1, 2, 3, 4};

    std::cout << "vect1: ";
    printVector(vect1);
    std::cout << "vect2: ";
    printVector(vect2);
    std::cout << "vect3: ";
    printVector(vect3);

    std::vector<double> normalDistributionSamples;
    for (auto i{0}; i<10; ++i)
    {
        normalDistributionSamples.push_back(distribution(randomNumberGenerator));
    }

    std::cout << "acessing elements using iterators: " <<std::endl;
    for (auto it = vect3.cbegin(); it != vect3.cend(); it++ )
    {
        auto itPosition{it - vect3.cbegin()};
        std::cout << "iterator at " << itPosition <<" contains "  <<*it <<std::endl;
    }

    std::cout << "normalDistributionSamples: ";
    printVector(normalDistributionSamples);

    std::cout <<"sample with id 2: " << normalDistributionSamples[2] << std::endl;
    std::cout <<"sample with id 2: " << normalDistributionSamples.at(2) << std::endl;

    //out of range access
    //std::cout <<"sample with id 30: " << normalDistributionSamples[30] << std::endl;
    try
    {
        std::cout <<"sample with id 30: " << normalDistributionSamples.at(30) << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Out of range error: " << e.what() << std::endl;
    }


    const auto numOfElements{1'000'000uz}; 
    std::vector<std::pair<double, double>> pairs1;

    const auto startTimeParis1Insertion{std::chrono::high_resolution_clock::now()};
    for (auto i{0}; i<numOfElements; ++i)
    {
        pairs1.push_back(std::make_pair(static_cast<double>(i), 2*static_cast<double>(i)));
    }
    const auto endTimeParis1Insertion{std::chrono::high_resolution_clock::now()};
    const auto durationParis1Insertion{std::chrono::duration_cast<std::chrono::microseconds>(endTimeParis1Insertion - startTimeParis1Insertion).count()};
    std::cout << "Time taken to insert " << numOfElements << " pairs into pairs1: " << durationParis1Insertion << " microseconds" << std::endl;

    std::vector<std::pair<double, double>> pairs2;
    pairs2.reserve(numOfElements);

    const auto startTimeParis2Insertion{std::chrono::high_resolution_clock::now()};
    for (auto i{0}; i<numOfElements; ++i)
    {
        pairs2.push_back(std::make_pair(static_cast<double>(i), 2*static_cast<double>(i)));
    }
    const auto endTimeParis2Insertion{std::chrono::high_resolution_clock::now()};
    const auto durationParis2Insertion{std::chrono::duration_cast<std::chrono::microseconds>(endTimeParis2Insertion - startTimeParis2Insertion).count()};
    std::cout << "Time taken to insert " << numOfElements << " pairs into pairs2: " << durationParis2Insertion << " microseconds" << std::endl;

    return EXIT_SUCCESS;
}