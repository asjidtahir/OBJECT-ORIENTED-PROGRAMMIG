#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class addressType
{
public:
	string addresses;
	string city;
	string state;
    string zip;
	addressType()
	{
		addresses = "    ";
		city = "  ";
		state = "  ";
		zip = "  ";
	}
	addressType(addressType& x)
	{
		addresses = x.addresses;
		city = x.city;
		state = x.state;
		zip = x.zip;
	}
	void store_the_address(string adr, string cty, string st, string zip)
	{
		addresses = adr;
		city = cty;
		state = st;
		zip = zip;
	}
	void print_addresses()
	{
		cout << addresses << " " << city << " " << state << " " << zip << endl;
	}
};
class personType
{

public:
	string first;
	string last;
	personType()
	{

		first = "    ";
		last = "     ";
	}
	personType(string First, string Last)
	{
		set_Name(First, Last);
	}

	void printPname() const
	{
		cout << last << " \t    " << first<<endl;
	}

	void set_Name(string First, string Last)
	{
		first = First;
		last = Last;
	}

	string get_First_Name() const
	{
		return first;
	}

	string get_Last_Name() const
	{
		return last;
	}
};
class dateType
{
public:
	int day;
	int month;
	int year;

	dateType()
	{
		day = 0;
		month = 0;
		year = 0;
	}

	dateType(int month, int day, int year)
	{
		set_Date(month, day, year);
	}
	void set_Date(int month, int day, int year)
	{
		month = month;
		day = day;
		year = year;
	}
	int get_Day() const
	{
		return day;
	}
	int get_Month() const
	{
		return month;
	}
	int get_Year() const
	{
		return year;
	}

	void print_Date() const
	{
		cout << month << "  " << day << "  " << year << endl;
	}
};
class e_PersonType :public addressType, public personType, public dateType
{

private:
	string nickname;
public:
	string person;
	int phone_number;
	friend class myFriend;
	e_PersonType()
	{
		person = "   ";
		phone_number = 0;
	}

	void store(string per, int ph)
	{
		person = per;
		phone_number = ph;
	}

	void print()
	{
		cout << person << "\t" << phone_number<<endl;
	}
};
class myFriend
{
public:
	string name, address;
	int phone_number, age;
	void setter(e_PersonType& ext, string n)
	{
		ext.nickname = n;
	}

	string getter(e_PersonType& ext)
	{
		return ext.nickname;
	}
};
class addressBookType
{
public:
	e_PersonType foo2[500];
	string file;
	myFriend F;
	friend void displayall(addressBookType&);
	void input()
	{
		string f, l, personality, strtaddress, c, s, z, nick;
		int d, m, y;

		ifstream foo;
		foo.open("ajji.txt");
		for (int i = 0; i < 500; i++)
		{
			foo >> f;
			foo >> l;
			foo >> nick;
			F.setter(foo2[i], nick);
			foo >> d >> m >> y;
			foo2[i].set_Date(m, d, y);
			foo2[i].set_Name(f, l);
			foo >> personality >> d;
			foo2[i].store(personality, d);
			foo >> strtaddress >> c >> s >> z;
			foo2[i].store_the_address(strtaddress, c, s, z);
		}
		foo.close();
	}
	void output()
	{
		cout << "Last Name  " << "First Name  " << "D.O.B\t   " << "Relation\t";
		cout << "Ph. No.\t" << "  Address  \n";
		for (int z = 0; z < 500; z++)
		{
			foo2[z].printPname();
			cout << "      ";
			foo2[z].print_Date();
			cout << "   ";
			foo2[z].print();
			cout << "      ";
			foo2[z].print_addresses();

		}
	}
	void search()
	{
		int counter = 0;
		string name;

		cout << " The Last which you want to search : " << endl;
		cin >> name;

		for (int i = 0; i < 500; i++)
		{
			if (name == foo2[i].get_Last_Name())
			{
				 if (counter == 0)
				{
					cout << "The Persons With the Last Name are :" << name <<endl;
					cout << endl;
				}
				cout << " D.O.B  : "<<endl;
				foo2[i].print_Date();
				cout << " The phone number and the relation is : " << endl;
				foo2[i].print();
				cout <<" The  Address you want are  : "<<endl;
				foo2[i].print_addresses();
				cout << endl;
				counter++;
			}
		}
		if (counter == 0)
		{
			cout << "Found EMPTY:" << endl;
		}
	}
	void searching_of_month()
	{
		int month, counter = 0;
		cout << "The month you want to search is :"<<endl;
		cin >> month;
		for (int i = 0; i < 500; i++)
		{
			if (month == foo2[i].get_Month())
			{
				if (counter == 0)
				{
					cout << "Those persons which have the same birthday months with other:"<<endl;
					cout << "Last Name   " <<  "First Name "<<endl;
				}
				foo2[i].printPname();
				cout << endl;
				counter++;
			}
		}
		if (counter == 0)
		{
			cout << "Found EMPTY:" << endl;
		}
	}
	void searchl()
	{
		string first_name, last_name;
		int i, j, counter = 0, count = 0;
		cout << "The first last name is:"<<endl;
		cin >> first_name;
		cout << "The second last name is :"<<endl;
		cin >> last_name;
		for (i = 0; i < 500; i++)
		{
			if (first_name == foo2[i].get_Last_Name())
			{
				j = i;
			}
		}
		j = j + 1;
		for (int k = j; k < 500; k++)
		{
			if (last_name == foo2[k].get_Last_Name())
			{
				count = k;
				break;
			}
		}
		for (j; j < count; j++)
		{
			if (counter == 0)
			{

				cout << "Name(s) Between the given Range are : \n\n";
				cout << "Last Name  " << "First Name  \n";
			}
			foo2[j].printPname();
			cout << endl;
			counter++;
		}
		if (counter == 0)
		{
			cout << "Found EMPTY:" << endl;
		}
	}

	void searching_of_data()
	{
		int counter = 0, buiss_ass;

		cout << "     Entering your data     " << endl;
		cout << "1. For Searching of Family Members "<<endl;
		cout << "2. For Searching of Friends:"<<endl;
		cout << "3. For Searching of Business Associates :"<<endl;
		cin >> buiss_ass;

		for (int i = 0; i < 500; i++)
		{
			if (buiss_ass == 1)
			{
				if (foo2[i].person == "Family")
				{
					if (counter == 0)
					{
						cout << "The names :"<<endl;
						cout << "Last Name  " << "First Name  "<<endl;
					}
					foo2[i].printPname();
					cout << endl;
					counter++;
				}
			}

			if (buiss_ass== 2)
			{
				if (foo2[i].person == "Friend")
				{
					if (counter == 0)
					{
						cout << "Name(s) are : \n";
						cout << "Last Name  " << "First Name  \n";
					}
					foo2[i].printPname();
					cout << endl;
					counter++;
				}
			}

			if (buiss_ass == 3)
			{
				if (foo2[i].person == "Business")
				{
					if (counter == 0)
					{
						cout << "Name(s) are : \n";
						cout << "Last Name  " << "First Name  \n";
					}
					foo2[i].printPname();
					cout << endl;
					counter++;
				}
			}
		}
		if (counter == 0)
		{
			cout << "Found EMPTY :"<<endl;
		}
	}


	void choices()
	{
		int option;
		cout << "Enter The number according to your requirements:"<<endl;
		cout << "1. Search for a person by last name :"<<endl;
		cout << "2. The address, phone number, and date of birth of a given person :"<<endl;
		cout << "3. The names of the people whose birthdays are in a given month :"<<endl;
		cout << "4. The names of all the people between two last names :"<<endl;
		cout << "5.  The names of all family members, friends, or business associates :" << endl;
		cin >> option;

		if (option== 1)
		{
			search();
		}
		else if (option == 2)
		{
			search();
		}
		else if (option == 3)
		{
			searching_of_month();
		}
		else if (option == 4)
		{
			searchl();
		}
		else if (option == 5)
		{
			searching_of_data();
		}
	}
};
void displayall(addressBookType& ptr)
{
	cout << "Last Name  " << "First Name  "<<endl;
	cout << "Nick Name   " << "D.O.B    " << "Relation"<<endl;
	cout << "Phone number" << "  Address  "<<endl;

	for (int u = 0; u < 500; u++)
	{
		ptr.foo2[u].printPname();
		cout << "      ";
		cout << ptr.F.getter(ptr.foo2[u]);
		cout << "      ";
		ptr.foo2[u].print_Date();
		cout << "   ";
		ptr.foo2[u].print();
		cout << "      ";
		ptr.foo2[u].print_addresses();
	}
}
int main()
{
	char option;
	addressBookType Y;
	Y.input();
	Y.choices();
	cout << "  If you want To Display All The Contacts Press yes otherwise not:" << endl;
	cout << endl;
	cout << endl;
	cin >> option;
	if (option == 'yes')
	{
		displayall(Y);
	}
	else
		return 0;
	system("pause");
	return 0;
}
