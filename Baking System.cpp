#include<iostream>
#include<string>
using namespace std;
class BankAccount
{
private:
	int acount_number;
	string name;
	string Father_name;
	double CNIC;
	int date_of_birth;
public:
	BankAccount() // constructor
	{
		acount_number=0;
		name="";
		Father_name="";
		CNIC=0;
		date_of_birth=0;
	}
	BankAccount(string N, int Father_N,double C,int D) // constructor with parameters
	{
		name=N;
		Father_name=Father_N;
		CNIC=C;
		date_of_birth=D;
	}
	void Bank_name()
	{
		cout<<"**************WELLCOME TO MEEZAN BANK**************"<<endl;
		cout<<endl;
		cout<<"We are Happy That You Come to This Bank (for opening account)"<<endl;
	}
	void SetName(string N)
	{
		name=N;
	}
	void inName()
	{
		cout<<"PLease Enter Your Name :: ";
		cin>>name;
	}
	void outname()
	{
		cout<<"Your Name is :: "<<name<<endl;
	}
	void SET_F_N(string F_N)
	{
		Father_name=F_N;
	}
	void IN_F_N()
	{
		cout<<"Please enter your Father Name :: ";
		cin>>Father_name;
	}
	void outFathername()
	{
		cout<<"Your Father Name is :: "<<name<<endl;
	}
	void set_cnic(double cnic)
	{
		CNIC=cnic;
	}
	void in_cnic()
	{
		cout<<"Please Enter you Cnic without (-) :: ";
		cin>>CNIC;
	}
	void outcinc()
	{
		cout<<"Your CNIN is :: "<<CNIC<<endl;
	}
	void Set_DOB(int DOB)
	{
		date_of_birth=DOB;
	}
	void in_DOB()
	{
		cout<<"Please Enter you Date of Birth in form (dateMonthYear) without spaces :: ";
		cin>>date_of_birth;
	}
	void outdob()
	{
		cout<<"Your Date of birth is :: "<<date_of_birth<<endl;
	}
	void Show_choices()
	{
		cout<<"Here We Provide (3) Three Types Of Accounts to our costomer !!!"<<endl<<endl;
		cout<<"1) Certificate of deposit"<<endl;
		cout<<"2) Savings Accounts"<<endl;
		cout<<"3) Checking Account"<<endl;
	}
};
class Certificate_of_deposit  : public BankAccount
{
private:
	double interest_Rate;
	int account_number;
	int Current_month;
public:
	Certificate_of_deposit() //constructor
	{
		account_number=0;
		interest_Rate=0;
		Current_month=0;
	}
	Certificate_of_deposit(int ACC_N, double Int_Rat,int Curr_mon)//parametric constructor
	{
		account_number=ACC_N;
		interest_Rate=Int_Rat;
		Current_month=Curr_mon;
	}
	void Set_CheckingAccount(int ACC_N, double Int_Rat,int Curr_mon)
	{
		account_number=ACC_N;
		interest_Rate=Int_Rat;
		Current_month=Curr_mon;
	}
	void choice1()
	{
		Current_month=5;
		interest_Rate=2.5;
		account_number=3541234;
		cout<<"Thanks for Choosing Checking Account"<<endl;
		cout<<"Your Account Number is :: "<<account_number<<endl;
		cout<<"Your cunrrent month is :: "<<Current_month<<endl;
		cout<<"The interest Rate for that account is  :: "<<interest_Rate<<endl;
	}
};
class SavingAccount: public Certificate_of_deposit
{
private:
	double High_Interest;
	double Low_interest;
	int OPening_Charges;
public:
	SavingAccount()  // constructor
	{
		High_Interest=0;
		Low_interest=0;
		OPening_Charges=0;
	}
	SavingAccount(double H_S,double L_S,int Charges)  //parametric constructor
	{
		High_Interest=H_S;
		Low_interest=L_S;
		OPening_Charges=Charges;
	}
	void Set_SavingAccount(double H_C,double L_S,int Charges)
	{
		High_Interest=H_C;
		Low_interest=L_S;
		OPening_Charges=Charges;
	}
	void Low_interestAccount()
	{
		OPening_Charges=25;
		Low_interest=30;
		cout<<"Thanks For selecting !!!"<<endl;
		cout<<"In this account We offer you having No Low Balance Limit !!!"<<endl;
		cout<<"Also We offer you A very Low Interest Rate Of Yearly !!!"<<endl;
		cout<<"Only Opening Account Fee is high But You Feel Free from yearly Large amount of interst !!!"<<endl<<endl;
		cout<<"The opening Charges of the Bank account is :: "<<OPening_Charges<<"$"<<endl;
		cout<<"The Yearly Interest Rate of the Low Interesting Account is :: "<<Low_interest<<"$"<<endl;
	}
	void High_InterestAccount()
	{
		OPening_Charges=20;
		High_Interest=50;
		cout<<"Thanks For selecting !!!"<<endl;
		cout<<"In this account We offer you having Low Balance Limit !!!"<<endl;
		cout<<"Also We offer you A High Interest Rate Of Yearly !!!"<<endl;
		cout<<"Only Opening Account Fee is Low But You get yearly Large amount of interst !!!"<<endl<<endl;
		cout<<"The opening Charges of the Bank account is :: "<<OPening_Charges<<"$"<<endl;
		cout<<"The Yearly Interest Rate of the Low Interesting Account is :: "<<High_Interest<<"$"<<endl;
	}
	void Set_All()
	{
		int n;
		cout<<"Thanks for choosing Saving Account"<<endl;
		cout<<"We Offer (2) Two Types of Saving Accounts "<<endl;
		cout<<"1) Having No minimum Balance & having Low Interest Rate !!!"<<endl;
		cout<<"2) Having Minimum Balance & Having High interest Rate !!!"<<endl;
		cout<<"Choose What type of Account do you want !!!"<<endl;
		cin>>n;
		if(n==1)
		{
			Low_interestAccount();
		}
		if(n==2)
		{
			High_InterestAccount();
		}
		else
		{
			cout<<"Invalide Option"<<endl;
		}	
	}
};
class CheckingAccount :public SavingAccount
{
private:
	double service_charges;
	double Monthly_Charges;
	int Limit_Check_writing; 
	double Low_blnc;
	double interest_r;
	double max_blnc;
public:
	CheckingAccount()  // constructor
	{
		service_charges=0;
		Monthly_Charges=0;
		Limit_Check_writing;
		Low_blnc=0;
		interest_r=0;
		max_blnc=0;
	}
	CheckingAccount(double S_CH,double MO_CH,int L_C_W,double L_B,double I_R, double MAX)
	{
		service_charges=S_CH;
		Monthly_Charges=MO_CH;
		Limit_Check_writing=L_C_W;
		Low_blnc=L_B;
		interest_r=I_R;
		max_blnc=MAX;
	}
	void FirstChoice()
	{
		Monthly_Charges=2;
		Limit_Check_writing=30;
		cout<<"Thanks for selecting"<<endl;
		cout<<"This account Having Monthly Service Charges which you have to pay"<<endl;
		cout<<"Also You have a Limit for Check Writing"<<endl;
		cout<<"Also You don't get Any Interest"<<endl<<endl;
		cout<<"The Monthly Service Charges are :: "<<Monthly_Charges<<"$"<<endl;
		cout<<"The Limit Of check writing is :: "<<Limit_Check_writing<<endl;
		cout<<"In this Account you get Interest of :: "<<0<<"$"<<endl;
	}
	void SecondChoice()
	{
		Low_blnc=0.25;
		interest_r=13;
		cout<<"Thanks for selecting"<<endl;
		cout<<"This account Having No Monthly Service Charges"<<endl;
		cout<<"This Account Have Minimum Balace requirment"<<endl;
		cout<<"Also You have Unlimit for Check Writing"<<endl;
		cout<<"Also You get Lower Interest"<<endl<<endl;
		cout<<"The Monthly Service Charges are :: "<<0<<"$"<<endl;
		cout<<"The Minimum Balance required is :: "<<Low_blnc<<"$"<<endl;
		cout<<"The UnLimit Of check writing is allowed :: "<<"Unlimited"<<endl;
		cout<<"In this Account you get Interest of :: "<<interest_r<<"$"<<endl;
	}
	void ThirdChoice()
	{
		max_blnc=10;
		interest_r=30;
		cout<<"Thanks for selecting"<<endl;
		cout<<"This account Having No Monthly Service Charges"<<endl;
		cout<<"This Account Have Maximum Balace requirment"<<endl;
		cout<<"Also You have Unlimit for Check Writing"<<endl;
		cout<<"Also You get Higher Interest"<<endl<<endl;
		cout<<"The Monthly Service Charges are :: "<<0<<"$"<<endl;
		cout<<"In this Account you get Interest of :: "<<interest_r<<"$"<<endl;
		cout<<"The Maximum Balance required is :: "<<max_blnc<<"$"<<endl;
		cout<<"The UnLimit Of check writing is allowed :: "<<"Unlimited"<<endl;
		

	}
	void Choice2()
	{
		int x;
		cout<<"Thanks for choosing Checking Account"<<endl;
		cout<<"We Offer (3) Three Types Of Checking Accounts"<<endl;
		cout<<"1) Having monthly service charge, limited check writing, no minimum balance, & no interest"<<endl;
		cout<<"2) Having no monthly service charge, a minimum balance requirement, unlimited check writing & lower interest"<<endl;
		cout<<"3) no monthly service charge, a higher minimum requirement, a higher interest rate,& unlimited check writing."<<endl<<endl;
		cout<<"Choose which type of account do you want to open !!!"<<endl;
		cin>>x;
		if(x==1)
		{
			FirstChoice();
		}
		if(x==2)
		{
			SecondChoice();
		}
		if(x==3)
		{
			ThirdChoice();
		}
	}
	void Inherit_All_Main_Funtions()
	{

		int y;
		cout<<"Enter the Acount number That you wanted to open !!!"<<endl;
		cin>>y;
		if(y==1)
		{
			choice1();
		}
		if(y==2)
		{
			Set_All();
		}
		if(y==3)
		{
			Choice2();
		}
	}
	void Get_information()
	{
		cout<<endl;
		cout<<"Now We want to Collect Some Information From You For Opening account !!!!"<<endl;
		cout<<"Kindly Answer the Following Questions To record your Information in Bank !!!"<<endl<<endl;
		inName();
		IN_F_N();
		in_cnic();
		in_DOB();
	}

	void Congratutaion()
	{
		cout<<endl;
		cout<<"Congratulations From Meezan Bank"<<endl;
		cout<<"Your Account has been open in Meezan Bank"<<endl<<endl;
		cout<<"The folowing is information of your account"<<endl;
		outname();
		outFathername();
		outcinc();
		outdob();
		cout<<"your bank account number is :: "<<35423779<<endl;
		cout<<"And bank Account type is selected according to your selected choice"<<endl;
		cout<<"Thanks for Choosing Meezan Bank (The Islamic Bank Of Pakistan)"<<endl<<endl;
	}
};
int main()
{
	CheckingAccount o;
	o.Bank_name();
	o.Show_choices();
	o.Inherit_All_Main_Funtions();
	o.Get_information();
	o.Congratutaion();
	system("pause");
	return 0;
}
