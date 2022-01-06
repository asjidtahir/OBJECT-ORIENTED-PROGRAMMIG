#include <iostream> 
#include<string>
#include<fstream>
using namespace std;
void foo(char arr[], int* n)
{
	int a = 0;
	ifstream infile;
	infile.open("Data.txt");
	ofstream outfile;
	outfile.open("Answer.txt");
	outfile << "answer";
	for (int i = 0; i <= *n / 2 && *n != 0; i++)
	{
		if (arr[i] != arr[*n - i - 1])
		{
			a = 1;
			break;
		}
	}
	if (a == 1)
	{
		cout << "Not Palindrome" << endl;
		outfile << "array is not pallindrome" << endl;
	}
	else
		cout << "Palindrome" << endl;
	outfile << "array is palindrome" << &foo << endl;
}
int main()
{
	char arr[] = { 1, 2, 3, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	foo(arr, &n);
	system("pause");
	return 0;
}