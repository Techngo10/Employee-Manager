#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include <iostream>
#include <string.h>

class Customer : public Person {
    private:
        int bank_number;
        int spendings;
        int clientId;
        std::string bank;
        std::string purchase_history;
        std::string notes;

    public:
        //Initialisation
        Customer();
        Customer(int bank_num, int spent, int C_ID, std::string BANK, std::string pur_his, std::string new_note, int age, int phone, std::string name, std::string address);

        //Getters
        int get_bankAccount();
        std::string get_bank();
        std::string get_purchase_history();
        int get_spendings();
        int get_clientId();
        std::string get_notes();

        //Setters
        void set_bankAccount(int bank_num);
        void set_bank(std::string BANK);
        void set_purchase_history(std::string history);
        void set_spendings(int spendings);
        void set_notes(std::string new_note);
        void set_clientId(int clientId);

};

#endif //CUSTOMER_H