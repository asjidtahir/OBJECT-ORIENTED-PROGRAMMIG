#include<iostream>
#include<string>
using namespace std;
class person
{

public:
	string name;
	int age;

public:
	void setname()
	{
		cout << " The name of the person is :" << endl;
		cin >> name;
	}

	void setage()
	{
		cout << "The age of the person is :" << endl;
		cin >> age;
	}
	person* address()
	{
		return this;
	}
};

class student :virtual public person
{

public:

	int studentid;
	float gpa;

	student(int id = 0, float gp = 0.0)
	{
		studentid;
		gpa = gp;
	}

	void setstdid(int id)
	{
		studentid = id;
	}

	void setstdgpa(float gp)
	{
		gpa = gp;
	}
	student* address()
	{
		return this;
	}

};

class employee :virtual public person
{

public:

	int employeeid;
	float salary;
	employee(int id = 0, float S= 0)
	{
		employeeid = id;
		salary = S;
	}

	void setemployeeid()
	{
		employeeid = id;
	}
	void setemsalary(float S)
	{
			salary = S;
	}
	employee* address()
	{
		return this;
	}
};

class functionality : public student, public employee
{
public:

	void assign(string opt)
	{
		int id;
		float G;
		setname();
		setage();

		if (opt == "s")
		{
			cout << "The id of the student is :" << endl;
			cin >> id;
			setstdid(id);
			cout << "Enter the GPA of Student :" << endl;
			cin >> G;
			setstdgpa(G);
		}

		if (opt == "e")
		{
			cout << "The id of the employee is :" << endl;
			cin >> id;
			setemployeeid();
			cout << "the salary of the employee is :" << endl;
			cin >> G;
			setemsalary(G);
		}
	}

	void change(string ch)
	{
		;
		int ID;
		int choices;
		float s;
		cout << " Input your entries according to your choices:" << endl;
		cout << "1. The name changes:" << endl;
		cout << "2. The age changes:" << endl;
		cout << "3. the id changes:" << endl;
		cout << "4. The salary gpa changes:" << endl;
		cin >> choices;
		if (choices == 1)
		{
			setname();
		}
		else if (choices ==2)
	 
		{
			setage();
		}
		else if (choices == 3)
		{
			cout << "The new id of employee is :" << endl;
			cin >> ID;
			if (ch == "e")
			{
				setemployeeid(id);
			}
			if (ch == "s")
			{
				setstdid(ID);
			}
		}
		if (choices == 4)
		{
			cout << "Enter A New Salary/GPA:" << endl;
			cin >> s;
			if (ch == "e")
			{
				setemsalary(s);
			}
			if (ch == "s")
			{
				setstdgpa(s);
			}
		}
	}


	void deleted()
	{
		name = " ";
		age = 0;
		employeeid = 0;
		salary = 0;
		gpa = 0.0;
		studentid=0;
	}

	void display(string ch)
	{
		cout << "Name = " << name << endl;
		cout << "Age = " << age << endl;
		if (ch == "e")
		{
			cout << "Employee's ID = " << employeeid << endl;
			cout << "Employee's Salary = " << salary << endl;
		}

		else if (ch == "s")
		{
			cout << "Student's ID = " << studentid << endl;
			cout << "Student's GPA = " << gpa << endl;
		}
	}

	void choice()
	{
		string ch;
		int i = 0;
		cout << "Enter Who's record you want to store:" << endl;
		cin >> ch;
		assign(ch);
		do
		{

			cout << "Enter your Choices According to Options Given Below :" << endl;
			cout << "1. To Update Record :" << endl;
			cout << "2. To Delete the Record :" <<endl;
			cout << "3. To Display the Record :" << endl;
			cout << "4. For Exit  ::" << endl;
			cout << endl;
			cin >> i;
			if (i == 1)
			{
				change(ch);
			}
				
			else if (i == 2)
			{
				deleted();
			}
				
			else if (i == 3)
			{
				display(ch);
			}
				
			else if (i == 4)
			{
				return;
			}
				
		} while (i != 4);
	}

	functionality* printaddress(void)
	{

		return this;
	}

};
int main()
{
	person P, P1;
	student S, S1;
	employee E, E1;
	functionality F, F1;
	F.choice();
	cout << "Addresses of Person Class :" << endl;
	cout << "Address of P :" << P.address() << endl;
	cout << "Address of P1 :" << P1.address() << endl;

	cout << "Addresses of Student Class :" << endl;
	cout << "Address of S :" << S.address() << endl;
	cout << "Address of S1 :" << S1.address() << endl;

	cout << "Addresses of Employee Class :" << endl;
	cout << "Address of E :" << E.address() << endl;
	cout << "Address of E1 :" << E1.address() << endl;

	cout << "Addresses of Functionality Class :"<<endl;
	cout << "Address of F :" << F.printaddress() << endl;
	cout << "Address of F1 :" << F1.printaddress() << endl;
	system("pause");
	return 0;
}
