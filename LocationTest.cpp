#include <iostream>
#include "Location.h"
#include "Software.h"

int main() {
    // Create a location
    Location location("123 Main St");

    // Add some people
    Person person1(25, 123456789, "Alice", "123 Main St");
    Person person2(30, 987654321, "Bob", "456 Elm St");
    Person person3(35, 555555555, "Charlie", "789 Oak St");
    Software software1(20, 40, "17th May", 20, 0412312451, "Victor", "city", "Top Programmer");


    location.addPerson(&person1);
    location.addPerson(&person2);
    location.addPerson(&person3);
    location.addPerson(&software1);

    // Print initial people
    std::cout << "People in the location:" << std::endl;
    for (int i = 0; i < location.get_curr_size(); ++i) {
        std::cout << "Name: " << location.people[i]->get_name() << ", Age: " << location.people[i]->get_age() << std::endl;
    }

    // Remove a person
    location.rmPerson("Bob");

    // Print remaining people
    std::cout << "\nAfter removing Bob:" << std::endl;
    for (int i = 0; i < location.get_curr_size(); ++i) {
        std::cout << "Name: " << location.people[i]->get_name() << ", Age: " << location.people[i]->get_age() << std::endl;
    }

    location.people[3]->set_position("Manager");

    std::cout << "Current project of the software: " << location.people[3]->get_position() << std::endl;

    return 0;
}