#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <ctime>

class Person {
    private:
        int age;
        int phone_number;
        std::string name;
        std::string address;

    public:
        Person();
        Person(int new_age, int new_phone, std::string new_name, std::string new_address);

        int get_age();
        void set_age(int new_age);

        int get_phone();
        void set_phone(int new_phone);

        std::string get_name();
        void set_name(std::string new_name);

        std::string get_address();
        void set_address(std::string new_address);

};

#endif