#include <iostream>
#include<string>
using namespace std;
void GetNameInitials(string fullname) //pass full name as parameter
{
	int i = 1;
    if (fullname.length() == 0) //if string has zero value it returns the empty string
    {
    	return; 	
	}
    cout << (char)toupper(fullname[0]); //toupper() build-in function used for typecasting i.e typecasting means conversion of charcter to integer type
    while ( i < fullname.length() - 1) //While loop is only for traversing the string 
    {
    	 if (fullname[i] == ' ') //for fullname
    	 {
    	 	cout << (char)toupper(fullname[i + 1]) << ""; //Printing First character
		 }  
		i++;    //for increment the string fullname
	}  
}

int main()
{
    string fullname = "Muhammad Abdullah Azam"; //fullname that you passes
    cout<<" The first initial characters of given fullname are : ";
    GetNameInitials(fullname); //function calling from main
    return 0;
}
