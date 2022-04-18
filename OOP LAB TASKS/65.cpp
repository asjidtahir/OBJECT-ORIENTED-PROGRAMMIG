#include<iostream>
#include<string>
using namespace std;
class enemy
{
public:
	int size;
	string colour;
	int health;
		enemy()
		{
			cout << "Default constructed created:" << endl;
		}
		enemy(string Col, int size,int h)
		{
			size = size;
			colour = Col;
			health = h;
		}
	virtual void attack() = 0;
	virtual void capture() = 0;
	virtual void destroyed() = 0;
};
class aliens : public enemy
{
public:
	string colour;
	int size;
	int health;
	string laserbean;
	string shoot;
	aliens()
	{
		health = 100;
		size = 10;
		colour = "Black";
	}
	void attack()
	{
		if (shoot == "laserbean")
		{
			cout << " Alien dead:" << endl;
		}
		else
		{
			cout << "Alien alive :" << endl;
		}

	}
	void capture()
	{
		if (shoot != "laserbean")
		{
			cout << " Our aliens should catch our enemy:" << endl;

		}
		else
		{
			cout << "Our alien dead:" << endl;
		}
	}
	void destroy()
	{
		if (health=0)
		{
			cout << " Our alien should be destroyed:" << endl;
		}
		else
		{
			cout << "Our aliens should not be destroyed:" << endl;
		}
	}
};
class Monsters : public enemy
{
public:
	string shoot;
	string colour;
	string highbeamweapon;
	int health;
	Monsters()
	{
		health = 100;
		colour == "Dark Black";
		highbeamweapon == " 0";
	}
	void attack()
	{
		if (highbeamweapon >= "5")
		{
			cout << "Monster is killed:" << endl;
		}
		else
		{
			cout << "Monster is alived :" << endl;
		}
	}
	void capture()
	{
		if (highbeamweapon != "5")
		{
			cout << " our enemy catched by the monster:" << endl;
		}
		else
		{
			cout << "Our monster dead: " << endl;
		}
	}
	void destroy()
	{
		if (health = 0)
		{
			cout << "Our monster should be destroyed:" << endl;
		}
		else
		{
			cout << " our monster is allived:" << endl;
		}
	}
};
	
