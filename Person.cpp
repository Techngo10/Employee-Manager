#include "Person.h"
#include <iostream>
#include <ctime>
using namespace std;

Person::Person(){age = 0, phone_number = 0, name = "name", address = "address";};
Person::Person(int new_age, int new_phone, string new_name, string new_address){
    age = new_age;
    phone_number = new_phone;
    name = new_name;
    address = new_address;
};

int Person::get_age() const {return age;};
void Person::set_age(int new_age){age = new_age;};

int Person::get_phone() const {return phone_number;};
void Person::set_phone(int new_phone){phone_number = new_phone;};

string Person::get_name() const {return name;};
void Person::set_name(string new_name){name = new_name;};

string Person::get_address() const {return address;};
void Person::set_address(string new_address){address = new_address;};


bool Person::operator==(const Person& other) const {
    return (age == other.age && phone_number == other.phone_number && 
            name == other.name && address == other.address);
}