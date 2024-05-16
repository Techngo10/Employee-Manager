#include <iostream>
#include "ResearchDev.h"

int main() {
    // Creating a ResearchDev object
    ResearchDev researcher(30.0, 40.0, "2024-05-16", 35, 1234567890, "Alice Smith", "789 Elm St", "Senior Researcher", "Project A", "Project B", "Machine Learning");

    // Testing getters and setters
    std::cout << "Position: " << researcher.get_position() << std::endl;
    researcher.set_position("Lead Researcher");
    std::cout << "New Position: " << researcher.get_position() << std::endl;

    std::cout << "Finished Research: " << researcher.get_finished() << std::endl;
    researcher.add_finished("Project C");
    std::cout << "Updated Finished Research: " << researcher.get_finished() << std::endl;

    std::cout << "Current Research: " << researcher.get_research() << std::endl;
    researcher.set_research("Project D");
    std::cout << "New Current Research: " << researcher.get_research() << std::endl;

    std::cout << "Expertise: " << researcher.get_expertise() << std::endl;
    researcher.add_expertise("Deep Learning");
    std::cout << "Updated Expertise: " << researcher.get_expertise() << std::endl;

    return 0;
}
