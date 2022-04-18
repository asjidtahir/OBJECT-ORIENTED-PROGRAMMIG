#include<iostream>
#include<string>
using namespace std;
class number
{
public:
	int numbers;
	number()
	{
		cout << "The default constructor is created:" << endl;
		numbers = 1;
	}
	number(int foo)
	{
		if (foo >= 1 && foo <= 100)
		{
			numbers = foo;
		}
		else
			cout << "Your range of the number is not valid:" << endl;
	}
	void set()
	{
		int range;
		do
		{
			cout << "Enter a number which is in the range of 0 to 100:" << endl;
			cin >> range;
			if (range >= 1 && range <= 100)
			{
				numbers = range;
			}
			else
				cout << "Your range of the number is not valid:" << endl;

		} while (!(range > 0 && range < 101));
	}
	int getnumbers()
	{
		return numbers;
	}
	void operator >(number& foo1)
	{
		if (numbers > foo1.numbers)
		{
			cout << numbers << " > " << foo1.numbers << "= True " << endl;
		}
		else
			cout << numbers << " > " << foo1.numbers << "= False " << endl;
	}
	void operator <(number& foo2)
	{
		if (numbers < foo2.numbers)
		{
			cout << numbers << " < " << foo2.numbers << "= True " << endl;
		
		}	
		else
			cout << numbers << " < " << foo2.numbers << "= False " << endl;
	}
	void operator ==(number& foo3)
	{
		if (numbers == foo3.numbers)
		{
			cout << numbers << " == " << foo3.numbers << "= True " << endl;
		}
		else
			cout << numbers << " == " << foo3.numbers << "= False " << endl;
	}
	void operator !=(number& foo4)
	{
		if (numbers != foo4.numbers)
		{
			cout << numbers << " != " << foo4.numbers << "= True " << endl;
		}
		else
			cout << numbers << " != " << foo4.numbers << "= False " << endl;
	}
	void operator =(number& foo5)
	{
		numbers = foo5.numbers;
	}
};
int main()
{
	number A, B;
	A.set();
	B.set();
	A > B;
	A < B;
	A == B;
	A != B;
	cout << "Before using the ' = ' operator:" << endl;
	cout << " The number 1 = " << A.numbers << endl;
	cout << "The number 2 = " << B.numbers << endl;
	A = B;
	cout << "After using the ' = ' operator:" << endl;
	cout << "The number 1 = " << A.numbers << endl;
	cout << "The number 2 = " << B.numbers<< endl;
	system("pause");
	return 0;
}
