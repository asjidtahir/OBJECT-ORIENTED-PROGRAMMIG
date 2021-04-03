#include<iostream>
using namespace std;
class Animal
{
public:
	virtual void eat() //virtual Function
	{
		cout << "I am eating healthy organic food:" << endl;
	}
};
class cat : public Animal
{
public:
	void eat()
	{
		cout << "I am eating fish:" << endl;
	}
};
class dog : public Animal
{
public:
	void eat()
	{
		cout << "I am eating cats:" << endl;
	}
};
void foofunction(Animal *ptr)
{
	ptr->eat();
}
int main()
{
	Animal* x;
	cat c;
	dog d;
	x = &d;
	foofunction(x);
	system("pause");
	return 0;
}