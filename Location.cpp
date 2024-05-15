#include "Location.h"
#include "Person.h"
#include <iostream>
#include <cstring>

using namespace std;

// Creates a location from a given address
Location::Location(string address) {
    this->address = address;
    people = new Person[0];
    curr_size = 0;
};

// Getters and Setters for address
string Location::get_address() {return address;};
void Location::set_address(string address) {this->address = address;};

// curr_size getter
int Location::get_curr_size() {return curr_size;};

// add person code using the person
bool Location::addPerson(Person new_person) {

    Person* new_people = new Person[curr_size + 1]; // Creates a new array of size one larger than the old one
    for (int i = 0; i < curr_size; i++){            // Copies the old array to the new array
        new_people[i] = people[i];
    }
    new_people[curr_size] = new_person;             // Creates the new person at the end of the array
    curr_size++;                                    // Increments curr_size for next time

    delete[] people;                                // Deletes the old array so there isnt a memory leak

    people = new_people;                            // Makes the old pointer now point to the new array

    return true;       
}

// remove person code using the name of the person (can be easily changed to other traits)
bool Location::rmPerson(const std::string& name) {

    int index = -1;                                 // Sets index at -1 to setup for the no found clause
    for (int i = 0; i < curr_size; i ++){           // Searches all the 
        if (people[i].get_name() == name){
            index = i;
            break;
        }
    }

    if (index == -1){                               // Clause for if no name found
        return false;
    }

    for (int i = index; i < curr_size - 1; i++){    // Shifts the array so that there are no holes where the removed employee is
        people[i] = people[i + 1];
    }

    curr_size--;                                    // Updates the size

    return true;
}



