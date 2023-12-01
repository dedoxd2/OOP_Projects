#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;
string set_user(string input_un, string input_pa , string u1_user,string u1_pass,string u2_user , string u2_pass);
struct user
{
	string user_name;
	string password;
	double recent_cash;


};

void show_menu();


int main()
{
	int option = 0;
	string hold_us , hold_pass;
	user u1;
	u1.user_name = "dedoxd2";
	u1.password = "dudxd123";
	u1.recent_cash = 1500;
	user u2;
	u2.user_name = "kholio";
	u2.password = "123";
	u2.recent_cash = 1700;
	
	do {
		cout << "Please enter ur user name : ";
		cin >> hold_us;
		cout << "\n Please enter ur password : ";
		cin >> hold_pass;

		while (set_user(hold_us, hold_pass, u1.user_name, u1.password, u2.user_name, u2.password) == "wrong")
		{
			cout << "Ur user name and password dosent match enter ur user name and password again \n";
			cout << " user name : "; cin >> hold_us;
			cout << "\n enter ur password : "; cin >> hold_pass;
		}

		if (set_user(hold_us, hold_pass, u1.user_name, u1.password, u2.user_name, u2.password) == "user1")
		{



			int dep_amount = 0;
			double balance = 500.5;
			double with_draw = 0;
			do
			{

				show_menu();
				cout << "\t\t\t\t\t\t Option : ";
				cin >> option;
				system("cls");
				cout << "\n";

				switch (option)
				{
				case 1:
					cout << "\t\t\t\t\t\t the balance is " << u1.recent_cash << '$' << endl;
					break;
				case 2: cout << "\t\t\t\t\t\t Please enter deposite amount \n";
					cout << "\t\t\t\t\t\t";
					cin >> dep_amount;
					u1.recent_cash += dep_amount;
					cout << "\t\t\t\t\t\t Your Balance became = " << u1.recent_cash << "\n";
					break;
				case 3:
					cout << "\t\t\t\t\t\t Please enter Withdraw amount \n";
					cout << "\t\t\t\t\t\t";
					cin >> with_draw;
					if (with_draw <= u1.recent_cash)
					{
						u1.recent_cash -= with_draw;
						cout << "\t\t\t\t\t\t The operation have been done sucssefully \n";
						cout << "\t\t\t\t\t\t And ur balance is = " << u1.recent_cash << "\n";
					}
					else
					{
						cout << "\t\t\t\t\t\t u dont have this amount of money\n";
					}
					break;

				case 4:
					cout << "\t\t\t\t\t\t Enter the amount of money u wanna tarnsfare \n\t\t\t\t\t\t";
					cin >> with_draw;
					if (with_draw <= u1.recent_cash)
					{
						u1.recent_cash -= with_draw;
						u2.recent_cash += with_draw;
						cout << "\t\t\t\t\t\t The operation have been done sucssefully \n";
						cout << "\t\t\t\t\t\t And ur balance is = " << u1.recent_cash << "\n";
						cout << "\t\t\t\t\t\t And ur friend's balance is = " << u2.recent_cash << "\n";
					}
					else
					{
						cout << "\t\t\t\t\t\t u dont have this amount of money\n";
					}
					break;

				}





			} while (option != 5 && option != 6);

		}
		else
		{

			int option;
			int dep_amount = 0;
			double balance = 500.5;
			double with_draw = 0;
			do
			{

				show_menu();
				cout << "\t\t\t\t\t\t Option : ";
				cin >> option;
				system("cls");
				cout << "\n";

				switch (option)
				{
				case 1:
					cout << "\t\t\t\t\t\t the balance is " << u2.recent_cash << '$' << endl;
					break;
				case 2: cout << "\t\t\t\t\t\t Please enter deposite amount \n";
					cout << "\t\t\t\t\t\t";
					cin >> dep_amount;
					u2.recent_cash += dep_amount;
					cout << "\t\t\t\t\t\t Your Balance became = " << u2.recent_cash << "\n";
					break;
				case 3:
					cout << "\t\t\t\t\t\t Please enter Withdraw amount \n";
					cout << "\t\t\t\t\t\t";
					cin >> with_draw;
					if (with_draw <= u2.recent_cash)
					{
						u2.recent_cash -= with_draw;
						cout << "\t\t\t\t\t\t The operation have been done sucssefully \n";
						cout << "\t\t\t\t\t\t And ur balance is = " << u2.recent_cash << "\n";
					}
					else
					{
						cout << "\t\t\t\t\t\t u dont have this amount of money\n";
					}
					break;

				case 4:
					cout << "\t\t\t\t\t\t Enter the amount of money u wanna tarnsfare \n\t\t\t\t\t\t";
					cin >> with_draw;
					if (with_draw <= u2.recent_cash)
					{
						u2.recent_cash -= with_draw;
						u1.recent_cash += with_draw;
						cout << "\t\t\t\t\t\t The operation have been done sucssefully \n";
						cout << "\t\t\t\t\t\t And ur balance is = " << u1.recent_cash << "\n";
						cout << "\t\t\t\t\t\t And ur friend's balance is = " << u2.recent_cash << "\n";
					}
					else
					{
						cout << "\t\t\t\t\t\t u dont have this amount of money\n";
					}
					break;
				}




			} while (option != 5 && option != 6);

		}


	}while (option != 6);



	system("pause>0");
}


string set_user(string input_un, string input_pa, string u1_user, string u1_pass, string u2_user, string u2_pass)
{
	if (input_un == u1_user && input_pa == u1_pass)
	{
	//	cout << "Welcome " << u1_user << endl;
		return "user1";
	}
	else if (input_un == u2_user && input_pa == u2_pass)
	{
	//	cout << "Welcome " << u2_user << endl;
		return "user2";
	}
	else
	{
		return "wrong";
	}


}



void show_menu()
{
	cout << "\t\t\t\t\t\t*********MENU*********\n";
	cout << "\t\t\t\t\t\t1. Check balance\n"; 
	cout << "\t\t\t\t\t\t2. Deposit\n";
	cout << "\t\t\t\t\t\t3. Withdraw \n";
	cout << "\t\t\t\t\t\t4. For transefare money \n";
	cout << "\t\t\t\t\t\t5. if u wanna log out \n";
	cout << "\t\t\t\t\t\t6. For Close The program\n";
	//cout << "\t\t\t\t\t\t5. For Close The program\n";
	cout << "\t\t\t\t\t\t**********************\n";
}
