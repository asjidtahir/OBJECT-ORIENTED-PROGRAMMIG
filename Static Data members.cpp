#include<iostream>
using namespace std;
class ajji
{
public:
	int x;
	static int count;
	ajji()  //Default constructor
	{
		count++;
	}
};
int ajji::count = 0;
int main()
{
	cout << "The initial count is :" << ajji::count << endl;
	ajji foo,foo1 , foo3 ;
	cout << "After increament the count is :" << ajji::count << endl;
	system("pause");
	return 0;
}
