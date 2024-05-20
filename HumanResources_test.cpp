#include <iostream>
#include <string.h>
#include "HumanResources.h"
#include "Person.h"
#include "Employee.h"

int main() {
    // Creating a HumanResources object
    HumanResources hr(20.0, 40.0, "2024-05-16", 30, 1234567890, "John Doe", "123 Main St", "Manager");

    // Testing getters and setters
    std::cout << "Position: " << hr.get_position() << std::endl;
    hr.set_position("Assistant Manager");
    std::cout << "New Position: " << hr.get_position() << std::endl;

    // Testing adders
    hr.set_trained(5);
    hr.set_hired(2);
    hr.set_fired(1);
    hr.set_retired(3);

    // Testing getters for added values
    std::cout << "Trained: " << hr.get_trained() << std::endl;
    std::cout << "Hired: " << hr.get_hired() << std::endl;
    std::cout << "Fired: " << hr.get_fired() << std::endl;
    std::cout << "Retired: " << hr.get_retired() << std::endl;

    return 0;
}
