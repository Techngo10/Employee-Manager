#include "Location.h"
#include "Person.h"

//Initialisation
Location::Location() {
    address = "none";
    people = new Person*[0];    //Creats an array with 0 size as people will be added with a function
    curr_size = 0;
};
Location::Location(string address) {
    this->address = address;
    people = new Person*[0];
    curr_size = 0;
};

// add person code using the person
bool Location::addPerson(Person* new_person) {
    Person** new_people = new Person*[curr_size + 1]; // Creates a new array of size one larger than the old one
    for (int i = 0; i < curr_size; i++) {new_people[i] = people[i];} // Copies the old array to the new array
    new_people[curr_size] = new_person; // Creates the new person at the end of the array
    curr_size++; // Increments curr_size for next time

    delete[] people; // Deletes the old array so there isnt a memory leak
    people = new_people; // Makes the old pointer now point to the new array
    return true;       
}

// remove person code using the name of the person (can be easily changed to other traits)
bool Location::rmPerson(const std::string& name) {

    int index = -1; // Sets index at -1 to setup for the no found clause
    for (int i = 0; i < curr_size; i ++){ // Searches all the people for a matching name
        if (people[i]->get_name() == name){
            index = i;
            break;
        }
    }

    if (index == -1) {return false;} // Clause for if no name found

    for (int i = index; i < curr_size - 1; i++){ // Shifts the array so that there are no holes where the removed employee is
        people[i] = people[i + 1];
    }
    curr_size--; // Updates the size

    // Code to remove the extra size of the dynamic array
    Person** new_people = new Person*[curr_size]; // Creates a new array of correct size
    for (int i = 0; i < curr_size; i++){ // Copies the old array to the new array
        new_people[i] = people[i];
    }

    delete[] people; // Deletes the old array so there isnt a memory leak

    people = new_people; // Makes the old pointer now point to the new array
    
    return true;
}


// Getters
string Location::get_address() {return address;};
int Location::get_curr_size() {return curr_size;};

//Setters
void Location::set_address(string address) {this->address = address;};

//Deconstructor
Location::~Location() {delete[] people;}