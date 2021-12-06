#include <string>
#include <iostream>

using namespace std;

class Employee
{
public:
	int EmpNumber;
    string EmpName;
    string EmpJob;
    string EmpType;
    string EmpDoj;
    int  EmpSal;
    int EmpDeptNo;
    int PossPortNumber;

public:

	Employee(int EmpNumber, string EmpName, string EmpJob, string EmpType, string EmpDoj, int EmpSal, int EmpDeptNo, int PossPortNumber)
	{
		EmpNumber = EmpNumber;
		EmpName = EmpName;
		EmpJob = EmpJob;
		EmpType = EmpType;
		EmpDoj = EmpDoj;
		EmpSal = EmpSal;
		EmpDeptNo = EmpDeptNo;
		PossPortNumber = PossPortNumber;
	}
    //Ploymorphis Function Oveloading CompileTime
	Employee(int EmpNumber, string EmpName, string EmpJob, int EmpDeptNo, int PossPortNumber)
	{
		EmpNumber = EmpNumber;
		EmpName = EmpName;
		EmpJob = EmpJob;
		EmpDeptNo = EmpDeptNo;
		PossPortNumber = PossPortNumber;
	}

    addEmployeeName(string x){
        cout<< x <<endl;
        cout<< "PArent name" <<endl;
    }
    //Abstract Class Implimentation
    virtual void fun() = 0; 

	void setEmpNumber(int n)
	{
		EmpNumber = n;
	}
	void setEmpName(string n)
	{
		EmpName = n;
	}
	void setEmpJob(string n)
	{
		EmpJob = n;
	}
	void setEmpType(string n)
	{
		EmpType = n;
	}
	void setEmpDoj(string doj)
	{
		EmpDoj = doj;
	}
    void setEmpSal(int n)
	{
		EmpSal = n;
	}
	void setEmpDeptNo(int n)
	{
		EmpDeptNo = n;
	}
	void setPossPortNumber(int n)
	{
	    PossPortNumber = n;
	}

	int const getEmpNumber()
	{
		return EmpNumber;
	}
	string const getEmpName()
	{
		return EmpName;
	}
	string const getEmpJob()
	{
		return EmpJob;
	}
	string const getEmpType()
	{
		return EmpType;
	}
	string const getEmpDoj()
	{
		return EmpDoj;
	}
	int const getEmpSal()
	{
		return EmpSal;
	}
	int const getEmpDeptNo()
	{
		return EmpDeptNo;
	}
    	int const getPossPortNumber()
	{
		return PossPortNumber;
	}
};

class DepartmenEmployeeeAddress: public Employee
{
public:
	int PossPortNumber  ;
    string CountryName;
    string CityName;
    string VillageName;
    int PinCodeNumber;

public:
	DepartmenEmployeeeAddress(int PossPortNumber, string CountryName, string CityName, string VillageName, int PinCodeNumber)
	{
		PossPortNumber = PossPortNumber;
		CountryName = CountryName;
		CityName = CityName;
		VillageName = VillageName;
		PinCodeNumber = PinCodeNumber;
	}

    //Ploymorphis Function Overriding rutime virtual function
    addEmployeeName(string x){
        cout<< x <<endl;
        cout<< "Child name" <<endl;
    }
    //Abstract Method
        virtual void fun(){
         cout << "In Derived \n";
        } 

	void setPossPortNumber(int n)
	{
		PossPortNumber = n;
	}
	void setCountryName(string n)
	{
		CountryName = n;
	}
	void setCityName(string n)
	{
		CityName = n;
	}
	void setVillageName(string n)
	{
		VillageName = n;
	}
	void setPinCodeNumber(int doj)
	{
		PinCodeNumber = doj;
	}
    

	int const getPossPortNumber()
	{
		return PossPortNumber;
	}
	string const getCountryName()
	{
		return CountryName;
	}
	string const getCityName()
	{
		return CityName;
	}
	string const getVillageName()
	{
		return VillageName;
	}
	int const getPinCodeNumber()
	{
		return PinCodeNumber;
	}
};


class Department: public DepartmenEmployeeeAddress
{
private:
	int DeptNumber ;
    string DeptName;
    string DeptLocation;

public:
	Department(int DeptNumber, string DeptName, string DeptLocation)
	{
		DeptNumber = DeptNumber;
		DeptName = DeptName;
		DeptLocation = DeptLocation;
	}
    // Dependant
    DepartmenEmployeeeAddress *pEmployee;

	void setDeptNumber(int n)
	{
		DeptNumber = n;
	}
	void setDeptName(string n)
	{
		DeptName = n;
	}
	void setDeptLocation(string n)
	{
		DeptLocation = n;
	}

	int const getDeptNumber()
	{
		return EmpNumber;
	}
	string const getDeptName()
	{
		return DeptName;
	}
	string const getDeptLocation()
	{
		return DeptLocation;
	}
	
};
int main()
{
    DepartmenEmployeeeAddress d; 
    d.fun(); 
    return 0; 

}