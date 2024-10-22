// This program has been done 16.09.2024. 
// First version of this was in 18.09.2023

#include "dataTypes.cpp"
#ifndef iostream
#include <iostream>
#endif
#include <vector>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <memory>
#include <fstream>
#include <algorithm>


int numCurves3D; // number of Curves3D
int maxParam; // max value of valuer for parameters

// get numCurves3D and maxParam
void getParam()
{
    std::ifstream fin;
    fin.open("input_param.txt");
    fin >> numCurves3D >> maxParam;
    fin.close();

}

// get numCurves3D from keyboard
void getNumCurves3D()
{
    std::cout << "Enter number of Curves3D" << std::endl;
    std::cin >> numCurves3D;
    std::cout << '\n';
}

// function rerurns random number : 0..n
int randomN(int n)
{
   
    int x = n + 1;
    while ( x > n)
        x = std::rand() % (n + 1);
        //  x = 1 + std::rand() / ((RAND_MAX + 1u) / 6); 

    return x; 
}
// populate a vector of pointers to Curves3D
// solving task # 2
std::vector<std::shared_ptr<Curves3D>> populateCon_1()
{
    std::vector<std::shared_ptr<Curves3D>> v;

    srand(std::time(nullptr));
    for (int n=0; n < numCurves3D; ++n) 
    {
        int x = randomN(2);

        switch (x)
        {
        case 0:
        { 
            std::shared_ptr<Curves3D> pC(new Circle3D(randomN(maxParam),randomN(maxParam),randomN(maxParam)));
            v.push_back(pC);
            break;
        }
        case 1:
        { 
            std::shared_ptr<Curves3D> pE(new Ellipse3D(randomN(maxParam),randomN(maxParam),randomN(maxParam),randomN(maxParam)));
            v.push_back(pE);
            break;
        }
        case 2:
        { 
            std::shared_ptr<Curves3D> pH(new Helix3D(randomN(maxParam), randomN(maxParam)));
            v.push_back(pH);
            break;
        }
        default:
            break;
    }
    }   
    return v;
}

// print data of container vector with parameter t
// solving task # 3
void printCont(const std::vector<std::shared_ptr<Curves3D>> &p_v, double t)
{
     for(auto x: p_v)
     {  
        std::cout << "Curves3D is " ;
        std::cout << typeid(*x).name() << '\n';
        std::cout << "coordinates of Point3D at t= " << t << ':';
         x->getPoint3D(t).showCoordinates();
        std::cout << '\n';
        std::cout << "coordinates of Vector3D at t= " << t << ':';
         x->getDer1(t).showVector();
        std::cout << '\n' << "*********\n";
     }
}

// populate second container with Circle3D
std::vector<std::shared_ptr<Curves3D>>  populateCircle3D(
    const std::vector<std::shared_ptr<Curves3D>> & p_v)
{
    std::vector<std::shared_ptr<Curves3D>> v;
    for(auto x:p_v)
        if( typeid(*x)== typeid(Circle3D))
            v.push_back(x);
    return v;
}

void printRadius(const std::vector<std::shared_ptr<Curves3D>>& p_v)
{
    for(auto x:p_v)
        std::cout << (*x).getRadius() << std::endl;
}

// this function is needed for sort algorithm
bool lessThan(const std::shared_ptr<Curves3D> sp1,
              const std::shared_ptr<Curves3D> sp2)
{
    if(sp1->getRadius() <= sp2->getRadius())
        return true;
    else 
        return false;
}
// calculate all radious in container
double calculateRad(const std::vector<std::shared_ptr<Curves3D>>& p_v)
{
    double sum{0};
    for(auto x: p_v)
        sum += x->getRadius();
    return sum;
}
int main()
{
    // getting number of Curves3D and maxParam from file 
    getParam();

    // # 1, 2 task. Design classes of curves and populate a container
    std::vector<std::shared_ptr<Curves3D>> v = populateCon_1();

    // # 3 task. Print curves3D in a point.
    printCont(v, M_PI/4);
    std::cout << "---------------" << std::endl;
    
    // #4 task. Populate a second container(vector) of Circle3D
    std::vector<std::shared_ptr<Curves3D>> v2 = populateCircle3D(v);

    //Displaying v2 vector
    printCont(v2, M_PI/4);
    std::cout << "---------------" << std::endl;
    
    //Displaying radious of Circle3D in v2
    printRadius(v2);
    std::cout << "---------------" << std::endl;

    // solving task #5. Sort vector by radious of Circle3D
    std::sort(v2.begin(), v2.end(), lessThan);

    //Displaying radious of Circle3D in v2 after sorting
    printRadius(v2);
    std::cout << "---------------" << std::endl;

    // solving task #6
    std::cout << " Sum of all radious in v2 = " << calculateRad(v2) << std::endl;
    std::cout << "---------------" << std::endl;
    
    
    return 0;
}