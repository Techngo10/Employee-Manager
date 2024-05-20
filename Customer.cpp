#include "Customer.h"
#include <iostream>
#include <string.h>

//Initialisation
Customer::Customer() : Person(), bank_number(0), spendings(0), clientId(0), bank("none"), purchase_history("none"), notes("none"){}
Customer::Customer(int bank_num, int spent, int C_ID, std::string BANK, std::string pur_his, std::string new_note, int age, int phone, std::string name, std::string address)
: Person(age, phone, name, address), bank_number(bank_num), spendings(spent), clientId(C_ID), bank(BANK), purchase_history(pur_his), notes(new_note) {}

//Getters
int Customer::get_bankAccount(){return bank_number;};
std::string Customer::get_bank(){return bank;};
std::string Customer::get_notes(){return notes;};
int Customer::get_spendings(){return spendings;};
int Customer::get_clientId(){return clientId;};
std::string Customer::get_purchase_history(){return purchase_history;};

//Setters
void Customer::set_bankAccount(int bank_num){bank_number = bank_num;};
void Customer::set_bank(std::string BANK){bank = BANK;};
void Customer::set_notes(std::string new_note){notes = new_note;};
void Customer::set_spendings(int spendings){this->spendings = spendings;};
void Customer::set_purchase_history(std::string history){purchase_history = history;};
