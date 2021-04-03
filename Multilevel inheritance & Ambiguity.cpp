#include<iostream>
using namespace std;
class Ajji                   //Base class 1
{
public:
	void printmessage()
	{
		cout << "The class is start now :" << endl;
	}
};
class Rajput                 //Base class 2
{
public:
	void printmessage()
	{
		cout << "The class is end now :" << endl;
	}
};
class AjjiRajput : public Ajji, public Rajput           //Derived class :: Multiple level inheritance
{
public:
	void print_message()
	{
		Ajji::printmessage();
		Rajput::printmessage();        //Ambiguity Cleared
		cout << "The class is start and end now :" << endl;
	}
};
int main()
{
	AjjiRajput foo;
	foo.print_message();
	system("pause");
	return 0;
}