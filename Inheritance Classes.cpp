#include<iostream>
using namespace std;
class shape
{
public:
	void print()
	{
		cout << " This is a shape \n";
	}
};
class polygon : public shape
{
public:
	void print1()
	{
		cout << " Polygon is a shape \n";
	}
};
class rectangle : public shape , public polygon 

{
public:
	void print2()
	{
		cout << " Rectangle is a shape \n";
	}
};
class triangle : public shape , public polygon , public rectangle 
{
public:
	void print3()
	{
		cout << " triangle is a shape \n";
	}
};
class Square : public shape , public polygon, public rectangle , public triangle
{
public:
	void print4()
	{
		cout << " Square is a shape \n";
	}
};
int main()
{
	polygon p;
	p.print();
	rectangle r;
	r.print1();
	r.print2();
	Square s;
	s.print3();
	s.print4();
	return 0;
}