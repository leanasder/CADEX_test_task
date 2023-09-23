#include <iostream>
#include <math.h>
using namespace std;
#include "dataTypes.h"
#include <vector>
#include <algorithm>

// populate a vector of pointers to Curves3D
// entering data from standart i/o stream
// outcome: required vector
vector<Curves3D*> populateCont1()
{
    cout << "Enter Curves, please : " << endl
         << "Enter required digits: " << endl
         << " 1 - Circle, 2 - Ellipse, 3 -Helix "<< endl
         << "Ctl+D - terminate entering"<< endl;

    vector<Curves3D*> v;
    unsigned int digit;

    while(cin >> digit)
        switch(digit)
        {
        case 1:
        {
            cout << "Please, enter X_center, Y_Center, Radius of circle in double values" << endl;
            double x_center, y_center, radius;
            cin >> x_center >> y_center >> radius;
            if(radius > 0){
                Curves3D* pC = new Circle(x_center, y_center, radius);
                v.push_back(pC);
            }
            else
                cout << "Wrong parameter, please check it and try again!" << endl;

            cout << "**************" << endl;
            cout << "Enter Curves, please : " << endl
            << "Enter required digits: " << endl
            << " 1 - Circle, 2 - Ellipse, 3 -Helix "<< endl
            << "Ctl+D - terminate entering"<< endl;
        }
        break;
        case 2:
        {
            cout << "Please, enter X_center, Y_Center, Rad_a, Rad_b of ellipse in double values" << endl;
            double x_center, y_center, rad_a, rad_b;
            cin >> x_center >> y_center >> rad_a >> rad_b;
            if(rad_a > 0 && rad_b > 0)
            {
                Curves3D* pE = new Ellipse3D(x_center, y_center, rad_a, rad_b);
                v.push_back(pE);
            }
            else
                 cout << "Wrong parameter, please check it and try again!" << endl;

            cout << "**************" << endl;
            cout << "Enter Curves, please : " << endl
            << "Enter required digits: " << endl
            << " 1 - Circle, 2 - Ellipse, 3 -Helix "<< endl
            << "Ctl+D - terminate entering"<< endl;
         }
        break;
        case 3:
        {
            cout << "Please, enter X_center, Y_Center, Z, Radius of helix in double values" << endl;
            double x_center, y_center, z, radius;
            cin >> x_center >> y_center >> z >> radius;
            if(radius > 0)
            {
               Curves3D* pH = new Helix3D(x_center, y_center, z, radius);
                v.push_back(pH);
            }
            else
                cout << "Wrong parameter, please check it and try again!" << endl;

            cout << "**************" << endl;
            cout << "Enter Curves, please : " << endl
            << "Enter required digits: " << endl
            << " 1 - Circle, 2 - Ellipse, 3 -Helix "<< endl
            << "Ctl+D - terminate entering"<< endl;
        }
        break;
    default:
        cout << "**************" << endl;
        cout <<" You've entered unaccurate character! Please, try again! " << endl;
        cout << "**************" << endl;

        break;
    }
    return v;
}
// print data of container vector with parameter t
void printCont(vector<Curves3D*> p_v, double t)
{
     for(int i = 0; i < p_v.size(); i++ )
     {
         p_v[i]->getPoint(t).showCoordinates();
         p_v[i]->getDer1(t).showVector();
     }
}
// populate container 2, which have only data type - Circle
vector<Curves3D*> populateCont2(vector<Curves3D*> p_v)
{
     vector<Curves3D*> v2;
     for(int i = 0; i < p_v.size(); i++ )
     {
        if (p_v[i]->getType() == 1)
            v2.push_back(p_v[i]);
     }

      return v2;
}
// this function is required for sorting vector by radius of curve Circle
bool LessRadiusThen(Curves3D* c1, Curves3D* c2)
{
    if(c1->getRadius() < c2->getRadius())
        return true;
    else
        return false;
}
// compute all radius of curves Circle
double ComputeAllRadius(vector<Curves3D*> v)
{
    double sum = 0;
    for(long unsigned int i = 0; i < v.size(); i++)
        sum += v[i]->getRadius();

    return sum;
}
// memory deallocation. Clean vector.
// in requirements is writed: don't use explicit memory deallocation, but i don't know
// how  do it.
// Therefore i do how i can.
void clearVector(vector<Curves3D*> v)
{
    for(auto iter = v.begin(); iter < v.end(); ++iter){
        delete *iter;
    }
    v.clear();
}
int main (void)
{
    // begining with stars...
    cout << "**********************" << endl;

    // populating a container of object  created in random manner with random
    // parametres
    vector<Curves3D*> v1 = populateCont1();

    // printing coordinates of points and deribatives of all curves in the container
    // at t = PI/4
    printCont(v1, M_PI/4);

    // adding some stars to screen...
    cout << "**********************" << endl;

    // populating a second required container
    vector<Curves3D*> v2 = populateCont2(v1);

    // sorting the second container in the ascending order of circles' radii.
    sort(v2.begin(), v2.end(), LessRadiusThen);

    // computing the total sum of radii of all curves in second container and
    // printing it.
    cout << "Sum of all radiuses of curve Circle  = "
         << ComputeAllRadius(v2) << endl;

    // there can never be too many stars)
    cout << "**********************" << endl;

    // memory deallocation
    clearVector(v1);
    v2.clear();

    return 0;
}
