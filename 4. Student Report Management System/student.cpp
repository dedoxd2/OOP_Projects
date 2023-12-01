#include "student.h"

void student::set_fname(string f)
{
	f_name = f;
}

string student::get_fname()
{
	return f_name;
}

void student::set_lname(string lname)
{
	l_name = lname;
}

string student::get_lname()
{
	return l_name;
}

void student::set_stu_num(int n)
{
	stu_num = n;
}

int student::get_stu_num()
{
	return stu_num;
}

void student::set_engl(int s)
{
	english = s;
}

int student::get_engl()
{
	return english;
}

void student::set_arabic(int a)
{
	arabic = a;
}

int student::get_arabic()
{
	return arabic;
}

void student::set_math(int m)
{
	math = m;
}

int student::get_math()
{
	return math;
}

void student::set_phisics(int ph)
{
	phisics = ph;
}

int student::get_phisics()
{
	return phisics;
}

void student::calc_math_succ()
{
	if (((float)math / 100 )> 0.5)
	{
		math_succ = true;

	}
	else
	{
		math_succ = false;
	}
}

void student::calc_english_succ()
{
	if (((float)english / 100) > 0.5)
	{
		eng_succ = true;

	}
	else
	{
		eng_succ = false;
	}

}

void student::calc_arabic_succ()
{
	if (((float)math / 100) > 0.5)
	{
		arab_succ = true;

	}
	else
	{
		arab_succ = false;
	}
}

void student::calc_phisics_succ()
{
	if (((float)math / 100) > 0.5)
	{
		phisics_succ = true;

	}
	else
	{
		phisics_succ = false;
	}
}

bool student::get_math_succ()
{
	return math_succ;
}

bool student::get_english_succ()
{
	return eng_succ;
}

bool student::get_arabic_succ()
{
	return arab_succ;
}

bool student::get_phisics_succ()
{
	return phisics_succ;
}

void student::set_big_succ()
{
	if (eng_succ && math_succ && arab_succ && phisics_succ)
	{
		big_succ = true;
	}
	else
	{
		big_succ = false;
	}
}

bool student::get_big_succ()
{
	return big_succ;
}

student::student(string fname, string lname, int code, int eng, int arab, int ma, int phis):f_name(fname),l_name(lname),stu_num(code),english(eng),arabic(arab),math(ma),phisics(phis)
{
	calc_arabic_succ(); calc_math_succ(); calc_english_succ(); calc_phisics_succ();
	set_big_succ();


}

void student::print()
{
	cout << "\t\t\t\t\t\tFrist Name : " << get_fname() << endl;
	cout << "\t\t\t\t\t\tLast Name : " << get_lname() << endl;
	cout << "\t\t\t\t\t\tStudent Code : " << get_stu_num() << endl;
	cout << "\t\t\t\t\t\tMath : " << get_math() << endl;
	cout << "\t\t\t\t\t\tArabic : " << get_arabic() << endl;
	cout << "\t\t\t\t\t\tEnglish : " << get_engl() << endl;
	cout << "\t\t\t\t\t\tPhisics : " << get_phisics() << endl;
}
