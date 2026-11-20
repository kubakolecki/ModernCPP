#include <iostream>
#include <string>
#include <iomanip> //for stream manipulators with parameters (like std::setprecision)
#include <cmath>
#include <numbers> //to get PI, available from C++20!

using namespace std::string_literals;

struct CameraSensor
{
    std::string name{};
    int widthInPixels{6000};
    int heightInPixels{4000};
    double pixelSizeInMilimeters{0.00549};
}; //observe that we need a semicolon here

struct Lens
{
    std::string name{};
    double focalLengthInMilimeters{20.0};
};

//of course we can nest structures
struct Camera
{
    CameraSensor cameraSensor{};
    Lens lens{};
};

 
int main()
{
    CameraSensor myCameraSensor1{"NikonD850"s, 8256,  5504, 0.004342}; //brace initialization: narrowing conversion fails compilation!
    CameraSensor myCameraSensor2("NikonD7500"s, 5568 , 3712.2, 0.002205); //narrowing conversion passes compilation!
    Lens myLens1{"Nikkor50mm"s, 50.0};
    Lens myLens2{"Nikkor35mm"s, 35.0};
    //consider declaring all the above objects as const
    
    auto myCamera1{Camera{myCameraSensor1, myLens1}}; //explicit type initialization
    
    const auto [name1, W1, H1, pix1 ]{myCameraSensor1}; //structured binding
    
    std::cout <<"sensor dimensions of: " <<myCameraSensor1.name <<" are " <<std::fixed << std::setprecision(6) <<myCameraSensor1.widthInPixels*myCameraSensor1.pixelSizeInMilimeters << " X " << myCameraSensor1.heightInPixels*myCameraSensor1.pixelSizeInMilimeters << "[mm]\n";
    std::cout <<"sensor dimensions of: " <<name1 <<" are " <<std::fixed << std::setprecision(6) <<W1 * pix1 << " X " << H1 * pix1 << "[mm]\n";

    auto fov = 2*std::atan(0.5*myCamera1.cameraSensor.widthInPixels*myCamera1.cameraSensor.pixelSizeInMilimeters / myCamera1.lens.focalLengthInMilimeters); //field of view
    std::cout <<"field of view of my camera is " << fov * 180.0 / std::numbers::pi_v<double> << " [deg]\n";
    
    //does thos structured binding below involves copying: 
    auto&[camSensor, lens]{myCamera1}; //what would happen if make this const auto?
    lens = myLens2; //I'm changing the lens in myCamera1

    //the new lens should provide a wider field of view:
    //(btw - we could write a member funtion or free fucntion for computing a field of viwe)
    fov = 2*std::atan(0.5*myCamera1.cameraSensor.widthInPixels*myCamera1.cameraSensor.pixelSizeInMilimeters / myCamera1.lens.focalLengthInMilimeters); //field of view
    std::cout <<"field of view of my camera is " << fov * 180.0 / std::numbers::pi_v<double> << " [deg]\n";

    std::cout << "sizeof(Camera) = " << sizeof(Camera) << "\n"; 

    return EXIT_SUCCESS;
}

//summary:
// 1. definition of structure: member variables of structure
// 2. nested structures (composition of structures)
// 3. brace initializaton of objects of custom types
// 4. difference between brace initialization and brackets initialization of object of custom types
// 5. using auto or const auto when declaring object of custom types
// 6. acessing member variables via structure reference operator "." (a dot)
// 7. "unpacking" the object of custom type using structrured binding
// 8. Using structured binding along with auto
// 9. Using structured binding along with const keyword
// 10. Reference semantics (&) vs value semantics in structure binding
// 11. The sizeof operator: compile-time computation of object size