#include <iostream>
#include "Location.h"

int main() {
    // Create a location
    Location location("123 Main St");

    // Add some people
    Person person1(25, 123456789, "Alice", "123 Main St");
    Person person2(30, 987654321, "Bob", "456 Elm St");
    Person person3(35, 555555555, "Charlie", "789 Oak St");

    location.addPerson(person1);
    location.addPerson(person2);
    location.addPerson(person3);

    // Print initial people
    std::cout << "People in the location:" << std::endl;
    for (int i = 0; i < location.get_curr_size(); ++i) {
        std::cout << "Name: " << location.people[i].get_name() << ", Age: " << location.people[i].get_age() << std::endl;
    }

    // Remove a person
    location.rmPerson("Bob");

    // Print remaining people
    std::cout << "\nAfter removing Bob:" << std::endl;
    for (int i = 0; i < location.get_curr_size(); ++i) {
        std::cout << "Name: " << location.people[i].get_name() << ", Age: " << location.people[i].get_age() << std::endl;
    }

    return 0;
}