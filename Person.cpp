#include "Person.h"
#include <iostream>
#include <ctime>

Person::Person(){age = 0, phone_number = 0, name = "name", address = "address";};
Person::Person(int new_age, int new_phone, std::string new_name, std::string new_address){
    age = new_age;
    phone_number = new_phone;
    name = new_name;
    address = new_address;
};

int Person::get_age(){return age;};
void Person::set_age(int new_age){age = new_age;};

int Person::get_phone(){return phone_number;};
void Person::set_phone(int new_phone){phone_number = new_phone;};

std::string Person::get_name(){return name;};
void Person::set_name(std::string new_name){name = new_name;};

std::string Person::get_address(){return address;};
void Person::set_address(std::string new_address){address = new_address;};
