# include "dataTypes.h"
# include <iostream>
# include <math.h>
// implementation of classes
Point3D::Point3D (): x(0), y(0), z(0) {}

Point3D::Point3D(double p_x, double p_y, double p_z):
    x(p_x), y(p_y), z(p_z) {}

void Point3D::showCoordinates()
{
    std::cout << std::fixed 
              << "x is " << x
              << " y is " << y 
              << " z is " << z;
}

Vector3D::Vector3D() : x(0), y(0), z(0), lenV(0) {}

Vector3D::Vector3D(double p_x, double p_y, double p_z)
    {
        x = p_x - 0;
        y = p_y - 0;
        z = p_z - 0;
        lenV = sqrt(x*x + y*y + z*z);
    }

Vector3D::Vector3D(double p1_x, double p1_y, double p1_z,
              double p2_x, double p2_y, double p2_z)
    {
        x = p2_x - p1_x;
        y = p2_y - p1_y;
        z = p2_z - p1_z;
        lenV = sqrt(x*x + y*y + z*z);
    }    
void Vector3D::showVector()
{
    std::cout << std::fixed
              << "x is " << x
              << " y is " << y
              << " z is " << z;
}

// ctor Circle3D
Circle3D::Circle3D(double p_x, double p_y, double p_r) : x_c(p_x), y_c(p_y), z(0), r(p_r) 
{

}
// not needs anymore
/*
bool Circle3D::operator<(Circle3D& p_ref)
{
    if(this->getRadius() >= p_ref.getRadius())
        return true;
    else 
        return false;
}
*/

double Circle3D::getRadius()
{
    return r;
}

Point3D Circle3D::getPoint3D(double t)
{
    double x, y, z;
    x = x_c + r*cos(t);
    y = y_c +r*sin(t);
    z = 0;
    
    Point3D point(x, y, z);
    return point;
}

Vector3D Circle3D::getDer1(double t)
{
    double x, y, z;
    x = -r*sin(t);
    y = r*cos(t);
    z = 0;

    Vector3D vector(x, y, z);

    return vector;
}

// double Circle3D::getRadius()
// {
//     return r;
// }

Ellipse3D::Ellipse3D(double p_x, double p_y, double p_r_a, double p_r_b) :
    x_c(p_x), y_c(p_y), z(0), r_a(p_r_a), r_b(p_r_b) 
{

}
double Ellipse3D::getRadius()
{ return 0;}

Point3D Ellipse3D::getPoint3D(double t)
{
    double x, y, z;
    x = x_c + r_a*cos(t);
    y = y_c + r_b*cos(t);
    z = 0;

    Point3D point(x, y, z);

    return point;
}

Vector3D Ellipse3D::getDer1(double t)
{
    double x, y, z;
    x = -r_a*sin(t);
    y = r_b*cos(t);
    z = 0;

    Vector3D vector(x, y, z);

    return vector;
}

Helix3D::Helix3D(double p_r, double p_step) : r(p_r), step(p_step)
{
    
}

double Helix3D::getRadius()
{return 0;}

Point3D Helix3D::getPoint3D(double t)
{
    double x, y, z;
    x = r*cos(t);
    y = r*sin(t);
    z = (step/(2*M_PI))*t;

    Point3D point(x, y, z);

    return point;
}

Vector3D Helix3D::getDer1(double t)
{
    double x, y, z;
    x = -r*sin(t);
    y = r*cos(t);
    z = (step/(2*M_PI));

    Vector3D vector(x, y, z);

    return vector;
}