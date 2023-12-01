#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "admin.h"
#include"car.h"
#include"customer.h"
#include"human.h"
int main_menu(vector<customer> c, vector<admin> a);
void creating(  vector <customer> s);
int login(vector <customer> c, vector <admin> a);
int admin_login( vector<admin> a, string user_input, string password_input);
int cust_login(vector<customer> c, string user_input, string password_input);
void cust_menu(vector <car> crs ,  vector<customer> z , int indx);
void adminmenu(vector<car> crs);
void creating_car(vector <car> c);
void deleting_car(vector <car> c);
int main()
{
	int big_helper;
	vector <car> cars;
	car car0("none", "none", 0, 0.0, 0);
	cars.push_back(car0);
	car car1("BMW", "BLACK", 2020, 9.8, 1), car2("Hyonda", "white", 2019, 8, 2), car3("Tyota", "Gray", 2021, 9, 3); cars.push_back(car1); cars.push_back(car2); cars.push_back(car3);
	vector <customer> customers;
	customer c1("dedoxd2", "dudxd1", "dedo.xd3@yahoo.com", 50.3) , c2("dedoxd3", "dudxd12", "dedo.xd33@yahoo.com", 500.3), c3("dedoxd4", "dudxd123", "dedo.xd333@yahoo.com", 5000.3);
	//customer ;
//	customer c3("dedoxd4", "dudxd123", "dedo.xd333@yahoo.com", 5000.3);
	customers.push_back(c1);
	customers.push_back(c2);
	customers.push_back(c3);
	vector <admin> admins;
	admin admin1("admin1", "admin1");
	admin admin2("admin2", "admin2");
	admins.push_back(admin1);
	admins.push_back(admin2);
	do
	{
		big_helper = main_menu(customers, admins);
		
		if ( big_helper== 1)
		{
			//login(customers, admins);
			
			int helper = login(customers, admins);
			if (helper == -1)//admin
			{
				adminmenu(cars);
			}
			else if (helper!=-1&&helper!=0)//custmor
			{
				cust_menu(cars, customers, helper);
			}
			else
			{
				cout << "\nInvalid input try again \n";
			}
		}
		else if (big_helper==2)
		{
			creating(customers);

		}
		

	} while (big_helper!=0);
	// gonna do a whole loop for once atleast even if he pressed 0


	return 0;
}

int main_menu(vector<customer> c, vector<admin> a )
{
	cout << "Welcome u have account or wanna make one ?\n";
	cout << "enter 1 if u have account 2 for creating  a new one or 0 to close the program \n";
	int num ;
	cin >> num;
	
	return num;
}

void creating(  vector <customer> s)  // string user, string pass, string emai, float cash
{
	cout << "Enter ur user name pls\n";
	string user, pass,emai;
	cin >> user;
	cout << "\nEnter ur password \n";
	cin >> pass;
	cout << "\nEnter ur Email\n";
	cin >> emai;
	cout << "\nPls enter cash\n";
	float cash;
	cin >> cash;
	customer c1(user, pass, emai, cash);
	s.push_back(c1);
	cout << "Ur account has been done succefully\n";
	int helper = s.size();
	s[helper - 1].print_human();

}
// 1 for admin 2 for customer 
int login(vector<customer> c, vector<admin> a)  
{
	int helper = -1;
	string pas_input, us_input;
	cout << "Enter ur user name : ";
	cin >> us_input;
	cout << "\nEnter ur password : ";
	cin >> pas_input;
	//admin_login( a, us_input, pas_input)
	while (true)//!admin_login(a, us_input, pas_input)&&!cust_login( c,  us_input,  pas_input)
	{
		if (admin_login(a, us_input, pas_input) == -1)
		{
			helper = -1;
			break;
		}
		else if (cust_login(c,us_input,pas_input)!=0)
		{
			helper = cust_login(c, us_input, pas_input);
			break;
		}
		helper = cust_login(c, us_input, pas_input);
		cout << "\nEnter ur user name Again : ";
		cin >> us_input;
		cout << "\nEnter ur password : ";
		cin >> pas_input;
	}
	return helper;

}

int admin_login( vector<admin> a, string user_input, string password_input)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (user_input == a[i].get_user()&&password_input==a[i].get_pass())
		{
			return -1;
		}
		
	}
	return 0;
}

int cust_login(vector<customer> c, string user_input, string password_input)
{
	for (int i = 1; i < c.size(); i++)
	{

		if (user_input == c[i].get_user() && password_input == c[i].get_pass())
		{
			return i;
			break;
		}

	}

	return 0;
}

void cust_menu(vector<car> crs , vector<customer> z , int indx)
{
	float new_cash = 0.0;
	cout << "1. for add some cash \n2.for borrow a car\n";
	int path;
	cin >> path;
	switch (path)
	{
	case  1 :
		cout << "Enter tha value u wanna add\n";
		
		cin >> new_cash;
		z[indx].set_rec_cash(new_cash);
		cout << "Done\n";
		break;
	default:
		float temp;
		int code = 0, days;
		int helper = 0;
		system("CLS");
		for (int i = 1; i < crs.size(); i++)
		{
			crs[i].print();
			cout << endl << "enter any number to see the next car \n";
			cin >> helper;
		}
		while (!code)
		{
			cout << "Enter car's code  u wanna \n ";
			cin >> code;
			cout << "enter how many days u wanna Borrow \n ";
			cin >> days;
			for (int i = 1; i < crs.size(); i++)
			{
				if (code == crs[i].get_code())
				{
					temp = crs[i].get_pay();
					break;
				}
			}

		}

		float cost = -temp * days;
		z[indx].set_rec_cash(cost);
		cout << "The cose will be " << cost << "$\n";
		cout << "The operatin done sucssfully \n" << "the cash remaning = " << z[indx].get_rec_cash() << endl;
		cout << "Ty come again ^^ \n";
		break;
	}
	
}

void adminmenu(vector<car> crs)
{
	cout << "Hello mr admin \n";
	cout << "1. add a car \n";
	cout << "2. delet a car \n";
	cout << "3. change somthing spesefic in a spesefic car  (not avilavble now ) \n";
	int num;
	cin >> num;
	switch (num)
	{
	case  1 :
		creating_car(crs);
		break;
	case 2 :
		deleting_car(crs);
		break;
	default:
		cout << "SHUT THE FUCK UP \n";
		break;
	}
}

void creating_car(vector<car> c)
{
	int model,code; float pay;
	string factory, color;
	cout << "Enter car's Factory \n";
	cin >> factory;
	cout << "\nenter car's color\n";
	cin >> color;
	cout << "\netner car's model\n";
	cin >> model;
	cout << "\nEnter pay rate for the car \n";
	cin >> pay;
	cout << "\nEnter Car's Code\n";
	cin >> code;
	car cc(factory, color, model, pay, code);
	c.push_back(cc);
	cout << "Creation new car done \n ty\n";
	system("CLS");
	cc.print();
}

void deleting_car(vector<car> c)
{
	int cod , holder=0;
	cout << "Enter car's code \n";
	cin >> cod;
	for (int i = 1; i < c.size(); i++)
	{
		if (c[i].get_code() == cod)
		{
			holder = i;
			break;
		}
	}
	if (holder != 0)
	{
		c.erase(c.begin() + holder);
		cout << "Dleting car done  ty \n";
	}
}

/*


ÇáÇßæäÊÇÊ ãÔ ÈÊÊÖÇÝ åí æ ÇáÚÑÈíÇÊ Çæ ããßä ÈÊÖÇÝ ÈÓ ãÔ ÚÇÑÝ ÇæÕáåÇ Úä ØÑíÞ ÝäßÔä Çá .size


*/