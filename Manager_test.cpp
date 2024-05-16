#include "Manager.h"
#include <iostream>

int main() {
    // Create a Manager object
    Manager manager(50.0, 40.0, "2024-05-16", 35, 1234567890, "Alice Smith", "123 Main St", "password123", "Manager");

    // Test getters and setters
    std::cout << "Name: " << manager.get_name() << std::endl;
    std::cout << "Salary: " << manager.get_salary_hourly() << std::endl;
    std::cout << "Position: " << manager.get_position() << std::endl;

    // Add function to ask user if they want to change password

    // Test setting password
    string entered_old_pass;
    std::cout << "Enter old Password: " << endl;
    std :: cin >> entered_old_pass;
    while (entered_old_pass != manager.get_password()){
        std::cout << "It is wrong. Enter old Password again: " << endl;
        std :: cin >> entered_old_pass;
        if(entered_old_pass == manager.get_password()) {
            break;
        }
    }
    
    string new_pass;
    std::cout << "Enter new Password: " << endl;
    std :: cin >> new_pass; 

    manager.set_password(new_pass);
    std::cout << "New Password: " << manager.get_password() << std::endl;

    // Test setting position
    manager.set_position("Senior Manager");
    std::cout << "New Position: " << manager.get_position() << std::endl;

    return 0;
}
