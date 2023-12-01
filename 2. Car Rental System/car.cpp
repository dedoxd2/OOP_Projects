#include "car.h"



	

car::car():factor("def"),color("nani"),model(0),pay_day(0.0),code(0)
{
}

void car::set_factor(string f)
{
	factor = f;
}

string car::get_factor()
{
	return factor;
}

void car::set_color(string c)
{
	color = c;
	cout << "Enter Car's Model \n";
	int mo;
	cin >> mo;
	set_model(mo);
}

string car::get_color()
{
	return color;
}

void car::set_model(int m)
{
	model = m;
	cout << "Enter Car pay by day \n";
	float p;
	cin >> p;
	set_pay(p);
}

int car::get_model()
{
	return model;
}

void car::set_pay(float r)
{
	pay_day = r;
	cout << "Enter car's code \n";
	int h;
	cin >> h;
	cout << endl;
	set_code(h);
}

float car::get_pay()
{
	return pay_day;
}

void car::print()
{
	cout << "Factor = " << get_factor() << endl;
	cout << "Model = " << get_model() << endl;
	cout << "pay per day = " << get_pay() << endl;
	cout << "Car's Code = " << get_code() << endl;

}

void car::set_code(int c)
{
	code = c;
	cout << "Creating a new car has done \n";
	cout << "if u wanna print tha data to make sure enter 1 if u wanna exit enter 0 \n";
	int helper;
	cin >> helper;
	if (helper)
	{
		print();
	}
	
}

int car::get_code()
{
	return code;
}

car::car(string f, string c, int mo, float pay, int cod):factor(f),color(c),model(mo),pay_day(pay),code(cod)
{
}

car::car(string f)
{
	set_factor(f);
	cout << "Enter Car Color \n";
	string c;
	cin >> c;
	set_color(c);

}

float car::calc_total(int days)
{
	return pay_day*days;
}
