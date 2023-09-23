// Class returns Point with x, y, z coordinates
class Point3D
{
private:
    double X, Y, Z;
public:
    Point3D(double x, double y, double z);
    //Show coordinates method
    void showCoordinates();
    //Set up point method
    void setPoint(double x, double y, double z);
};
//Class returns Vector-point
class Vector3D
{
private:
    double X,Y,Z;
public:
    Vector3D(double x, double y, double z);
    //Show data of vector method
    void showVector();
    //Set up data
    void setVector(double x, double y, double z);
};

//Abstract class -ancestor of other Curves classes
class Curves3D
{
public:
   //virtual ~dtor
   virtual ~Curves3D(){};
   //pure virtual method- get a 3D point at parameter t
   virtual Point3D getPoint(double t) = 0;
   //pure virtual method- get a first derivative ( 3D vector)
   virtual Vector3D getDer1(double t) = 0;
   //this method is designed to clarify type of curves3D
   virtual int getType() = 0;
   //getting radius of curve if it is posssible
   virtual double getRadius() = 0;
};
//class of curve: Circle
class Circle : public Curves3D
{
protected:
    double X_center,Y_center;
    double Z ;
    double Radius;
public:
    // C(t) for Circle is:
    // x(t) = x_center + radius*cos(t);
    // y(t) = y_center + radius*sin(t);
    //ctors:
    Circle(double x, double y, double r);
    Circle(double x, double y, double z, double r);
    // creating a point, inserting t in C(t)
    Point3D getPoint(double t) override;
    //creating a vector, taking a first derivative per t
    Vector3D getDer1(double t) override;
    //overrided method from base class Curves3D
    int getType() override;
    //overrided getRadius from base class
    double getRadius() override;
};
//class of curve: Ellipse. It is inherited from base Circle and Curves3D
class Ellipse3D : public Circle
{
private:
    //unique field for this class- radius b
    double  Rad_b;
public:
    // C(t) for Ellipse is:
    // x(t) = x_center + rad_a*cos(t);
    // y(t) = y_center + rad_b*sin(t);
    Ellipse3D(double x, double y, double r_a, double r_b);
    // creating a point, inserting t in C(t)
    Point3D getPoint(double t) override;
    //creating a vector, taking a first derivative per t
    Vector3D getDer1(double t) override;
    //determing type method:
     int getType() override;
};
//class of curve: Helix. It is inherited from base class Circle and Curves3D
class Helix3D : public Circle
{
private:
    // unique field for class Helix3D
    double  step;
public:
    // C(t) for Helix  is:
    // x(t) = x_center + radius*cos(t);
    // y(t) = y_center + radius*sin(t);
    // z(t) = step*t
    Helix3D(double x, double y, double z, double r);
    // creating a point, inserting t in C(t)
    Point3D getPoint(double t) override;
    //Creating a vector, taking a first derivative per t
    Vector3D getDer1(double t) override;
    //determing type method:
    int getType() override;
};
    //Implementation of classes:
    Point3D::Point3D(double x, double y, double z)
    {
	X = x;
	Y = y;
	Z = z;
    }

    void Point3D::showCoordinates()
    {
	cout << "X is " << fixed << X << " ";
	cout << "Y is " << fixed << Y << " ";
	cout << "Z is " << fixed << Z << endl;
    }

    void Point3D::setPoint(double x, double y, double z)
    {
	X = x;
	Y = y;
	Z = z;
    }

    Vector3D:: Vector3D(double x, double y, double z)
    {
	X = x;
	Y = y;
	Z = z;
    }

    void Vector3D::showVector()
    {
	cout << "X is " << fixed << X << " ";
	cout << "Y is " << fixed << Y << " ";
	cout << "Z is " << fixed << Z << endl;
    }

    void Vector3D::setVector(double x, double y, double z)
    {
	X = x;
	Y = y;
	Z = z;
    }

    Circle::Circle(double x, double y, double r) : X_center(x), Y_center(y), Radius(r)
    {
	Z = 0;
    }

    Circle::Circle(double x, double y, double z, double r) : X_center(x), Y_center(y), Z(z), Radius(r)
    {

    }

    Point3D  Circle::getPoint(double t)
    {
	//0 <= t <= 2*PI;
	double x, y, z;

	x = X_center + Radius*cos(t);
	y = Y_center + Radius*sin(t);
	z = 0;

	Point3D point(x, y, z);

	return point;
    }

    Vector3D Circle::getDer1(double t)
    {
	double x, y , z;
	x = -Radius*sin(t);
	y = Radius*cos(t);
	z = 0;

	Vector3D vector(x, y, z);

	return vector;
    }

    int Circle::getType()
    {
        return 1;
    }

    double Circle::getRadius()
    {
        return Radius;
    }
    Ellipse3D::Ellipse3D(double x, double y, double r_a, double r_b)
	: Circle(x, y, r_a), Rad_b(r_b)
    {
	Z = 0;
    }

    Point3D Ellipse3D::getPoint(double t)
    {
	//0 <= t <= 2*pi;
	double x, y, z;

	x = X_center + Radius*cos(t);
	y = Y_center + Rad_b*sin(t);
	z = 0;

	Point3D point(x, y, z);

	return point;
    }

    Vector3D Ellipse3D::getDer1(double t)
    {
	double x, y , z;
	x = -Radius*sin(t);
	y = Rad_b*cos(t);
	z = 0;

	Vector3D vector(x, y, z);

	return vector;
    }

    int Ellipse3D::getType()
    {
         return 2;
    }

    Helix3D::Helix3D(double x, double y, double z, double r)
	: Circle(x, y, z, r)
    {
	step = Z;
    }

    Point3D Helix3D::getPoint(double t)
    {
	//0 <= t <= 2*pi;
	double x, y, z;

	x = X_center + Radius*cos(t);
	y = Y_center + Radius*sin(t);
	z = Z;

	Point3D point(x, y, z);

	return point;
    }

    Vector3D Helix3D::getDer1(double t)
    {
	double x, y , z;
	x = -Radius*sin(t);
	y = Radius*cos(t);
	z = step;

	Vector3D vector(x, y, z);

	return vector;
    }

    int Helix3D::getType()
    {
         return 3;
    }
