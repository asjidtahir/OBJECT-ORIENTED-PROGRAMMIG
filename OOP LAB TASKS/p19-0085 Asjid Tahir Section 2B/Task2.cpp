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
		{
			height = h;
		}
		else
			height = 0;
	}
	void set2(double cx1, double cy1)
	{
		cx = cx1;
		cy = cy1;
	}
	double volume()
	{
		return area() * height;
	}
	double surfaceArea()
	{
		return (2 * 3.1416 * getRadius() * height) + (2 * area());
	}
};
int main()
{
	double radius;
	double height;
	double shipping_cost;
	double paint_cost;
	double x;
	double y;
	cout << "Enter the Radius of Circle :"<<endl;
	cin >> radius;
	cout << "Enter the Height of Cylinder :" << endl;
	cin >> height;
	cout << "Enter the Shipping Cost per Litre :"<<endl;
	cin >> shipping_cost;
	cout << "Enter the Paint Cost per square foot :"<<endl;
	cin >> paint_cost;
	cylinderType C;
	C.setRadius(radius);
	C.set1(height);
	x = C.volume() / 0.0353147;
	cout << "Shipping Cost is = $" << x * shipping_cost << endl;
	cout << "Paint Cost is  =   $" << C.surfaceArea() * paint_cost << endl;
	system("pause");
	return 0;
}
