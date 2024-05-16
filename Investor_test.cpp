 #include "Investor.h"
#include <iostream>
#include <string.h>

int main(){
    Investor investor(21, 122333, "DAVID", "London", 9999.98);


    std::cout << "Initial investment amount: $" << investor.get_amount_of_investment() << std::endl;

 
    investor.set_amount_of_investment(15000.0);

 
    std::cout << "Updated investment amount: $" << investor.get_amount_of_investment() << std::endl;

    return 0;
}