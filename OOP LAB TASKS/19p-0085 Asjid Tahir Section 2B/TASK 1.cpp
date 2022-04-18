#include<iostream>
using namespace std;
class ajji
{
private:
	int counter;
public:
	ajji() :counter(0)
	{
	}
	void input()
	{
		cout << "The non-negative integer is :" << endl;
		cin >> counter;
	}
	void get()
	{
		cout<<"counter = "<<counter;
	}
	void increament()
	{
		counter++;
	}
	void decreament()
	{
		if (counter > 0)
		{
			 counter--;

		}

	}
};
int main()
{
	ajji foo;
	foo.input();
	foo.increament();
	foo.get();
	foo.decreament();
	foo.get();
	system("pause");
	return 0;
}

