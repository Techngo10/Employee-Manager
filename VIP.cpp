#include "VIP.h"

//Initialisation
VIP::VIP() : Customer(), referrals(0) {}
VIP::VIP(int bank_number, int spent, int Client_ID, std::string BANK, std::string purchase_history, std::string new_note,
            int age, int phone, std::string name, std::string address, int referrals)
: Customer(bank_number, spent, Client_ID, BANK, purchase_history, new_note, age, phone, name, address),
 referrals(referrals) {}
//Getter
int VIP::get_referrals(){return referrals;}

//Setter
void VIP::set_referrals(int referrals){this->referrals = referrals;}

// Define a data structure to store the available prizes
std::map<std::string, int> availablePrizes = {
    {"Model", 5}, // Prize name and its referral cost
    {"Towel", 10},
    {"Car", 15}
};

void VIP::displayPrizes() {
    std::cout << "Available Prizes:" << std::endl;
    for (const auto &prize : availablePrizes) {
        std::cout << prize.first << " - " << prize.second << " referrals" << std::endl;
    }
}

