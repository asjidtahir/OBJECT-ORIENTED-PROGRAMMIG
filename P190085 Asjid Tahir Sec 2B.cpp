#include<iostream>
#include<string>
#include"certificateOfDeposit"
#include"highInterestChecking"
#include"highInterestSavings"
#include"serviceChargeChecking"
using namespace std;
const int MAX_CHECKS = 5;
const double SVC_CHARGE = 10.0l;
class bankAccount
{
public:
	bankAccount(int acctNum, string name, double initialBalance)
	{
		m_AcctNumber = acctNum;
		m_Name = name;
		m_Balance = initialBalance;
	}
	~bankAccount(void) {}
	string get_Name()
	{
		return m_Name;
	}
	int get_AcctNumber()
	{
		return m_AcctNumber;
	}
	double get_Balance()
	{
		return m_Balance;
	}
	void deposit(double amount)
	{
		m_Balance += amount;
		cout << "$" << amount << " has been deposited to your account" << endl;
	}
	virtual void withdraw(double amount) = 0;
	virtual void printStatement() = 0;
	virtual void printSummary()
	{
		cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
		cout << endl << setw(25) << "" << "Account Summary" << endl << endl;
		cout << setw(25) << "Name: " << m_Name << endl;
		cout << setw(25) << "Account #: " << m_AcctNumber << endl;
		cout << setw(25) << "Current Balance: $" << m_Balance << endl;
	}
protected:
	string m_Name;
	int m_AcctNumber;
	double m_Balance;
};
class certificateOfDeposit :
	public bankAccount
{
public:
	certificateOfDeposit(int acctNum, string name, double initialBalance, int matMon)
		: bankAccount(acctNum, name, initialBalance)
	{
		m_MaturityMonths = matMon;
		m_CurrentMonth = 1;
		m_InterestRate = 4.75;
	}
	~certificateOfDeposit(void) {}
	void withdraw(double amount)
	{
		if (m_Balance - amount < 0)
		{
			cout << "Declined: Insufficient funds remain to withdraw that amount" << endl;
			return;
		}
		m_Balance -= amount;
	}
	void printSummary()
	{
		bankAccount::printSummary();
		cout << setw(25) << "Interest rate: " << m_InterestRate << "%" << endl;
		cout << setw(25) << "Maturity Months: " << m_MaturityMonths << endl;
		cout << setw(25) << "Current Month: " << m_CurrentMonth << endl;
		cout << endl << setw(60) << setfill('-') << "" << setfill(' ') << endl;
	}
	void printStatement()
	{
		printSummary();
		cout << "A full implementation would also print a Certificate of Deposite Account Statement here." << endl;
	}
private:
	double m_InterestRate;
	int m_MaturityMonths;
	int m_CurrentMonth;
};
class checkingAccount :
	public bankAccount
{
public:
	checkingAccount(int acctNum, string name, double initialBalance)
		: bankAccount(acctNum, name, initialBalance)
	{
	}
	~checkingAccount(void) {}
	virtual void writeCheck(double amount) = 0;
	void withdraw(double amount)
	{
		if (m_Balance - amount < 0)
		{
			cout << "Declined: Insufficient funds remain to withdraw that amount" << endl;
			return;
		}
		if (m_Balance - amount < m_MinimumBalance)
		{
			cout << "Declined: Minimum balance requirement prohibits this withdrawal" << endl;
			return;
		}
		m_Balance -= amount;
	}
	void printStatement()
	{
		printSummary();
		cout << endl << "A full implementation would also print details of a Checking Account Statement here." << endl << endl;
	}
protected:
	double m_InterestRate;
	int m_ChecksRemaining;
	double m_MinimumBalance;
};
class highInterestChecking :
	public noServiceChargeChecking
{
public:
	highInterestChecking(int acctNum, string name, double initialBalance)
		: noServiceChargeChecking(acctNum, name, initialBalance)
	{
		m_InterestRate = 5.0; 
		m_ChecksRemaining = -1;
		m_MinimumBalance = 1000; 
	}
	~highInterestChecking(void) {}
};
class highInterestSavings :
	public savingsAccount
{
public:
	highInterestSavings(int acctNum, string name, double initialBalance)
		: savingsAccount(acctNum, name, initialBalance)
	{
		m_MinimumBalance = 5000;
	}
	~highInterestSavings(void) {}
	void withdraw(double amount)
	{
		if (m_Balance - amount < 0)
		{
			cout << "Declined: Insufficient funds remain to withdraw that amount" << endl;
			return;
		}
		if (m_Balance - amount < m_MinimumBalance)
		{
			cout << "Declined: Minimum balance requirement prohibits this withdrawal" << endl;
			return;
		}
		m_Balance -= amount;
	}
	void printSummary()
	{
		bankAccount::printSummary();

		cout << setw(25) << "Interest rate: " << m_InterestRate << "%" << endl;
		cout << setw(25) << "Minimum Balance: $" << m_MinimumBalance << endl << endl;
		cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
	}
protected:
	double m_MinimumBalance;
};
class noServiceChargeChecking :
	public checkingAccount
{
public:
	noServiceChargeChecking(int acctNum, string name, double initialBalance)
		: checkingAccount(acctNum, name, initialBalance)
	{
		m_InterestRate = 2.5; 
		m_ChecksRemaining = -1; 
		m_MinimumBalance = 500; 
	}
	~noServiceChargeChecking(void) {}
	void writeCheck(double amount)
	{
		if (m_Balance - amount < 0)
		{
			cout << "Declined: Insufficient funds remain to withdraw that amount" << endl;
			return;
		}
		m_Balance -= amount; 
	}
	void printSummary()
	{
		bankAccount::printSummary();
		cout << setw(25) << "Interest rate: " << m_InterestRate << "%" << endl;
		cout << setw(25) << "Minimum Balance: $" << m_MinimumBalance << endl;
		cout << setw(25) << "Unlimited checks   " << endl;
		cout << setw(25) << "No monthly service fee   " << endl;
		cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
	}
};
class savingsAccount :
	public bankAccount
{
public:
	savingsAccount(int acctNum, string name, double initialBalance)
		: bankAccount(acctNum, name, initialBalance)
	{
		m_InterestRate = 3.99;
	}
	~savingsAccount(void)
	{
	}
	void withdraw(double amount)
	{
		if (m_Balance - amount < 0)
		{
			cout << "Declined: Insufficient funds remain to withdraw that amount" << endl;
			return;
		}
		m_Balance -= amount;
	}
	void printSummary()
	{
		bankAccount::printSummary();
		cout << setw(25) << "Interest rate: " << m_InterestRate << "%" << endl << endl;
		cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
	}
	void printStatement()
	{
		printSummary();
		cout << "A full implementation would also print a Savings Account Statement here." << endl;
	}
protected:
	double m_InterestRate;
};
class serviceChargeChecking :
	public checkingAccount
{
public:
	serviceChargeChecking(int acctNum, string name, double initialBalance)
		: checkingAccount(acctNum, name, initialBalance)
	{
		m_InterestRate = 0; // No interest
		m_ChecksRemaining = MAX_CHECKS; // Limit of 5 checks
		m_MinimumBalance = 0; // No minimum balance
	}
	~serviceChargeChecking(void) {}
	void writeCheck(double amount)
	{
		if (m_ChecksRemaining == 0)
		{
			cout << "Declined: No more checks remaining this month" << endl;
			return;
		}
		if (m_Balance - amount < 0)
		{
			cout << "Declined: Insufficient funds remain to withdraw that amount" << endl;
			return;
		}
		m_ChecksRemaining--;
		m_Balance -= amount; 
	}
	void printSummary()
	{
		bankAccount::printSummary();
		cout << setw(25) << "Checks remaining: " << m_ChecksRemaining << endl;
		cout << setw(25) << "Monthly service fee: $" << SVC_CHARGE << endl;
		cout << setw(25) << "No interest " << endl;
		cout << setw(25) << "No Minimum Balance " << endl;
		cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
	}
};
void TestCheckingWithService()
{
	serviceChargeChecking acct(123, "Asjid Tahir", 5000);
	char input = 0;
	double amount;
	cout << " The Testing Checking with Service Charge" << endl;
	cout << "Current account overview:" << endl;
	acct.printSummary();
	cout << endl;
	while (input != 'x')
	{
		cout << "Select a transaction:" << endl;
		cout << "1 - Make a Withdrawal" << endl;
		cout << "2 - Make a Deposit" << endl;
		cout << "3 - Print Summary" << endl;
		cout << "4 - Print Monthly Statement" << endl;
		cout << "5 - Write a check" << endl;
		cout << "x - Exit Test Suite" << endl;
		cout << "Enter choice: ";
		cin >> input;
		switch (input)
		{
		case '1':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.withdraw(amount);
			break;
		case '2':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.deposit(amount);
			break;
		case '3':
			acct.printSummary();
			break;
		case '4':
			acct.printStatement();
			break;
		case '5':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.writeCheck(amount);
			break;
		case '6':
			break;
		case 'x':
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
		acct.printSummary();
		cout << endl;
	}
}
void TestCheckingNoService()
{
	noServiceChargeChecking acct(123, "Ahmed Tahir", 5000);
	char input = 0;
	double amount;
	cout << "Testing Checking without Service Charge" << endl;
	cout << "Current account overview:" << endl;
	acct.printSummary();
	cout << endl;
	while (input != 'x')
	{
		cout << "Select a transaction:" << endl;
		cout << "1 - Make a Withdrawal" << endl;
		cout << "2 - Make a Deposit" << endl;
		cout << "3 - Print Summary" << endl;
		cout << "4 - Print Monthly Statement" << endl;
		cout << "5 - Write a check" << endl;
		cout << "x - Exit Test Suite" << endl;
		cout << "Enter choice: ";
		cin >> input;
		switch (input)
		{
		case '1':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.withdraw(amount);
			break;
		case '2':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.deposit(amount);
			break;
		case '3':
			acct.printSummary();
			break;
		case '4':
			acct.printStatement();
			break;
		case '5':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.writeCheck(amount);
			break;
		case '6':
			break;
		case 'x':
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
		acct.printSummary();
		cout << endl;
	}
}
void TestCheckingHighInterest()
{
	highInterestChecking acct(123, "Asjid Tahir", 5000);
	char input = 0;
	double amount;
	cout << "\t\tTesting Checking with High Interest" << endl << endl;
	cout << "Current account overview:" << endl;
	acct.printSummary();
	cout << endl;
	while (input != 'x')
	{
		cout << "Select a transaction:" << endl;
		cout << "1 - Make a Withdrawal" << endl;
		cout << "2 - Make a Deposit" << endl;
		cout << "3 - Print Summary" << endl;
		cout << "4 - Print Monthly Statement" << endl;
		cout << "5 - Write a check" << endl;
		cout << "x - Exit Test Suite" << endl;
		cout << "Enter choice: ";
		cin >> input;
		switch (input)
		{
		case '1':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.withdraw(amount);
			break;
		case '2':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.deposit(amount);
			break;
		case '3':
			acct.printSummary();
			break;
		case '4':
			acct.printStatement();
			break;
		case '5':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.writeCheck(amount);
			break;
		case '6':
			break;
		case 'x':
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
		acct.printSummary();
		cout << endl;
	}
}
void TestSavings()
{
	savingsAccount acct(123, "Asjid Tahir", 1000);
	char input = 0;
	double amount;
	cout << "Testing Regular Savings" << endl;
	cout << "Current account overview:" << endl;
	acct.printSummary();
	cout << endl;
	while (input != 'x')
	{
		cout << "Select a transaction:" << endl;
		cout << "1 - Make a Withdrawal" << endl;
		cout << "2 - Make a Deposit" << endl;
		cout << "3 - Print Summary" << endl;
		cout << "4 - Print Monthly Statement" << endl;
		cout << "x - Exit Test Suite" << endl;
		cout << "Enter the amount:" << endl;
		cin >> input;
		switch (input)
		{
		case '1':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.withdraw(amount);
			break;
		case '2':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.deposit(amount);
			break;
		case '3':
			acct.printSummary();
			break;
		case '4':
			acct.printStatement();
			break;
		case 'x':
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
		acct.printSummary();
		cout << endl;
	}
}
void TestSavingsHighInterest()
{
	highInterestSavings acct(123, "Asjid Tahir", 8000);
	char input = 0;
	double amount;
	cout << "Testing High Interest Savings" << endl;
	cout << "Current account overview:" << endl;
	acct.printSummary();
	cout << endl;
	while (input != 'x')
	{
		cout << "Select a transaction:" << endl;
		cout << "1 - Make a Withdrawal" << endl;
		cout << "2 - Make a Deposit" << endl;
		cout << "3 - Print Summary" << endl;
		cout << "4 - Print Monthly Statement" << endl;
		cout << "x - Exit Test Suite" << endl;
		cout << "Enter the amount:" << endl;
		cin >> input;
		switch (input)
		{
		case '1':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.withdraw(amount);
			break;
		case '2':
			cout << "Enter the amount:" << endl;
			cin >> amount;
			acct.deposit(amount);
			break;
		case '3':
			acct.printSummary();
			break;
		case '4':
			acct.printStatement();
			break;
		case 'x':
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
		acct.printSummary();
		cout << endl;
	}
}
void TestCertificateOfDeposit()
{
	certificateOfDeposit acct(123, "Asjid Tahir", 10000, 6);
	char input = 0;
	double amount;
	cout << "Testing High Interest Savings" << endl;
	cout << "Current account overview:" << endl;
	acct.printSummary();
	cout << endl;
	while (input != 'x')
	{
		cout << "Select a transaction:" << endl;
		cout << "1 - Make a Withdrawal" << endl;
		cout << "2 - Make a Deposit" << endl;
		cout << "3 - Print Summary" << endl;
		cout << "4 - Print Monthly Statement" << endl;
		cout << "x - Exit Test Suite" << endl;
		cout << "Enter choice: ";
		cin >> input;
		switch (input)
		{
		case '1':
			cout << "Enter amount: ";
			cin >> amount;
			acct.withdraw(amount);
			break;
		case '2':
			cout << "Enter amount: ";
			cin >> amount;
			acct.deposit(amount);
			break;
		case '3':
			acct.printSummary();
			break;
		case '4':
			acct.printStatement();
			break;
		case 'x':
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
		acct.printSummary();
		cout << endl;
	}
}
int main()
{
	char input;
	cout << "Welcome to the Bank Account Test Suite" << endl;
	cout << "What type of account do you want to test?" << endl;
	cout << "1 - Checking with Service Charge" << endl;
	cout << "2 - Checking without Service Charge" << endl;
	cout << "3 - Checking with High Interest" << endl;
	cout << "4 - Savings" << endl;
	cout << "5 - Savings with High Interest" << endl;
	cout << "6 - Certificate of Deposit" << endl;
	cout << "Enter choice: ";
	cin >> input;
	switch (input)
	{
	case '1':
		TestCheckingWithService();
		break;
	case '2':
		TestCheckingNoService();
		break;
	case '3':
		TestCheckingHighInterest();
		break;
	case '4':
		TestSavings();
		break;
	case '5':
		TestSavingsHighInterest();
		break;
	case '6':
		TestCertificateOfDeposit();
		break;
	default:
		cout << "Invalid choice" << endl;
		break;
	}
}

