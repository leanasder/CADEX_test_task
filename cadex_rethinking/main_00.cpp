#include "dataTypes.cpp"
#ifndef iostream
#include <iostream>
#endif
#include <vector>
#include <cstdlib>
#include <ctime>
#include <typeinfo>


const int numCurves3D = 20;
const int numParam = 10;

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
std::vector<Curves3D*> populateCon_1()
{
    std::vector<Curves3D*> v;

    srand(std::time(nullptr));
    for (int n=0; n < numCurves3D; ++n) 
    {
        int x = randomN(2);

        switch (x)
        {
        case 0:
        { 
            Curves3D* pC = new Circle3D(randomN(numParam),randomN(numParam),randomN(numParam));
            v.push_back(pC);
            break;
        }
        case 1:
        { 
            Curves3D* pE = new Ellipse3D(randomN(numParam),randomN(numParam),randomN(numParam),randomN(numParam));
            v.push_back(pE);
            break;
        }
        case 2:
        { 
            Curves3D* pH = new Helix3D(randomN(numParam), randomN(numParam));
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
void printCont(std::vector<Curves3D*> p_v, double t)
{
     for(int i = 0; i < p_v.size(); i++ )
     {  
        std::cout << "Curves3D is " ;
        std::cout << typeid(*p_v[i]).name() << '\n';
        std::cout << "coordinates of Point3D: ";
         p_v[i]->getPoint3D(t).showCoordinates();
        std::cout << '\n';
        std::cout << "coordinates of Vector3D: ";
         p_v[i]->getDer1(t).showVector();
        std::cout << '\n';
     }
}

int main()
{
    std::vector<Curves3D*> v = populateCon_1();
    printCont(v, M_PI/4);
    std::cout << "\n";
    
    return 0;
}