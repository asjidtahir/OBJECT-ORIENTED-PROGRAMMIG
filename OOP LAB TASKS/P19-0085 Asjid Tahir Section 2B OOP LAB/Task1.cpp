#include<iostream>
#include<string>
using namespace std;
class clock_type
{
	int hrs;
	int	mins;
	int	secs;
public:
	clock_type()
	{
		cout << "The Default Constructor is created:" << endl;
		hrs = 0;
		mins = 0;
		secs = 0;
	}
	clock_type(int h, int m, int s)
	{
		hrs = h;
		mins = m;
		secs = s;
	}
	//Copy Constructor is created
	clock_type(clock_type& foo)
	{
		hrs = foo.hrs;
		mins = foo.mins;
		secs = foo.secs;
	}
	void set()
	{
		do {
			cout << " Enter the hours :" << endl;
			cin >> hrs;
			if (hrs < 0 || hrs >24)
			{
				cout << "Please Enter Hours Between 0 & 24 hours:" << endl;
			}
		} while (!(hrs >= 0 && hrs <= 24));
		do {
			cout << " Enter the minutes :" << endl;
			cin >> mins;
			if (mins < 0 || mins >60)
			{
				cout << "Please Enter minutes Between 0 & 24 minutes:" << endl;
			}
		} while (!(mins >= 0 && mins <= 60));
		do {
			cout << " Enter the seconds :" << endl;
			cin >> secs;

			if (secs < 0 || secs >60)
			{
				cout << "Please Enter seconds Between 0 & 24 seconds:" << endl;
			}
		} while (!(secs >= 0 && secs <= 60));
	}
	int gethours()
	{
		return hrs;
	}
	int getminutes()
	{
		return mins;
	}
	int getseconds()
	{
		return secs;
	}
	string operator ==(clock_type& foo1)
	{

		string x;
		if (foo1.hrs == this->hrs && foo1.mins == this->mins && foo1.secs == this->secs)
		{
			return x = "True";
		}
		else
			return x = "False";
	}
	clock_type& operator =(clock_type& foo2)
	{
		hrs = foo2.hrs;
		mins = foo2.mins;
		secs = foo2.secs;
		return *this;
	}
	void operator <<(clock_type& foo3)
	{
		cout << "Hours = " << gethours() << endl;
		cout << "Minutes = " << getminutes() << endl;
		cout << "Seconds = " << getseconds() << endl;
	}
};
int main()
{
	string A;
	clock_type B, C;
	B.set();
	C.set();
	cout << "Obj1 == Obj2 " << (B == C) << endl;
	cout << "We make both the objects are equal:" << endl;
	B == C;
	cout << "Printing Using '<<' Operator : " << endl;
	B<<B;
	system("pause");
	return 0;
}
