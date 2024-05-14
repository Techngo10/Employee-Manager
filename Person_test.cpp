#include "Person.h"
#include <iostream>
#include <string>

int main(){

    Person Person1;
    std::cout << "Name: " << Person1.get_name() << std::endl;
    std::cout << "Age: " << Person1.get_age() << std::endl;
    std::cout << "Phone Number: " << Person1.get_phone() << std::endl;
    std::cout << "Address: " << Person1.get_address() << std::endl;

    Person Person2(30, 1234567890, "John", "I Live Here");
    std::cout << "Name: " << Person2.get_name() << std::endl;
    std::cout << "Age: " << Person2.get_age() << std::endl;
    std::cout << "Phone Number: " << Person2.get_phone() << std::endl;
    std::cout << "Address: " << Person2.get_address() << std::endl;

    return 0;
}