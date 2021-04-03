#include<iostream>
using namespace std;
inline int Sum(int x, int y)
{
	return x+y;  //The inline functions are a C++ enhancement feature to increase the execution time of
	            //a program. Functions can be instructed to compiler to make them inline so that compiler
	             //can replace those function definition wherever those are being called.
}
int main()
{
	cout << "The addition of x and y is :" << Sum(10, 10) << endl;
	system("pause");
	return 0;
}
