#include "dataTypes.cpp"
#ifndef iostream
#include <iostream>
#endif
#include <vector>
#include <cstdlib>
#include <ctime>
#include <typeinfo>


const int numCurves3D = 20;

// populate a vector of pointers to Curves3D
std::vector<Curves3D*> populateCon_1()
{
    std::vector<Curves3D*> v;

    srand(std::time(nullptr));
    for (int n=0; n < numCurves3D; ++n) 
    {
        int x = 3;
        while( x > 2)
            //  x = 1 + std::rand() / ((RAND_MAX + 1u) / 6); 
            x =  std::rand() % 3;

        switch (x)
        {
        case 0:
        { 
            Curves3D* pC = new Circle3D(1,1,2);
            v.push_back(pC);
            break;
        }
        case 1:
        { 
            Curves3D* pE = new Ellipse3D(1,1,3,4);
            v.push_back(pE);
            break;
        }
        case 2:
        { 
            Curves3D* pH = new Helix3D(2, 3.14);
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
    double kkk;
    std::cout << typeid(kkk).name() << '\n';

    return 0;
}