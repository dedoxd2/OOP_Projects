#pragma once
#include <String>
#include <iostream>
#include<cmath>
using namespace std;

class book
{
private :
	string title;
	string author;
	int copies;
	float cost; // the cose per 1 copy
	int code;
public :
	void set_title(string t);
	string get_title();
	string get_author();
	void set_author(string a);
	void set_copies(int c);
	int get_copies();
	void set_cost(float s);
	float get_cost();
	void set_code(int c);
	int get_code();
	book(string tit, string auth, int cop, float cos, int co);
	book();
	void print();
};

