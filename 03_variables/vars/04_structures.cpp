#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <numbers> //C++20!

using namespace std::string_literals;

struct CameraSensor
{
    std::string name{};
    int widthInPixels{6000};
    int heightInPixels{4000};
    double pixelSizeInMilimeters{0.00549};
};

struct Lens
{
    std::string name{};
    double focalLengthInMilimeters{20.0};
};

struct Camera
{
    CameraSensor cameraSensor{};
    Lens lens{}; // try with const Lens& lens;
};

 
int main()
{
    CameraSensor myCameraSensor1{"NikonD850"s, 8256,  5504, 0.004342}; //narrowing conversion fails compilation!
    CameraSensor myCameraSensor2("NikonD7500"s, 5568 , 3712.2, 0.002205); //narrowing conversion passes compilation!
    Lens myLens1{"Nikkor50mm"s, 50.0};
    Lens myLens2{"Nikkor35mm"s, 35.0};
    //consider declaring all the above objects as const
    auto myCamera1{Camera{myCameraSensor1, myLens1}};
    
    const auto [name1, W1, H1, pix1 ]{myCameraSensor1}; //structured binding
    
    

    std::cout <<"sensor dimensions of: " <<myCameraSensor1.name <<" are " <<std::fixed << std::setprecision(6) <<myCameraSensor1.widthInPixels*myCameraSensor1.pixelSizeInMilimeters << " X " << myCameraSensor1.heightInPixels*myCameraSensor1.pixelSizeInMilimeters << "[mm]\n";
    std::cout <<"sensor dimensions of: " <<name1 <<" are " <<std::fixed << std::setprecision(6) <<W1 * pix1 << " X " << H1 * pix1 << "[mm]\n";

    auto fov = 2*std::atan(myCamera1.cameraSensor.widthInPixels*myCamera1.cameraSensor.pixelSizeInMilimeters / myCamera1.lens.focalLengthInMilimeters); //field of view
    std::cout <<"field of view of my camera is " << fov * 180.0 / std::numbers::pi_v<double> << " [deg]\n";
    
    auto&[camSensor, lens]{myCamera1}; //what if make this const auto?
    lens = myLens2;

    fov = 2*std::atan(myCamera1.cameraSensor.widthInPixels*myCamera1.cameraSensor.pixelSizeInMilimeters / myCamera1.lens.focalLengthInMilimeters); //field of view
    std::cout <<"field of view of my camera is " << fov * 180.0 / std::numbers::pi_v<double> << " [deg]\n";


    std::cout << "sizeof(Camera) = " << sizeof(Camera) << "\n"; 



    return EXIT_SUCCESS;
}