#include<iostream>
using namespace std;
class ajji
{
private:
	int x;
	static int count;
public:
	ajji()  //Default constructor
	{
		count++;
	}
	static int getcount()
	{
		return count;
	}
};
int ajji::count = 0;
int main()
{
	cout << "The initial count is :" << ajji::getcount() << endl;
	ajji foo,foo1 , foo3 ;  //Objects directly proportional to increament count
	cout << "After increament the count is :" << ajji::getcount() << endl;
	system("pause");
	return 0;
}
