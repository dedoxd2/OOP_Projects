#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class student
{
private :
	string f_name, l_name;
	int stu_num , english , arabic , math , phisics , sum ;
	double avr;
	bool eng_succ, arab_succ, math_succ, phisics_succ , big_succ;

public :
	
	student() :f_name("none"), l_name("none"), stu_num(0), english(0), arabic(0), math(0), phisics(0), avr(0.0), eng_succ(false),arab_succ(false),math_succ(false),phisics_succ(false),big_succ(false)  {};

	void set_fname(string f);
	string get_fname();
	void set_lname(string lname);
	string get_lname();
	void set_stu_num(int n);
	int get_stu_num();
	void set_engl(int s);
	int get_engl();
	void set_arabic(int a);
	int get_arabic();
	void set_math(int m);
	int get_math();
	void set_phisics(int ph);
	int get_phisics();
	
	void calc_math_succ();
	void calc_english_succ();
	void calc_arabic_succ();
	void calc_phisics_succ();

	bool get_math_succ();
	bool get_english_succ();
	bool get_arabic_succ();
	bool get_phisics_succ();
	void set_big_succ();
	bool get_big_succ();
	student(string fname, string lname, int code, int eng, int arab, int ma, int phis);
	void print();
};

