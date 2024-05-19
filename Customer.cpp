#include "Customer.h"
 
#include <iostream>
#include <string.h>
using namespace std;

Customer::Customer() : Person(), bank_number(0), spendings(0), clientId(0), bank("none"), purchase_history("none"), notes("none"){}

Customer::Customer(int bank_num, int spent, int C_ID, string BANK, string pur_his, string new_note, int age, int phone, string name, string address)
: Person(age, phone, name, address), bank_number(bank_num), spendings(spent), clientId(C_ID), bank(BANK), purchase_history(pur_his), notes(new_note) {}

//string Purchase(model, price);

int Customer::get_bankAccount(){return bank_number;};
void Customer::set_bankAccount(int bank_num){bank_number = bank_num;};

string Customer::get_bank(){return bank;};
void Customer::set_bank(string BANK){bank = BANK;};

string Customer::get_notes(){return notes;};
void Customer::set_notes(string new_note){notes = new_note;};

int Customer::get_spendings(){return spendings;};
int Customer::get_clientId(){return clientId;};
string Customer::get_purchase_history(){return purchase_history;};

//VIP
int Customer::get_referrals() {return 0;};                               // Victor: something wrong
void Customer::set_referrals(int referrals) {(void) referrals;};

void Customer:: displayPrizes() {};
//bool Customer::buy_prize(string prizeName) {(bool);};