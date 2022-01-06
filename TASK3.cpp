#include<iostream>
#include<string>
using namespace std;
void menu()
{
	cout << "Enter 'Sun' for 'Sunday'" << endl;
	cout << "Enter 'Mon' for 'Monday'" << endl;
	cout << "Enter 'Tues' for 'Tuesday'" << endl;
	cout << "Enter 'Wednes' for 'Wednesday'" << endl;
	cout << "Enter 'Thurs' for 'Thursday'" << endl;
	cout << "Enter 'Fri' for 'Friday'" << endl;
	cout << "Enter 'Satur' for 'Saturday'" << endl;
}

class dayType
{
	string days[7];
	int i;
	string day;
	string prDay;
	string NxtDay;
	string AddDays;
public:
	dayType(string i) :day(i) {
		days[0] = "Mon";
		days[1] = "Tues";
		days[2] = "Wednes";
		days[3] = "Thurs";
		days[4] = "Fri";
		days[5] = "Satur";
		days[6] = "Sun";
	}
	string setday();
	string preday();
	void Nextday();
	string add(int n);
	void print();

};
int main()
{
	int n;

	string d;
	menu();
	cout << "Enter the day :";
	getline(cin, d);
	dayType Da(d);
	Da.setday();
	Da.preday();
	Da.Nextday();

	cout << "Enter the No. of days to add :";
	while (!(cin >> n) || n < 0) {
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Invalid data type! \nPlease enter No. of daysto add again :";

	}
	Da.add(n);
	Da.print();
	system("pause");
	return 0;

}


string dayType::setday()
{
	i = 9;
	for (int j = 0; j < 7; j++)
	{
		if (day == days[j])
		{
			i = j;
		}
	} if (i == 9)
	{
		day = "Invalid Input";
		i = 7;
	}
	return day;
}
string dayType::preday()
{
	if (i == 0)
		prDay = days[6];
	else if (i == 7)
		prDay = "Invalid Input";
	else
		prDay = days[i - 1];
	return prDay;
}
void dayType::Nextday()
{
	if (i == 6)
		NxtDay = days[0];
	else if (i == 7)
		prDay = "Invalid Input";
	else
		NxtDay = days[i + 1];

}
string dayType::add(int n)
{
	n = n + i;
	while (n >= 7)
	{
		n = n - 7;
	}
	if (i == 7)
		days[n] = "Invalid Input ";
	return AddDays = days[n];
}
void dayType::print()
{
	cout << endl << "\tDay=" << day << "day" << endl;
	cout << "\tPrevious day :" << prDay << "day" << endl;
	cout << "\tNext day :" << NxtDay << "day" << endl;
	cout << "\tAfter Adding Days :" << AddDays << "day" << endl;
}

