#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, n1;
	string** ptr = NULL;
	ptr = new string * [3];
	for (int i = 0; i < 2; i++)
	{
		ptr[i] = new string[3];
	}
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
			cout << " Enter the Data of First Person ";
		if (i == 1)
			cout << "Enter the Data of Second Person ";
		for (int z = 0; z < 3; z++)
		{
			cin >> *(ptr[i] + z);
		}
	} cout << " The Data stored is \n";
	for (int i = 0; i < 2; i++)
	{
		for (int z = 0; z < 3; z++)
		{
			cout << *(ptr[i] + z) << " 		 ";
		}
		cout << endl;
	}
	system("pause");

	return 0;
}