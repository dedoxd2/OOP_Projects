#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>
#include<vector>
//#include <bits/stdc++.h>/* «· €Ì—«  «·Ì ÃÊ« «·›«‰ﬂ‘‰“ ›Ì «·›Ìﬂ Ê— „‘ » ”„⁄ ›Ì «·«’·  „‘ﬂ·Â ﬂ· „—Â 
using namespace std;
#include"student.h"
void main_menu();
student creating_stu();
int search(vector <student> arr, int code);
void search_menu();
void big_path(vector<student>arr , int no_path ,int indx);
void subjects_menu();
void check_succ(vector<student> arr, int num);
void change_degree(vector<student> arr, int indx, int subj_no);
int main()
{
	int code,search_num=0,holder;
	student s11;
	vector <student> arr;
	student s1("ahmed", "hamada", 1, 60, 70, 80, 90) , s2("duke","dud",2,70,58,95,57),s3("hamasa","hoda",3 , 77,88,99,66);
	arr.push_back(s1); arr.push_back(s2); arr.push_back(s3);
	int num = 1; 
	while (num)
	{
		main_menu();
		cin >> num;
		switch (num)
		{
		case 1 : 
		s11 = creating_stu();
			arr.push_back(s11);
			break;
		case 2 :
			cout << "\t\t\t\t\t\t enter sutudent's Code\n"; cin >> code;
			holder = search(arr, code);
			if (holder==-1)
			{
				cout << "\t\t\t\t\t\t there's no student with this code \n";
			}
			else
			{
				search_menu();
				cin >> search_num;
				big_path(arr, search_num, holder);
			}
			break;
		case 3 : 
			num = 0;
			break;
		default:
			cout << "\t\t\t\t\t\t Invalid input\n";
			break;
		}
	}
	return 0;
}

void main_menu()
{
	cout << "\t\t\t\t\t\t\tMain Menu\n";
	cout << "\t\t\t\t\t\t1.Creat New Student\n";
	cout << "\t\t\t\t\t\t2.Search for Student\n";
	cout << "\t\t\t\t\t\t3.Exit\n";
}

student creating_stu()
{
	int code, eng, arab, phic, math;
	string fname, lname;
	cout << "\t\t\t\t\t\t Enter student's Frist Name \n"; cin >> fname;
	cout << "\n\t\t\t\t\t\t Enter student's Last Name\n"; cin >> lname;
	cout << "\n\t\t\t\t\t\t Enter students's Code\n"; cin >> code;
	cout << "\n\t\t\t\t\t\t Enter student's degree in english\n"; cin >> eng;
	cout << "\n\t\t\t\t\t\t Enter student's degree in arabic \n"; cin >> arab;
	cout << "\n\t\t\t\t\t\t Enter student's degree in phisics\n"; cin >> phic;
	cout << "\n\t\t\t\t\t\tEnter student's degree in math\n"; cin >> math;
	cout << "\n\t\t\t\t\t\t Done ^^\n";
	student s1(fname, lname, code, eng, arab, math, phic);
	return s1;
}

int  search(vector<student> arr, int code)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].get_stu_num() == code)
		{
			return i;
			break;
		}
	}
	
	return -1;
	
}

void search_menu()
{
	cout << "\t\t\t\t\t\t1.Check if this student sucsseded or not \n";
	cout << "\t\t\t\t\t\t2. Change  degree in specific subject  \n";
	cout << "\t\t\t\t\t\t3.Delet this student \n";
	cout << "\t\t\t\t\t\t4.Print Student's Data\n";
}

void big_path(vector<student> arr, int no_path, int indx)
{
	int num;
	switch (no_path )
	{
	case 1 : 
		check_succ(arr, indx);
		break;
	case 2: 
		subjects_menu();
		cin >> num;
		change_degree(arr, indx, num);
		break;
	case 3 :
		
		arr.erase(arr.begin() + indx);
		cout << "\t\t\t\t\t\t Done \n";
		break;
	case 4 :
		arr[indx].print();
		break;
	default:
		cout << "\t\t\t\t\t\t Invalid input\n";
		break;
	}
}

void subjects_menu()
{
	cout << "\t\t\t\t\t\t1.English\n";
	cout << "\t\t\t\t\t\t2.Math\n";
	cout << "\t\t\t\t\t\t3.Phisics\n";
	cout << "\t\t\t\t\t\t4.Arabic";
	cout << "\t\t\t\t\t\t5.Exit\n";
}

void check_succ(vector<student> arr, int num)
{
	if(arr[num].get_big_succ())
	{
		cout << "\t\t\t\t\t\tU did it , Good job son \n\t\t\t\t\t\tUp to the next lvl\n";
	}
	else {
		cout << "\t\t\t\t\t\ u didnt make it  lmaaaaao go kill ur self \n";
	}
}

void change_degree(vector<student> arr, int indx, int subj_no)
{
	int helper = 0;
	switch (subj_no)
	{case 1 ://  1 eng 2 math 3 phis 4 arab
		cout << "\t\t\t\t\t\tEnter The new degeree in english \n";
		cin >> helper;
		arr[indx].set_engl(helper);
		cout << "\t\t\t\t\t\tDone\n";
		break;
	case 2 : 
		cout << "\t\t\t\t\t\tEnter The new degeree in Math \n";
		cin >> helper;
		arr[indx].set_math(helper);
		cout << "\t\t\t\t\t\tDone\n";
		break;
	case 3 : 
		cout << "\t\t\t\t\t\tEnter The new degeree in Phisics \n";
		cin >> helper;
		arr[indx].set_phisics(helper);
		cout << "\t\t\t\t\t\tDone\n";
		break;
	case 4 :
		cout << "\t\t\t\t\t\tEnter The new degeree in Arabic\n";
		cin >> helper;
		arr[indx].set_arabic(helper);
		cout << "\t\t\t\t\t\tDone\n";
		break;
	case 5 :
		break;
	default:
		cout << "\t\t\t\t\t\t Invalid input\n";
		break;
	}


}
