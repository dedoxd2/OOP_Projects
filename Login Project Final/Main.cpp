#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
#include "registration.h"
bool set_path(int path);

/*          Open facebook registration to transfar from function to another but start from the constructor
* ex : go to the constructor then go to function set last name 
*		then go to set_emai
*													ﬁ’œÌ «‰ «· — Ì» «‰« Ã«Ì»Â „‰ «·›Ì”»Êﬂ  ﬂ√‰ﬂ » ⁄„· «ﬂÊ‰  ⁄·Ì ›Ì”»Êﬂ Ì⁄‰Ì 
* 
*/

using namespace std;
int main()
{
	string user_name = "this value should be in the data base i think", password = "same here";
	int path = 0 , flag=0;
	cout << "Hello ! Mr : ? ... Pleas enter ur name ^^\n";
	string name;
	cin >> name;
	cout << "Hello Mr : " << name << " if u already have account enter 2 if u wanna regist enter 1 \n";
	cin >> path;
	while (path != 1 && path != 2)
	{
		cout << "invalid input pls enter 1 or 2 \n";
		cout << "Hello Mr : " << name << " if u already have account enter 2 if u wanna regist enter 1 \n";

		cin >> path;
	}

	registration acc1;
	if (set_path(path))
	{
		registration acc2(name);
		
		acc1 = acc2;
		cout<<"here acc2 will show his name  " << acc2.get_f_name() << "\n";
	}
	else
	{
		string holder_user, holder_pas;
		cout << "Enter ur user name pls \n";

		getline(cin, holder_user);

		while (holder_user!=user_name)
		{
			cout << "Wrong pls enter ur user name again \n";
			getline(cin, holder_user);
		}
		cout << "Good \n now enter ur password \n";

		getline (cin, holder_pas);
		while (holder_pas != password)
		{
			cout << "Wrong pls enter ur password again \n";
			getline(cin, holder_pas);
		}

		cout << "U loged in \n  \t have a nice day ^^\n ";
		return 0;
	}
	cout << "If u wanna long in enter 1 if u wanna exist the program enter 0\n";
	cin >> flag;
	if (flag)
	{
		cout << "Enter ur user name Please \n";
		string s;
		cin >> s;
		while (s != acc1.get_mobile_emai())
		{
			cout << "Invalid input pls inter ur user name again \n";
			cin >> s;
		}
		
		cout << "Enter ur password \n";
		string p;
		cin >> p;
		while (p != acc1.get_password())
		{
			cout << "Invalid input pls inter ur password again \n";
			cin >> p;
		}
		
		
		cout << "U have loged in \n \t \t Have a Good Day Mr : " << name << "\n";

	}

	return 0 ;	
}

bool set_path(int path)//true for regist false for login
{
	if (path == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}