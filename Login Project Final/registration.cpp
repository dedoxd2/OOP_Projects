#include "registration.h"

registration::registration(string n)
{
	
	cout << "Frome here after  every sucssefull step i'll say Done ! \n less gooo \n";
	
	set_f_name(n);
	
}

void registration::set_f_name(string fn)
{
	f_name = fn;
	cout << "Mr : " << fn << " Please enter ur last name \n";
	string ll;
	cin >> ll;
	set_l_name(ll);

}

string registration::get_f_name()
{
	return f_name;
}

void registration::set_l_name(string ln)
{
	l_name = ln;
	cout << "Done!\n lets go to next stip\n";
	cout << "Please enter ur Mobile number or ur email address \n";
	string s;
	cin >> s;
	set_mobile_emai(s);

}

string registration::get_l_name()
{
	return l_name;
}

void registration::set_mobile_emai(string m_e)
{
	mobile_email = m_e;
	cout << "Done ! ^^ lets got to the next step \n";
	cout << "Please enter ur password  \n";
	string s;
	cin >> s;
	registration::set_password(s);
	/*
	cout << "Done ! ^^ \n lets go to the next stip \nPlease enter ur date of birh \n";
	string helper;

	cin >> helper;*/



}

string registration::get_mobile_emai()
{
	return mobile_email;
}

void registration::set_password(string pw)
{
	password = pw;
	cout << "Please enter ur password again \n";
	string helper;
	cin >> helper;
	while (!registration::confirm_pass(helper))
	{
		cout << "Wrong Password \nenter ur password again please ... \n";
		cin >> helper;

	}

	cout << "Done ! ^^ lets go to next step\n";
	cout << "Enter ur date of birth this way ( no_day \ no_month\ no_year ) \n";
	string s;
	cin >> s;
	registration::set_bd(s);

}

string registration::get_password()
{
	return password;
}

void registration::set_gender(string g)
{
	gender = g;
	cout << "Creating ur account done \nhave a good day king \n";

}

string registration::get_gender()
{
	return gender;
}

void registration::set_bd(string s)
{
	date = s;
	cout << "Done ! ^^ one more step \n";
	cout << "Enter ur gender pls \n";
	string helper;
	cin >> helper;
	registration::set_gender(helper);
}

string registration::get_bd()
{
	return date;
}

bool registration::confirm_pass(string p_s)
{
	//cout << "Please enter ur password again \n";
	//string s;
	//cin >> s;
	if (p_s == password)
	{

		return true;
	}
	else
	{
		return false;
	}
}
