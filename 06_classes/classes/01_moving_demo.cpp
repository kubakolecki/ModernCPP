#include <iostream>

struct Point2D
{
    double x{};
    double y{};
};

int main()
{
    
    auto A{Point2D{}}; //default construction
    auto B{Point2D{3.0, -3.0}}; //non-default construction
    auto C{Point2D{-9.0, 2.0}}; //non-default construction
    auto D{B}; //copy construction
    D = C; //copy assignment operation

    std::cout <<"A: "<< A.x <<" "<<A.y <<std::endl;
    std::cout <<"B: "<< B.x <<" "<<B.y <<std::endl;
    std::cout <<"C: "<< C.x <<" "<<C.y <<std::endl;
    std::cout <<"D: "<< D.x <<" "<<D.y <<std::endl;

    //concept of moving the object:
    D = std::move(B); //move operation!

    //The ovnership of the memmory associated with the object B is transferred to the object D.
    //The object B is left in a valid but unspecified state.

    std::cout <<std::endl <<"after moving B" <<std::endl;
    std::cout <<"A: "<< A.x <<" "<<A.y <<std::endl;
    std::cout <<"B: "<< B.x <<" "<<B.y <<std::endl;
    std::cout <<"C: "<< C.x <<" "<<C.y <<std::endl;
    std::cout <<"D: "<< D.x <<" "<<D.y <<std::endl;

    auto E{std::move(C)}; //move construction!
    //now the object C is in a valid but unspecified state



    //desctuction of the objects A, B, C, D, E will be called automatically at the end of the scope
    return EXIT_SUCCESS;
}


//We now have a notion of following operations:
//1. default construction
//2. non-default construction
//3. copy construction
//4. copy assignment operation
//5. move assignment operation
//6. move construction
