#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>
#include <ranges>

int main()
{
    std::random_device randomDevice;
    std::mt19937 randomNumberGenerator(randomDevice());
    std::normal_distribution<> distribution(0.0, 1.0);

    const auto numOfSamples{10};
    const auto multiplier{2};

    std::vector<double> normalDistSamples1;
    std::vector<double> normalDistSamples2;
    std::vector<double> normalDistSamples3;
    std::vector<double> normalDistSamples4;

    normalDistSamples1.reserve(numOfSamples);
    for (auto i{0}; i<numOfSamples; ++i)
    {
        normalDistSamples1.push_back(distribution(randomNumberGenerator));
    }

    normalDistSamples2.reserve(numOfSamples);
    std::generate_n(std::back_inserter(normalDistSamples2), numOfSamples, [&distribution, &randomNumberGenerator](){return distribution(randomNumberGenerator);});

    normalDistSamples3.resize(numOfSamples);
    std::generate(normalDistSamples3.begin(), normalDistSamples3.end(), [&distribution, &randomNumberGenerator](){return distribution(randomNumberGenerator);});

    normalDistSamples4.resize(numOfSamples);
    std::ranges::generate(normalDistSamples4, [&distribution, &randomNumberGenerator](){return distribution(randomNumberGenerator);});

    std::cout <<"normalDistSamples3:\n";
    for (const auto& sample: normalDistSamples3)
    {
        std::cout <<sample <<" ";
    }
    std::cout <<std::endl;

    std::cout <<"normalDistSamples4:\n";
    for (const auto& sample: normalDistSamples4)
    {
        std::cout <<sample <<" ";
    }
    std::cout <<std::endl;

    std::vector<double> randomNumbers;
    std::ranges::transform(normalDistSamples4, std::back_inserter(randomNumbers), [m = multiplier](const auto& val){return m*val;});

    std::ranges::sort(randomNumbers, [](const auto& val1, const auto& val2){return std::fabs(val1) < std::fabs(val2);});

    std::cout <<"randomNumbers:\n";
    for (const auto& number: randomNumbers)
    {
        std::cout <<number <<" ";
    }
    std::cout <<std::endl;

    auto filteredNumbers = randomNumbers |
     std::views::filter([](const auto& val){return val > 0;}) |
     std::views::transform([](const auto& val){return std::pow(val, 2.0);}) |
     std::views::reverse |
     std::views::take(2) |
     std::ranges::to<std::vector>();

    std::cout <<"filteredNumbers:\n";
    for (const auto& number: filteredNumbers)
    {
        std::cout <<number <<" ";
    }

    return EXIT_SUCCESS;
}