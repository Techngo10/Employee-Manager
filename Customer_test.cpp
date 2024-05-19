#include "Person.h"
#include "Customer.h"

#include <iostream>
#include <string.h>
using namespace std;

int main() {
     Customer Customer1;
    //VIP vip1(100020333, 200000, 10001, "commonwealth", "Cybertruck, Model 3", "rich man", 99, 887766, "RICH", "India", 3);

    cout << "Name: " << Customer1.get_name() << endl;
    cout << "Age: " << Customer1.get_age() << endl;
    cout << "Phone Number: " << Customer1.get_phone() << endl;
    cout << "Address: " << Customer1.get_address() << endl;
    cout << "Bank number: " << Customer1.get_bankAccount() << endl;
    cout << "Spendings: " << Customer1.get_spendings() <<endl;
    cout << "Client ID: " << Customer1.get_clientId() <<endl;
    cout << "Bank: " << Customer1.get_bank() <<endl;
    cout << "Purchase History: " << Customer1.get_purchase_history() <<endl;
    cout << "Notes: " << Customer1.get_notes() <<endl;

    cout << "\n";

    Customer1.set_bank("Commonwealth Bank");
    Customer1.set_bankAccount(12345);
    cout << "New Bank: " << Customer1.get_bank() <<endl;
    cout << "New Bank number: " << Customer1.get_bankAccount() << endl;

    Customer1.set_referrals(50);
    std::cout << "\nRemaining referrals: " << Customer1.get_referrals() << std::endl;

    Customer1.displayPrizes();
    std::cout << "\nBuying another prize...\n";
    //Customer1.buy_prize("Towel");



    

    return 0;
}