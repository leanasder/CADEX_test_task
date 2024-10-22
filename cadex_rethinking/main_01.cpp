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
void printCont(std::vector<std::shared_ptr<Curves3D>> p_v, double t)
{
     for(int i = 0; i < p_v.size(); i++ )
     {  
        std::cout << "Curves3D is " ;
        std::cout << typeid(*p_v[i]).name() << '\n';
        std::cout << "coordinates of Point3D at t= " << t << ':';
         p_v[i]->getPoint3D(t).showCoordinates();
        std::cout << '\n';
        std::cout << "coordinates of Vector3D at t= " << t << ':';
         p_v[i]->getDer1(t).showVector();
        std::cout << '\n' << "*********\n";
     }
}

int main()
{
    
    getParam();

    // # 1, 2 task
    std::vector<std::shared_ptr<Curves3D>> v = populateCon_1();
    // # 3 task
    printCont(v, M_PI/4);

    std::cout << "\n";
    
    return 0;
}