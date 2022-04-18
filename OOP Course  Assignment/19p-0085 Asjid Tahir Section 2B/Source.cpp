#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct menuItem
{
	string name;
	int Quantity_of_item;
	string Waiting_time;
	float Taxes;
	float Charges;
	char  foo_1[5];
};
void data_menu(menuItem menu_List[], int n)
{
	ifstream foo;
	foo.open("abc.txt");
	for (int i = 0; i < n; i++)
	{
		foo >> menu_List[i].name;
		foo >> menu_List[i].Quantity_of_item;
		foo >> menu_List[i].Taxes;
		foo >> menu_List[i].Waiting_time;
		foo >> menu_List[i].Charges;
		for (int j = 0; j < 5; j++)
		{
			foo >> menu_List[i].foo_1[j];
		}
	}
}
void showMenu(menuItem menu_List[], int n)
{
	cout << "Enter the item you want to choose :" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "   ";
		cout << menu_List[i].name << "\t";
		cout << menu_List[i].Quantity_of_item << "\t";
		cout << menu_List[i].Taxes << "\t";
		cout << menu_List[i].Waiting_time << "\t";
		cout << menu_List[i].Charges << "\t";
		for (int j = 0; j < 5; j++)
		{
			cout << menu_List[i].foo_1[j];
		}
		cout << endl;
	}
}
void Checking(menuItem menu_List[], int n)
{
	int opt;
    int q;
    int d[9] = { 0,0,0,0,0,0,0,0,0 };
	int counter = 0;
	int q1[9] = { 0,0,0,0,0,0,0,0,0 };
	char k;
	float bill = 1.0;
	float bill_1 = 0.0;
	do {
		showMenu(menu_List, n);
		cin >> opt;
		d[counter] = opt;
		cout << "Enter the Quantity of the Item :" << endl;
		cin >> q;
		q1[counter] = q;
		bill = (menu_List[opt - 1].Charges) * q;
		bill = bill * (menu_List[opt - 1].Taxes);
		bill_1 = bill_1 + bill;
		cout << "Do you want to make any other choice or not(y/n)?:" << endl;
		cin >> k;
		if (k == 'y')
			counter++;
	} while (k != 'n');
	cout << "YOUR BILL IS :" << endl;
	cout << "Item Name\t  Quantity \t Taxes \tCharges per Serving \t\n";
	for (int z = 0; z < counter + 1; z++)
	{
		opt = d[z];
		q = q1[z];
		cout << menu_List[opt - 1].name << "\t";
		cout << q << "\t";
		cout << menu_List[opt - 1].Taxes << "\t";
		cout << menu_List[opt - 1].Charges << "\t";
		cout << endl;
	}
	cout << "Your Total Bill is  $ : " << bill_1<<endl;
}
int main()
{
	menuItem menu_List[9];
	data_menu(menu_List, 9);
	Checking(menu_List, 9);
	system("pause");
	return 0;
}