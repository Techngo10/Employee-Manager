#include "VIP.h"
#include "Customer.h"
#include <iostream>
#include <string>

VIP::VIP() : Customer(), referrals(0) {}

VIP::VIP(int bank_num, int spent, int C_ID, string BANK, string pur_his, string new_note,
int age, int phone, string name, string address, int referrals)
: Customer(bank_num, spent, C_ID, BANK, pur_his, new_note, age, phone, name, address),
 referrals(referrals) {}

int VIP::get_referrals(){return referrals;}
void VIP::set_referrals(int referrals){this->referrals = referrals;}

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

// bool VIP::buy_prize(string prizeName) {
//     //auto it = availablePrizes.find(prizeName); - Kurt: not sure why this is needed as when its removed it solves a pink error

//     int prizeCost = availablePrizes[prizeName];
//     if (referrals < prizeCost) {
//         cout << "Insufficient referrals to buy the prize!" << endl;
//         return false;
//     }

//     referrals -= prizeCost;
//     cout << "Congratulations! You have successfully bought " << prizeName << "!" << endl;
//     return true;
// }
