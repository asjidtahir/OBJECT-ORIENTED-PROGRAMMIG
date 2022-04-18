#include<iostream>
using namespace std;
void foo(int x, int y)
{
	if (y < 11)
	{
		cout << x << "  *  " << y << "  =  " << x * y << endl;
		y++;
		foo(x, y);
	}
	if (x== 10)
	{
		return;
	}
}
int main()
{
	int n = 1, n1;
	cout << "Enter your table you want:" << endl;
	cin >> n1;
	foo(n1, n);
    system("pause");
    return 0;
}