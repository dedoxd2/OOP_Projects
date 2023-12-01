#include "book.h"

void book::set_title(string t)
{
	title = t;
}

string book::get_title()
{
	return title;
}

string book::get_author()
{
	return author;
}

void book::set_author(string a)
{
	author = a;
}

void book::set_copies(int c)
{
	copies = c;
}

int book::get_copies()
{
	return copies;
}

void book::set_cost(float s)
{
	cost = s;
}

float book::get_cost()
{
	return cost;
}

void book::set_code(int c)
{
	code = c;
}

int book::get_code()
{
	return code;
}

book::book(string tit, string auth, int cop, float cos , int co):title(tit),author(auth) , copies(cop),cost(cos), code(co)
{
}

book::book():title("none"),author("none"),copies(0),cost(0.0)
{
}

void book::print()
{
	cout << "\t\t\t\t\t Title : " << title << endl;
	cout << "\t\t\t\t\t Author : " << author << endl;
	cout << "\t\t\t\t\t Copies Avalable : " << copies << endl;
	cout << "\t\t\t\t\t Cost per 1 copy : " << cost << endl;

}
