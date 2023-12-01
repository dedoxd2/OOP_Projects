#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class human
{
private:
	string user_name;
	string password;
public :

	virtual void print_human() = 0;

	human()
	{

	}

	human(string u, string pass):user_name(u), password(pass)
	{
	}
	void set_user(string u)
	{
		user_name = u;
	}
	void set_pass(string p)
	{
		password = p;
	}

	string get_user()
	{
		return user_name;
	}
	string get_pass()
	{
		return password;
	}
};

