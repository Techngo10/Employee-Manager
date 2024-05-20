#include <iostream>
#include "Sales.h"

int main() {
    // Creating a Sales object
    Sales salesperson(20.0, 40.0, "2024-05-16", 30, 1234567890, "John Doe", "123 Main St", "Sales Associate", 0.75, 10, 50000.0);

    // Testing getters and setters
    std::cout << "Position: " << salesperson.get_position() << std::endl;
    salesperson.set_position("Senior Sales Associate");
    std::cout << "New Position: " << salesperson.get_position() << std::endl;

    std::cout << "Conversion Rate: " << salesperson.get_conversion_rate() << std::endl;
    salesperson.set_conversion_rate(0.8);
    std::cout << "New Conversion Rate: " << salesperson.get_conversion_rate() << std::endl;

    std::cout << "Cars Sold: " << salesperson.get_cars_sold() << std::endl;
    salesperson.set_cars_sold(5);
    std::cout << "Updated Cars Sold: " << salesperson.get_cars_sold() << std::endl;

    std::cout << "Revenue: $" << salesperson.get_revenue() << std::endl;
    salesperson.set_revenue(75000.0);
    std::cout << "Updated Revenue: $" << salesperson.get_revenue() << std::endl;

    return 0;
}
