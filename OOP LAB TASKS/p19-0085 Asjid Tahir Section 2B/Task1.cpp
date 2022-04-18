#include<iostream>
#include<string>
using namespace std;
class circleType
{
public:
	void setRadius(double r);
	//Function to set the radius.
	//Postcondition: if (r >= 0) radius = r;
	//otherwise radius = 0;
	double getRadius();
	//Function to return the radius.
	//Postcondition: The value of radius is returned.
	double area();
	//Function to return the area of a circle.
	//Postcondition: Area is calculated and returned.
	double circumference();
	//Function to return the circumference of a circle.
	//Postcondition: Circumference is calculated and returned.
	circleType(double r = 0);
	//Constructor with a default parameter.
	//Radius is set according to the parameter.
	//The default value of the radius is 0.0;
	//Postcondition: radius = r;
	void print()
	{
		cout << "Radius = " << radius << endl;
		cout << "Area = " << area() << endl;
		cout << "Circumference = " << circumference() << endl;
	}
private:
	double radius;
};
void circleType::setRadius(double r)
{
	if (r >= 0)
		radius = r;
	else
		radius = 0;
}
double circleType::getRadius()
{
	return radius;
}
double circleType::area()
{
	return 3.1416 * radius * radius;
}
double circleType::circumference()
{
	return 2 * 3.1416 * radius;
}
circleType::circleType(double r)
{
	setRadius(r);
}
class cylinderType : public circleType
{
private:
	double height;
	double cx;
	double cy;
public:
	void set1(double h)
	{
		if (h > 0)
			height = h;
		else
			height = 0;
	}
	void set2(double cx1, double cy1)
	{
		cx = cx1;
		cy = cy1;
	}
	void volume()
	{
		cout << "Voulme of cylinder = " << area() * height << endl;
	}
	void surfaceArea()
	{
		cout << "Surface Area of Cylinder = " << (2 * 3.1416 * getRadius() * height) + (2 * area()) << endl;
	}
};
int main()
{
	double radius;
	double height;
	double x_coo;
	double y_coo;
	cylinderType C;
	cout << "Your Radius of Circle :"<<endl;
	cin >> radius;
	cout << "Enter the Height of Cylinder :"<<endl;
	cin >> height;
	cout << "Enter the X point of Centre of Circle :"<<endl;
	cin >> x_coo;
	cout << "Enter the Y point of Centre of Circle :"<<endl;
	cin >> y_coo;
	C.setRadius(radius);
	C.print();
	C.set1(height);
	C.set2(x_coo, y_coo);
	C.volume();
	C.surfaceArea();
	return 0;
}
