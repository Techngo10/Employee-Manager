#include "Location.h"
#include "Person.h"
#include <iostream>

using namespace std;

// Creates a location from a given address
Location::Location(string address) {
    this->address = address;
};

// Getters and Setters for address
string Location::get_address() {return address;};
void Location::set_address(string address) {this->address = address;};

// Code to add a person
bool Location::addPerson(Person new_person) { // Using the person
    auto it = std::find(people.begin(), people.end(), new_person); //Code to check if person is not already in the location
    if (it == people.end()) {
        people.push_back(new_person); // adds the person
        return true;
    }
    return false; // for if adding the person fails
};

// Code to remove a person
bool Location::rmPerson(const std::string& name) {  // Using the persons name
    auto it = std::find_if(people.begin(), people.end(), [&name](const Person& person) { // finds the person of name
        return person.get_name() == name; // comparing each person in the vector to name
    });

    if (it != people.end()) { // removes the person
        people.erase(it);
        return true;
    }

    return false; // for if removing the person fails
}





