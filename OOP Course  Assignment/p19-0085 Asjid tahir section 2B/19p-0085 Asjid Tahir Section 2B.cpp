#include<iostream>
#include<string>
using namespace std;
struct teamdata
{
	string firstname, lastname;
	int no_of_goals;
	int age;
	int ranking;
};
void add(teamdata foo[], int* n)
{
	{
		cout << "The first Name of the player is :" << endl;
		cin >> foo[*n].firstname;
		cout << "The last name of the player is :" << endl;
		cin >> foo[*n].lastname;
		cout << "The age of the player is " << endl;
		cin >> foo[*n].age;
		cout << "The no of goals of the player is :" <<  endl;
		cin >> foo[*n].no_of_goals;
		cout << "The Rank of the player is :" << endl;
		cin >> foo[*n].ranking;
		cout<<endl<<endl;
	}
}
void update(teamdata foo[],int* n)
{
	cout << "What do you want to replace:" << endl;
	int change;
	string name,lname;
	cout<<"1. For Changing Firstname \n";
	cout<<"2. For Changing Lastname \n";
	cout<<"3. For Changing Age \n";
	cout<<"4. For Changing No. of Goals \n";
	cout<<"5. For Changing Ranking \n";
	cin >> change;
	cout<<"Enter the First Name \n";
	cin>>name;
	cout<<"Enter the Last Name \n";
	cin>>lname;
	for (int i = 0; i < *n; i++)
	{ if(name==foo[i].firstname && lname==foo[i].lastname)
		{if (change == 1)
		{  cout<<"Enter a new Firstname ";
			cin >> foo[i].firstname;
		}
		else if (change == 2)
		{   cout<<"Enter a new Lastname ";
			cin >> foo[i].lastname;
		}
		else if (change == 3)
		{   cout<<"Enter a new Age ";
			cin >> foo[i].age;
		}
		else if (change == 4)
		{  cout<<"Enter new No of Goals ";
			cin >> foo[i].no_of_goals;
		}
		else if (change == 5)
		{  cout<<"Enter a new Ranking ";
			cin >> foo[i].ranking;
		}}
	}cout<<endl<<endl;
}
void searching(teamdata foo[], int* n)
{
	string name, lname;
	cout << "What do you want to search:" << endl;
	cout << "The first name of the player is:" << endl;
	cin >> name;
	cout << "The last name of the player is :" << endl;
	cin >> lname;
	for (int i = 0; i < *n; i++)
	{
		if (name == foo[i].firstname && lname == foo[i].lastname)
		{
			cout << "The first name of the player is:" << foo[i].firstname << endl;
			cout << "The last name of the player is:" << foo[i].lastname << endl;
			cout << "The age of the player is:" << foo[i].age << endl;
			cout << "The no of goals of the player is :" << foo[i].no_of_goals << endl;
			cout << "The rank of the player is :" << foo[i].ranking << endl<<endl;
		}
	}
}
void display(teamdata foo[], int* n)
{
	for (int i = 0; i < *n; i++)
	{
		cout << "The first name of the player is:" << foo[i].firstname << endl;
		cout << "The last name of the player is:" << foo[i].lastname << endl;
		cout << "The age of the player is:" << foo[i].age << endl;
		cout << "The no of goals of the player is :" << foo[i].no_of_goals << endl;
		cout << "The rank of the player is :" << foo[i].ranking << endl<<endl;
	}
}

int main()
{  cout<<"Enter the No of players you want in th team ";
	int press,z,counter=0;
	int*ptr=&z,*counter1=&counter;
	cin>>z;
	teamdata foo[z];
do{	cout<<"Press 1 to add a new player:"<<endl;
	cout << "press 2 to update a players record:" << endl;
	cout << "Press 3 to search a player:" << endl;
	cout << "Press 4 to display and complete the list of players:" << endl;
	cout << "Press 5 to exit a program:" << endl;
	cin >> press;
	if (press == 1)
	{
	 if(counter<z)
		{
		add(foo,counter1);
		counter++;
		}}
	if (press == 2)
	{
		update(foo,ptr);

	}
	if (press == 3)
	{
		searching(foo,ptr);

	}
	if (press == 4)
     display(foo,ptr);
	}while(press != 5);
	
}
