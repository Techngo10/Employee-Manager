#ifndef VIP_H
#define VIP_H

#include "Customer.h"
#include <iostream>
#include <string>
#include <map> // Include the <map> header for the map data structure

using namespace std;

class VIP : public Customer {
private:
    string VIP_type;
    int referrals;

public:
    VIP();
    VIP(int bank_num, int spent, int C_ID, string BANK, string pur_his, string new_note,
        int age, int phone, string name, string address, string VIP_type, int referrals);

    string get_VIP_type();
    void set_VIP_type(string VIP_type);

    int get_referrals();
    void set_referrals(int referrals);

    void displayPrizes();
    bool buy_prize(string prizeName);

    // Declare the availablePrizes map directly in the class
    std::map<std::string, int> availablePrizes = {
        {"Model", 5}, // Prize name and its referral cost
        {"Towel", 10},
        {"Car", 15}
    };
};

#endif
