#include "VIP.h"
#include <iostream>
#include <string>

VIP::VIP() : VIP_type("none"), referals(0) {}

VIP::VIP(int bank_num, int spent, int C_ID, string BANK, string pur_his, string new_note,
int age, int phone, string name, string address, string VIP_type, int referals)
: Customer(bank_num, spent, C_ID, BANK, pur_his, new_note, age, phone, name, address),
  VIP_type(VIP_type), referals(referals) {}

string VIP::get_VIP_type(){return VIP_type;}
void VIP::set_VIP_type(string VIP_type){this->VIP_type = VIP_type;}

int VIP::get_referrals(){return referals;}
void VIP::set_referrals(int referals){this->referals = referals;}

// Define a data structure to store the available prizes
map<string, int> availablePrizes = {
    {"Model", 5}, // Prize name and its referral cost
    {"Towel", 10},
    {"Car", 15}
};

void VIP::displayPrizes() {
    cout << "Available Prizes:" << endl;
    for (const auto &prize : availablePrizes) {
        cout << prize.first << " - " << prize.second << " referrals" << endl;
    }
}

bool VIP::buy_prize(string prizeName) {
    auto it = availablePrizes.find(prizeName);
    if (availablePrizes.find(prizeName) == availablePrizes.end()) {
        cout << "Invalid prize name!" << endl;
        return false;
    }

    int prizeCost = availablePrizes[prizeName];
    if (referals < prizeCost) {
        cout << "Insufficient referrals to buy the prize!" << endl;
        return false;
    }

    referals -= prizeCost;
    cout << "Congratulations! You have successfully bought " << prizeName << "!" << endl;
    return true;
}
