#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class registration
{
protected: // i chosed protected not private so i can check in the drived class 
	string f_name;
	string	l_name;
	string mobile_email;
	string password;
	string gender;
	string date;
public:
	registration(string n);
	void set_f_name(string fn);
	string get_f_name();
	void set_l_name(string ln);
	string get_l_name();
	void set_mobile_emai(string m_e);
	string get_mobile_emai();
	void set_password(string pw);
	string get_password();
	void set_gender(string g);
	string get_gender();
	void set_bd(string s);
	string get_bd();
	bool confirm_pass(string p_s);
	void print()
	{
		cout << "\n frist name = " << f_name << endl;
		cout << "\n last name = " << l_name << endl;
		cout << "\n ur user name = " << mobile_email << endl;
		cout << "\n password = " << password << endl;
		cout << "\n ur gender = " << gender << endl;
		cout << "\n birt date = " << date << endl;



	}
	registration()
	{

	}
};

