#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class car
{
private :
	string factor, color;
	int model;
	float pay_day;
	int code;
public :
	car();
	void set_factor(string f);
	string get_factor();
	void set_color(string c);
	string get_color();
	void set_model(int m);
	int get_model();
	void set_pay(float r);
	float get_pay();
	void print();
	void set_code(int c);
	int get_code();
	car(string f, string c, int mo, float pay, int cod);
	car(string f);
	car	operator = (int zero)
	{
		car temp;
		temp.code = 0;
		temp.color = "none";
		temp.factor = "none";
		return temp;
	}
	float calc_total(int days);
	friend class admin;
};

#pragma once
#include "human.h"
class admin : public human
{

public :
	void print_human()
	{
		cout << "User name : " <<get_user() << endl;
		cout << "Password = " << get_pass() << endl;
	}

	admin(string u, string pa)
	{
		human::set_pass(pa);
		human::set_user(u);

	}//creating new acc admin


};
