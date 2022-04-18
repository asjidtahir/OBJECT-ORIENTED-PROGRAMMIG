#include<iostream>
using namespace std;
int main()
{
	int n, n1;
	int** ptr = NULL;
	cout << "Enter no of the Columns in an array ";
	cin >> n;
	cout << "Enter the no of Rows in an array ";
	cin >> n1;
	ptr = new int* [n];
	for (int i = 0; i < n1; i++)
	{
		ptr[i] = new int[n];
	}cout << " Enter the Values ";
	for (int i = 0; i < n1; i++)
	{
		for (int z = 0; z < n; z++)
		{
			cin >> *(ptr[i] + z);
		}
	} cout << " The Values Are ";
	for (int i = 0; i < n1; i++)
	{
		for (int z = 0; z < n; z++)
		{
			cout << *(ptr[i] + z) << endl;
		}
	}
	system("pause");

	return 0;
}
