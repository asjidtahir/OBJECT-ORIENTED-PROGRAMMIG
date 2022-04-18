#include<iostream>
using namespace std;
getnew(int& a, int*& ptr)
{
	cout << "Enter a value \n";
	cin >> a;
	ptr = new int[a];
}
void init(int& a, int*& ptr)
{
	cout << "Enter values ";
	for (int i = 0; i < a; i++)
	{
		cin >> *(ptr + i);
	}
}
void print(int& a, int*& ptr)
{
	cout << "Given values are ";
	for (int i = 0; i < a; i++)
	{
		cout << *(ptr + i) << endl;
	}
}
void del(int*& ptr)
{
	delete[] ptr;
}
int main()
{
	int* ptr;
	int a;
	getnew(a, ptr);
	init(a, ptr);
	print(a, ptr);
	del(a, ptr);
	system("pause");
	return 0;
}
