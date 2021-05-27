#ifndef ATM_H
#define ATM_H

#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>

using namespace std;


class account
{
	string username;
	string password;
	long int balance;
public:
	void create_account();
	void show_account();
	string get_username();
	void set_username(string username);
	string get_password();
	void set_password(string password);
	void set_balance(long int n);
	long int get_balance();
};

struct ATM{
    int price10k;
    int price20k;
    int price50k;
    int price100k;
    int price200k;
    int price500k;
    ATM(int _price10k, int _price20k, int _price50k, int _price100k, int _price200k, int _price500k){
        price10k = _price10k;
        price20k = _price20k;
        price50k = _price50k;
        price100k = _price100k;
        price200k = _price200k;
        price500k = _price500k;
    }
};

void menu(ATM &atm);
char *now();
void log_in(ATM &atm);
void sign_up();
void list_account();
account find_account(string username);
long int total_money_ATM (ATM atm);
void account_menu(account &acc, ATM &atm);
void windraw(account &acc, long int n, ATM &atm);
int price_min(ATM ATM);

void deposit(account &acc);
void rut_tien1(account &acc, ATM &amt);
void rut_tien2 (account &acc, ATM &atm, long int n );

void transfer_account(account &acc, account&acc2, long int n);
void history();
void transfer_to_ATM(ATM &atm);
void shown_ATM(ATM atm);

#endif // ATM_H
