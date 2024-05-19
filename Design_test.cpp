// Design_test.cpp
#include "Design.h"
#include <iostream>

int main() {
    // Create a Design object
    Design designer(20.5, 40, "2024-01-01", 30, 1234567890, "John Doe", "123 Main St", "Designer", "Project1, Project2", "Project1");

    // Display initial details
    std::cout << "Initial Details:" << std::endl;
    std::cout << "Position: " << designer.get_position() << std::endl;
    std::cout << "Amount Designed Finished: " << designer.get_finished() << std::endl;
    std::cout << "Design Current: " << designer.get_design_current() << std::endl;

    // Update details
    designer.set_position("Senior Designer");
    designer.set_finished("Project 1");
    designer.set_design_current("New Design Project");

    // Display updated details
    std::cout << "\nUpdated Details:" << std::endl;
    std::cout << "Position: " << designer.get_position() << std::endl;
    std::cout << "Amount Designed Finished: " << designer.get_finished() << std::endl;
    std::cout << "Design Current: " << designer.get_design_current() << std::endl;

    return 0;
}
