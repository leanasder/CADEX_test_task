// class returns point with x, y , z coordinates
class Point3D
{
private:
    double x, y, z;
public:
    // ctor by default
    Point3D();
    // ctor with parameters
    Point3D( double p_x, double p_y, double p_z);
    // show coordinates of point
    void showCoordinates();

};

// class returns vector
class Vector3D
{
private:
    double x, y, z; // coordinates of vector
    double lenV; // length of vector
public:
    // ctor by default
    Vector3D();
    // ctor with coordiantes 1 point
    Vector3D (double p_x, double p_y, double p_z);
    
    // ctor with coordinates 2 point
    Vector3D (double p1_x, double p1_y, double p1_z,
              double p2_x, double p2_y, double p2_z);
  
    // show coordinates of vector
    void showVector();

};

// abstract class - ancestor of other Curves classes
class Curves3D
{
public:
    //virtual ~dtor
    virtual ~Curves3D() {}
    // pure virtual method - get a point3D at parameter t
    virtual Point3D getPoint3D(double t) = 0;
    // pure virtual method - get a first derivative (3D vector)
    virtual Vector3D getDer1(double t) = 0;
    //getting radius of curve if it is possible
    virtual double getRadius() = 0;
};

//class Cirle3D
class Circle3D : public Curves3D
{
private:
    double x_c, y_c, z;
    double r;
public:
    //ctor
    Circle3D(double p_x, double p_y, double p_r);
    // creating the point
    Point3D getPoint3D(double t) override;
    // creating the vector
    Vector3D getDer1(double t) override;
   // bool operator<(Circle3D& p_ref);
    // overrided getRadious from base class
   // double getRadius() override;
   // getRadious()
   double getRadius() override;
};

// class Ellipse3D
class Ellipse3D: public Curves3D
{
private:
    double x_c, y_c, z;
    double r_a, r_b;
public:
    Ellipse3D(double p_x, double p_y, double p_r_a, double p_r_b);
    Point3D getPoint3D(double t) override;
    Vector3D getDer1(double t) override;
    double getRadius() override;
    
};

class Helix3D: public Curves3D
{
private:
    double r, step;
public:
    Helix3D(double p_r, double p_step);
    Point3D getPoint3D(double t) override;
    Vector3D getDer1(double t) override;
    double getRadius() override;
};