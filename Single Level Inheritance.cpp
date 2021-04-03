#include<iostream>
using namespace std;
class Shape
{
protected:
	int width;
	int height;
	int length;
public:
	void setwidth(int w)
	{
		width = w;
	}
	void setheight(int h)
	{
		height = h;
	}
	void setlength(int l)
	{
		length = l;
	}
};
class Rectangle : public Shape
{
public:
	int getarea()
	{
		return width * height;
	}
	int getArea()
	{
		return (12)*( width * height);
	}
};
class Square : public Shape
{
public:
	
	int get_area()
	{
		return length * width *height;
	}
};
int main()
{
	Rectangle rec;
	rec.setwidth(4);
	rec.setheight(5);
	Square s;
	s.setlength(3);
	cout << " Area of the Rectangle is : " <<rec.getarea() << endl;
	cout << " Area of the Triangle is : " << rec.getArea() << endl;
	cout << " Area of the Square is : " << s.get_area() << endl;
	system("pause");
	return 0;
}