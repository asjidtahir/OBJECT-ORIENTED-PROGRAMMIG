#include<iostream>
using namespace std;
class Shape
{
protected:
	int width;
	int height;
public:
	Shape(int w = 0, int h = 0)
	{
		width = w;
		height = h;
	}
	virtual int area()
	{
		cout << " The Parent Class area is :" << endl;
		return 0;
	}
};
class square : public Shape
{
public:
	square(int w = 0, int h = 0)
	{
		width = w;
		height = h;
	}
	int area()
	{
		int Area;
		Area = (2 * width) + (2 * height);
		cout << "Area of Square is : " << Area << endl;
		return Area;
	}
};
int main()
{
	Shape s;
	square s1(4, 4);
	Shape* ptr;
	ptr = &s1;
	ptr->area();
	system("pause");
	return 0;
}