#include "Location.h"
#include "Person.h"
#include <iostream>

int main() {
    Location l1("testlocation");

    Person p1(12, 0411, "name", "address");
    Person p2(122, 04112, "name2", "address2");
    Person p3(123, 04113, "name3", "address3");
    Person p4(124, 04114, "name4", "address4");

    // Adding people to the location
    l1.addPerson(p1);
    l1.addPerson(p2);
    l1.addPerson(p3);
    l1.addPerson(p4);

    // Displaying initial list of people
    std::cout << "Initial list of people in location:" << std::endl;
    for (const Person& person : l1.people) {
        std::cout << "Name: " << person.get_name() << ", Age: " << person.get_age() << ", Phone: " << person.get_phone() << ", Address: " << person.get_address() << std::endl;
    }
    std::cout << std::endl;

    // Removing a person by name
    std::string nameToRemove = "name2";
    std::cout << "Removing person with name: " << nameToRemove << std::endl;
    bool removed = l1.rmPerson(nameToRemove);
    if (removed) {
        std::cout << "Person removed successfully." << std::endl;
    } else {
        std::cout << "Person with name '" << nameToRemove << "' not found in the location." << std::endl;
    }
    std::cout << std::endl;

    // Displaying updated list of people
    std::cout << "Updated list of people in location:" << std::endl;
    for (const Person& person : l1.people) {
        std::cout << "Name: " << person.get_name() << ", Age: " << person.get_age() << ", Phone: " << person.get_phone() << ", Address: " << person.get_address() << std::endl;
    }

    return 0;
}