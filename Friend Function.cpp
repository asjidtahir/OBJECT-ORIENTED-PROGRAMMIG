#include<iostream>
using namespace std;
class Distance
{
private:
	int meters;
public:
	Distance()
	{
		meters = 0;
	}
	void displaydata()
	{
		cout << "The value of distance in meters is:" << meters << endl;
	}
	friend void addvalue(Distance& foo);  //friend function Calling
};
void addvalue(Distance& foo)
{
	foo.meters = foo.meters + 10;
}
int main()
{
	Distance x;
	x.displaydata();
	cout << endl;
	addvalue(x);
	x.displaydata();
	cout << endl;
	system("pause");
	return 0;
}