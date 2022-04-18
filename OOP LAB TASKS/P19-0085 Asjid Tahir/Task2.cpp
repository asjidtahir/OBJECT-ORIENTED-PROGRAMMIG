#include<iostream>
using namespace std;
class person
{
public:
	void introduction()
	{
		cout << "Hey from person" << endl;
	}
};
class student : public person
{
public:
	void introducuction()
	{
		cout << "Hey from Student" << endl;
	}
};
class farmer : public person
{
public:
	void introducuction()
	{
		cout << "Hey from Farmer" << endl;
	}
};
void whos_there(person& foo)
{
	foo.introduction();
}
int main()
{
	farmer anil;
	student alex;
	whos_there(anil);
	whos_there(alex);
	system("pause");
	return 0;
}