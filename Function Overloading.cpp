#include<iostream>
using namespace std;
int add(int a, int b)
{
	return a + b;
}
double add(double a, double b, double c)
{
	return a + b + c;
}
double add(int a, double b)
{
	return a + b;
}
int main()
{
	cout << "Following are the additions:" << endl;
	cout << "addition is :" << add(1, 2) << endl;
	cout << "addition is :" << add(1.3, 2.3, 2.3) << endl;
	cout << "addition is :" << add(1, 2.3) << endl;
	system("pause");
	return 0;
}