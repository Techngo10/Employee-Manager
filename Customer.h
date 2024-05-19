#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include <iostream>
#include <string.h>

using namespace std;

class Customer : public Person {
    private:
        int bank_number;
        int spendings;
        int clientId;
        string bank;
        string purchase_history;
        string notes;

    public:
        Customer();
        Customer(int bank_num, int spent, int C_ID, string BANK, string pur_his, string new_note, int age, int phone, string name, string address);
        //string Purchase(model, price);

        int get_bankAccount();
        void set_bankAccount(int bank_num);

        string get_bank();
        void set_bank(string BANK);

        string get_purchase_history();
        int get_spendings();
        int get_clientId();

        string get_notes();
        void set_notes(string new_note);

        virtual int get_referrals();
        virtual void set_referrals(int referrals);

        virtual void displayPrizes();
       // virtual bool buy_prize(string prizeName);
            
};

#endif //CUSTOMER_H