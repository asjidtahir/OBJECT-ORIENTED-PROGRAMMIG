#include <iostream> 
#include<string>
#include<fstream>
using namespace std;
int main()
{
	const int count= 25;
	int store[count];
	int a=0;
	int b;
	ifstream file;
	file.open("code.txt");
	if(!file)
	{
		cout<<"txt file note found"<<endl;
	}
	while(!file.eof())
	{
		file>>store[a];
		a++;
	}
	b = a;
	cout<<"The stored array is :: ";
	for(a = 0; a <  b; a++)
		cout<<" "<<store[a];
		cout<<endl;
	system("pause");
	return 0;
}