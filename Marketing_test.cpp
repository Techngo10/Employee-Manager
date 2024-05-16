#include <iostream>
#include "Marketing.h"

int main() {
    // Creating a Marketing object
    Marketing marketing(25.0, 40.0, "2024-05-16", 30, 1234567890, "Jane Doe", "456 Oak St", "Manager", 0.75);

    // Testing getters and setters
    std::cout << "Position: " << marketing.get_position() << std::endl;
    marketing.set_position("Senior Manager");
    std::cout << "New Position: " << marketing.get_position() << std::endl;

    std::cout << "Success Rate: " << marketing.get_success_rate() << std::endl;
    marketing.set_success_rate(0.85);
    std::cout << "New Success Rate: " << marketing.get_success_rate() << std::endl;

    return 0;
}
