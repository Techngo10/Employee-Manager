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
        Customer(int bank_num, int spent, int C_ID, string BANK, string pur_his, string new_note);
        //string Purchase(model, price);

        int get_bankAccount();
        int get_spendings();
        int get_clientId();
        string get_bank();
        string get_purchase_history();
        string get_notes();
        
        void set_bank(string BANK);
        void set_bankAccount(int bank_num);
        void set_notes(string new_note);

};

#endif //CUSTOMER_H