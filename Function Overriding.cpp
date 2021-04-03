#include<iostream>
using namespace std;
class animal
{
public:
	void makesound()
	{
		cout << " Different types of animals sound:" << endl;
	}
};
class dog : public animal
{
public:
	void makesound()
	{
		cout << "Dog bow bow :" << endl;
	}
};
class cat : public animal
{
public:
	void makesound()
	{
		cout << "Cat meow meow :" << endl;
	}
};
int main()
{
	animal a;
	a.makesound();
	cout << endl;
	dog d;
	d.makesound();
	cout << endl;
	cat c;
	c.makesound();
	system("pause");
	return 0;
}