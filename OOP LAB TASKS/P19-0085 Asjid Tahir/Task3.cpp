#include<iostream>
#include<string>
using namespace std;
class worker
{
private:
	string* worker_name;
	string SSN;
public:
	worker()
	{
		worker_name = new string;
		worker_name = 0;
		SSN = "xxx-xx-xxxx";
	}
	worker(string name)
	{
		worker_name = &name;
	}
	void setWorkerName(string name)
	{
		worker_name = &name;
	}
	void setSSN(string ssn)
	{
		SSN = ssn;
	}
	string getWorkerName()
	{
		return *worker_name;
	}
	string getSSN()
	{
		return SSN;
	}
	virtual void printValues()
	{
		cout << "The name of the worker is :" << endl;
		cout << *worker_name;
		cout << "The social security number of worker is :" << endl;
		cout << SSN;
		cout << endl;
	}
	~worker() //destructor
	{
		delete worker_name;
	}
};
class pay_worker : public worker
{
private:
	int dependants;
	double pay_rate;
public:
	void setPayRate(double pay_rate)
	{
		this->pay_rate = pay_rate;
	}

	void setDependents(int depandants)
	{
		this->dependants = dependants;
	}
	double getPayRate()
	{
		return pay_rate;
	}
	int getDependents()
	{
		return dependants;
	}
	void printValues(worker& foo)
	{
		foo.printValues();
		cout << "The pay rate of a worker is :" << pay_rate << endl;
		cout << "The total number of dependants are : " << dependants << endl;
		cout << endl;
	}
};
int main()
{
	pay_worker person;
	float pay_rate;
	string name;
	string ssn;
	cout << "The name of a person is :" << endl;
	cin >> name;
	cout << "The SSN of a person is :" << endl;
	cin >> ssn;
	cout << "The payrate of a worker is :"<<endl;
	cin >> pay_rate;
	person.setWorkerName(name);
	person.setSSN(ssn);
	person.setPayRate(pay_rate);
	person.setDependents(5);
	cout << "In Base class Worker, workerName is " << person.getWorkerName() << endl;
	cout << "In Base class Worker, SSN is " << person.getSSN() << endl;
	cout << "In derived class payWorker, payRate is $" << person.getPayRate() << endl;
	cout << "In derived class payWorker, dependent(s) are " << person.getDependents() << endl;
	person.printValues(person);
	system("pause");
	return 0;
}
