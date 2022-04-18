#include<iostream>
#include<string>
using namespace std;
class foo
{
public:
	string addresses[500];
	foo()
	{
		for (int i = 0; i < 500; i++)
		{
			addresses[i] = "   ";
			cout << "Your Constructor Created :" << endl;
		}
	}
	void store_address(string ad[], int n)
	{

		addresses[n] = ad[n];
	}

	void printing_of_address()
	{
		for (int i = 0; i < 500; i++)
		{
			cout << "Street Address is : " << addresses[i] << endl;
		}
	}
};