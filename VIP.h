#ifndef VIP_H
#define VIP_H

#include "Customer.h"
#include <map> // Include the <map> header for the map data structure

class VIP : public Customer {
    private:
        //std::string VIP_type;
        int referrals;
 
    public:
        //Initialisation
        VIP();
        VIP(int bank_number, int spent, int Client_ID, std::string BANK, std::string purchase_history, std::string new_note,
            int age, int phone, std::string name, std::string address, int referrals);
            
        //Getter
        int get_referrals() override;

        //Setter
        void set_referrals(int referrals) override;

        void displayPrizes() override;
 
        // Declare the availablePrizes map directly in the class
        std::map<std::string, int> availablePrizes = {
            {"Model", 5}, // Prize name and its referral cost
            {"Towel", 10},
            {"Car", 15}
        };
};

#endif //VIP_H
