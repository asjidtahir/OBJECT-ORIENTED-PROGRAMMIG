#include<iostream>
#include<string>
using namespace std;

class complex
{
public:
	int real, imginary;
	complex(int r = 0, int i = 0)
	{
		cout << " Your constructor created:" << endl;
		real = r;
		imginary = i;
	}
	void set()
	{
		cout << " The first real number is :" << endl;
		cin >> real;
		cout << " The first imaginary number is :" << endl;
		cin >> imginary;

	}

};


class add :public complex
{
public:
	int sumreal, sumimg, real1, img1;
	add(int r = 0, int i = 0, int r1 = 0, int i1 = 0)
	{
		real1 = r;
		img1 = i;
		sumreal = r1;
		sumimg = i1;
	}
	void setcomplex()
	{

		cout << " The Second real number is :" << endl;
		cin >> real1;
		cout << "Enter the second imaginary number is :" << endl;
		cin >> img1;
	}

	friend class Difference;
	void addC()
	{
		sumreal = real + real1;
		sumimg = imginary + img1;
		cout << "The sum of complex number is =" << sumreal << "+" << sumimg << "i" << endl;
	}

};

class Difference
{
public:
	int real2, imaginary2;
	Difference(int r = 0, int i = 0)
	{
		real2 = r;
		imaginary2 = i;
	}
	void set()
	{
		cout << "The third real number is :" << endl;
		cin >> real2;
		cout <<"the third imaginary number is :"<<endl;
		cin >> imaginary2;
	}


	void difference(add  Z)
	{
		int differencereal;
		int differenceimaginary;

		differencereal = Z.real - real2;
		differenceimaginary = Z.imginary - imaginary2;

		if (differenceimaginary >= 0 && differencereal >= 0)
		{
			cout << "The difference of complex number is =" << differencereal << "+" << differenceimaginary << "i" << endl;
		}
			
		else
			cout << "The difference of complex number is = " << differencereal << differenceimaginary << "i" << endl;
	}
};


int main()
{
	add foo;
	Difference foo1;
	foo.set();
	foo.setcomplex();
	foo.addC();
	foo1.set();
	foo1.difference(foo);
	system("pause");
	return 0;
}
