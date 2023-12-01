#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>
#include<vector>
//#include <bits/stdc++.h>
using namespace std;
#include "book.h"
struct book_holder
{
	int copy_no;
	float price;
	int code;

};
void main_menu();
book add(vector<book> arr);
void book_print(book b1);
book_holder searching(vector<book> arr);
bool check_avilabilty(book_holder b1 , int no_copy);
float calc_cost(book_holder b1, int cop);
int print_ticket(float total);
void do_selling(int num, int code, int copies,vector<book> arr);
int changing_menu();
void big_path(book b1, int lil_path);

int main()
{
	int helper = 0 , holder=0;
	vector <book> arr;
	book b1("phisics1", "stanley", 10, 10.5, 1), b2("phisics2", "stanley", 15, 10.5, 2), b3("phisics3", "stanley", 20, 50, 3);
	arr.push_back(b1);
	arr.push_back(b2);
	arr.push_back(b3);
	book b11;
	book_holder temp; temp.code = 0; temp.copy_no = 0; temp.price = 0;
	while (helper != 5)
	{
		
		main_menu();
		cin >> helper;
		switch (helper)
		{
		case 1:
			 b11 = add(arr);
			book_print(b11);
			break;
		case 2:
			while (!temp.code)
			{
				temp = searching(arr);
			}
			cout << "\t\t\t\t\t\t Enter how many copies u want  : "; cin >> holder;
			if (check_avilabilty(temp, holder))
			{
				calc_cost(temp, holder);cout << endl;
				int yamete_kodasai = print_ticket(calc_cost(temp, holder));
				do_selling(yamete_kodasai, temp.code, holder, arr);
			}
			else {
				cout << "\t\t\t\t\t\t We dont have this amount of copies\n";
			}
			temp.code = 0;
			break;
		case 3:
			temp = searching(arr);
			if (temp.code)
			{
				for (int i = 0; i < arr.size(); i++)
				{
					if (arr[i].get_code() == temp.code)
					{
						book_print(arr[i]);
						break;
					}
				}
			}
			else {
				cout << "\t\t\t\t\t\t we didnt found this book\n";
			}
			break;
		case 4 :
			temp = searching(arr);
			if (temp.code)
			{
				for (int i = 0; i < arr.size(); i++)
				{
					if (arr[i].get_code() == temp.code)
					{
						big_path(arr[i], changing_menu());
						break;
					}
				}
			}
			else
			{
				cout << "\t\t\t\t\t\t Invalid input\n";
			}
			break;
		
		case 5: 
			return 0;
		default :
			cout << "\t\t\t\t\t\t Envalid input try again \n";
			break;
		}
		
	}
	return 0;
}
void main_menu()
{
	cout << "\t\t\t\t\t\t\t Main Menu\n";
	cout << "\t\t\t\t\t\t1. For Entry of New Book\n";
	cout << "\t\t\t\t\t\t2. Buy Book\n"; // enter title and author func / calc avilabillty / calc cost
	cout << "\t\t\t\t\t\t3. Search For a Book\n";
	cout << "\t\t\t\t\t\t4. Edit details of Book \n";
	cout << "\t\t\t\t\t\t5. Exit\n";
}

book add(vector<book> arr)
{
	string title, author;
	int copies , code;
	float cost;
	cout << "\t\t\t\t\t\tEnter book's Title : "; cin >> title; cout << endl;
	cout << "\t\t\t\t\t\tEnter book's Author : "; cin >> author; cout << endl;
	cout << "\t\t\t\t\t\tEnter book's Amount : "; cin >> copies; cout << endl;
	cout << "\t\t\t\t\t\tEnter book's Cost per one copy : "; cin >> cost; cout << endl;
	cout << "\t\t\t\t\t\tEnter Nook's Code : "; cin >> code; cout << endl;
	book b1(title, author, copies, cost , code);
	arr.push_back(b1);
	return b1;
}

void book_print(book b1)
{
	cout << "\t\t\t\t\t\t Just Cheking This is the data u entered , Right ? \n";
	cout << "\t\t\t\t\t\t Title : " << b1.get_title() << endl;
	cout << "\t\t\t\t\t\t Author : " << b1.get_author() << endl;
	cout << "\t\t\t\t\t\t Avalible Copies : " << b1.get_copies() << endl;
	cout << "\t\t\t\t\t\t Cost per 1 Copy : " << b1.get_cost() << endl;
}

book_holder searching (vector<book> arr)
{
	book_holder temp;
	string author, title;
	cout << "\t\t\t\t\t\tEnter Author's Name : "; cin >> author; cout << endl;
	cout << "\t\t\t\t\t\tEnter Book's Tilte : "; cin >> title; cout << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].get_author() == author && arr[i].get_title() == title)
		{
			temp.copy_no = arr[i].get_copies();
			temp.price = arr[i].get_cost();
			temp.code = arr[i].get_code();
			return temp;
			break;
		}
	}
	temp.copy_no = 0;
	temp.price = 1;
	temp.code = 0;
	return temp;
}

bool check_avilabilty(book_holder b1 , int no_copy)
{
	if (b1.copy_no > no_copy)
	{
		return true;
	}
	else
	{
		return false;
	}
	
	
}

float calc_cost(book_holder b1, int cop)
{
	
	return cop * b1.price;
	

}

int print_ticket(float total)
{
	int num;
	cout << "\t\t\t\t\t\t The Cost will = " << total << endl;
	cout << "\t\t\t\t\t\t Enter 1 for accept 2 for cancel \n"; cin >> num;
	return num;
}

void do_selling(int num, int code, int copies, vector<book> arr)
{
	if (num == 2)
	{
		cout << "\t\t\t\t\t\tBuying  Canceled \n";
	}
	else
	{
		cout << "\t\t\t\t\t\t  Done \n";
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].get_code() == code)
			{
				int helper = arr[i].get_copies()-copies;
				arr[i].set_copies(helper);

				break;
			}
		}

	}
}

int changing_menu()
{
	int num;
	cout << "\t\t\t\t\t\t1. Change Author \n";
	cout << "\t\t\t\t\t\t2. Change Title \n";
	cout << "\t\t\t\t\t\t3. Change copies \n";
	cout << "\t\t\t\t\t\t4. Change Price \n";
	cin >> num;
	return num;
}

void big_path(book b1, int lil_path)
{
	string author, title;
	int copies, code;
	float cost;
	switch (lil_path)
	{

	case 1 :
		cout << "\t\t\t\t\t\t Enter the new Author : "; cin >> author;
		b1.set_author(author);
		cout << "\t\t\t\t\t\t Done \n";
		book_print(b1);
		break;
	case 2:
		cout << "\t\t\t\t\t\t Enter the new Title : "; cin >> title; cout << endl;
		b1.set_title(title);
		cout << "\t\t\t\t\t\t Done \n";
		book_print(b1);
		break;
	case 3:
		cout << "\t\t\t\t\t\t Enter the new Number of copies : "; cin >> copies; cout << endl;
		b1.set_copies(copies);
		cout << "\t\t\t\t\t\t Done \n";
		book_print(b1);
		break;
	case 4 :
		cout << "\t\t\t\t\t\t Enter the new price : "; cin >> cost; cout << endl;
		b1.set_cost(cost);
		cout << "\t\t\t\t\t\t Done \n";
		book_print(b1);
		break;
	default :
		cout << "\t\t\t\t\t\t Invalid input \n";
		break;

}
}
