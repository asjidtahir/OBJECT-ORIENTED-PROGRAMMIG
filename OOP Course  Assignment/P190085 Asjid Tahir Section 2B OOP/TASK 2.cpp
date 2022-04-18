#include<iostream>
#include<string>
using namespace std;
class Wheel
{

	string state;

public:

	void setwheelstate (string st)
	{
		state = st;
	}

	string getwheelstate()
	{
		return state;
	}
};
class car
{

	Wheel x[4];

public:

	void setcarismoving()
	{
		for (int i = 0; i < 4; i++)
		{
			x[i].setwheelstate("TURNING");
		}
	}

	void setcarisstopped()
	{
		for (int i = 0; i < 4; i++)
		{
			x[i].setwheelstate("STOPPED");
		}
	}

	void carwheelsstate()
	{
		cout << "The state of car is :" << endl;

		for (int i = 0; i < 4; i++)
		{
			cout << " The Wheel is : " << i << x[i].getwheelstate() << endl;
		}
	}

};

int main()
{
	car foo;
	foo.setcarismoving();
	foo.carwheelsstate();
	system("pause");
	return 0;
}






