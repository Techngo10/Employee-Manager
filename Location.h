#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include "Person.h"
#include <vector>
#include <algorithm>
using namespace std;

class Location{
private:
    string address;
    int curr_size;

public:
    Person* people;
    
    Location(string address);

    string get_address();
    void set_address(string address);
    int get_curr_size();

    bool addPerson(Person new_person);
    bool rmPerson(const std::string& name);

};


#endif // LOCATION_H