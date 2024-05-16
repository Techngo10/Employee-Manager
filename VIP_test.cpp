#include <iostream>
#include "VIP.h"

int main() {
    // Creating a VIP member
    VIP vipMember(123456, 100, 789, "Bank", "History", "Note", 30, 1234567890, "John Doe", "123 Main St", "Gold", 50);

    // Display available prizes
    vipMember.displayPrizes();

    // Attempt to buy a prize
    std::cout << "\nBuying a prize...\n";
    vipMember.buy_prize("Model");

    // Display updated referrals
    std::cout << "\nRemaining referrals: " << vipMember.get_referrals() << std::endl;

    // Attempt to buy another prize
    std::cout << "\nBuying another prize...\n";
    vipMember.buy_prize("Towel");

    // Display updated referrals
    std::cout << "\nRemaining referrals: " << vipMember.get_referrals() << std::endl;

    return 0;
}
