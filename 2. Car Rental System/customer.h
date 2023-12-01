#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#include "human.h"
class customer :
    public human
{
private :
    string email; 
    float rec_cash = 0;
public :
    void set_email(string e)
    {
        email = e;
    }
    string get_email()
    {
        return email;
    }
    void set_rec_cash(float add)
    {
        rec_cash += add;
    }
    float get_rec_cash()
    {
        return rec_cash;
    }
    customer(string us, string pass, string ema, float rec_ca)
    {
        human::set_user(us);
        human::set_pass(pass);
        email = ema;
        rec_cash = rec_ca;
    }
    void print_human()
    {
        cout << "User Name : " << human::get_user() << endl;
        cout << "Password : " << human::get_pass() << endl;
        cout << "Email : " << email << endl;
        cout << "Recent Cash = " << rec_cash << endl;
    }
};

