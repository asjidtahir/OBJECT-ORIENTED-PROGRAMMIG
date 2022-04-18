#include<iostream>
#include<string>
using namespace std;
class romanType
{
public:
	string s;
	char array[10000];
	int num;
public:
	romanType()
	{
		cout << "constructor created :"<<endl;
	}
	void store()
	{
		cout << "Enter a Roman Numeral:"<<endl;
		cin >> s;
	}
	void numeral()
	{
		int counter = 0;
		int n = s.length();
		for (int i = 0; i < n + 1; i++)
		{
			array[i] = s[i];
			if (array[i] == 'M')
			{
				counter += 1000;
			}
			else if (array[i] == 'D')
			{
				counter += 500;
			}
			else if (array[i] == 'C')
			{
				counter += 100;
			}
			else if (array[i] == 'L')
			{
				counter += 50;
			}
			else if (array[i] == 'X')
			{
				counter += 10;
			}
			else if (array[i] == 'V')
			{
				counter += 5;
			}
			else if (array[i] == 'I')
			{
				counter += 1;
			}
		}
		num = counter + 0;
	}
	void print()
	{
		cout << "Select the desired Opt:"<<endl;
		cout << "1. To print given Num again in Roman:" <<endl;
		cout << "2. To print given Num in Integer Form :"<<endl;
		int i = 0;
		cin >> i;
		if (i == 1)
		{
			cout << "Roman Numeral is " << s<<endl;
		}
		else if (i == 2)
		{
			cout << "Positive Integer Num is " << num<<endl;
		}
		else if (i != 1 && i != 2)
		{
			cout << "Please Enter a correct Opt:"<<endl;
			print();
		}
	}
};
int main()
{
	romanType r;
	r.store();
	r.numeral();
	r.print();
	system("pause");
	return 0;
}
