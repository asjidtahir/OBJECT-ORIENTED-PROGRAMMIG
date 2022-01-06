#include <iostream>
//#include<string>
using namespace std;
int main()
{
	int number;
	cout << "Enter a number to separate it's digits:"<<endl;
	cin >> number;
	int reverseNum = 0;
	while (number > 0)
	{
		reverseNum += (number % 10);
		reverseNum *= 10;
		number /= 10;
	}
	reverseNum /= 10;
	while (reverseNum != 0)
	{
		cout << reverseNum % 10 << " ";
		reverseNum /= 10;
	}
	cout << endl;
	system("pause");
	return 0;
}
