#include<iostream>
#include<string>
using namespace std;
class cars
{
private:
	string companyname;
	string modelname;
	float mileage;
	double price;
	string fueltype;
public:
	cars()
	{
		cout << "Default constructor created:" << endl;    //Default constructur
	}
	cars(string cname, string mname, float ml, double pr, string ft) //Parametrized constructor
	{
		cout << "Parametrized Constructor called:" << endl;
		cout << endl;
		companyname = cname;
		modelname = mname;
		mileage = ml;
		price = pr;
		fueltype = ft;
	}
	cars(cars& foo) //Copy Constructor (Reference to the object which is passed)
	{
		cout << "Copy Constructor called:" << endl;
		cout << endl;
		companyname = foo.companyname;
		modelname = foo.modelname;
		mileage = foo.mileage;
		price = foo.price;
		fueltype = foo.fueltype;
	}
	void setdata(string cname, string mname, float ml, double pr, string ft)   //Member Functions
	{
		companyname = cname;
		modelname = mname;
		mileage = ml;
		price = pr;
		fueltype = ft;
	}
	void displaydata()
	{
		cout << "       Features of Car       " << endl;
		cout << " Car company:" <<companyname<< endl;
		cout << "Car model name:" <<modelname<< endl;
		cout << "Car mileage per hour:" << mileage<<endl;
		cout << "Car prize:" <<price<< endl;
		cout << "Car fuel type:" << fueltype<< endl;
		cout << endl;
	}
};
int main()
{
	cars car1, car2("Toyota", "Fortuner", 65, 546737, "petrol");  //Parametrized Constructor
	car1.setdata("Honda", "Civic_X", 65, 400000, "Hight Octane");  //Default constructor
	car1.displaydata();
	car2.displaydata();
	cars car3 = car1; //Copy Constructed Called
	car3.displaydata();
	system("pause");
	return 0;
}