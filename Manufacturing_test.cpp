#include <iostream>
#include "Manufacturing.h"

int main() {
    // Create a Manufacturing object
    Manufacturing employee1(20.5, 40, "2024-01-01", 30, 1234567890, "John Doe", "123 Main St", "Manager", "Certified", 10);

    // Test member functions
    std::cout << "Position: " << employee1.get_position() << std::endl;
    std::cout << "Certification: " << employee1.get_certification() << std::endl;
    std::cout << "Cars Completed: " << employee1.get_cars_complete() << std::endl;

    // Update position, certification, and cars completed
    employee1.set_position("Supervisor");
    employee1.add_certification("Advanced Certified");
    employee1.add_cars_complete(5);

    // Test member functions after update
    std::cout << "\nAfter Update:" << std::endl;
    std::cout << "Position: " << employee1.get_position() << std::endl;
    std::cout << "Certification: " << employee1.get_certification() << std::endl;
    std::cout << "Cars Completed: " << employee1.get_cars_complete() << std::endl;

    return 0;
}
