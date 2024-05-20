#ifndef LOCATION_H
#define LOCATION_H

#include "Person.h"


class Location{
    private:
        std::string address;
        int curr_size;

    public:
        //People in public as it needs to be accessable
        Person** people;

        //Initialisation
        Location();
        Location(std::string address);

        //Deconstructor
        ~Location();

        //Functions
        bool addPerson(Person* new_person);
        bool rmPerson(const std::string& name);

        //Getters
        std::string get_address();
        int get_curr_size();

        //Setters
        void set_address(std::string address);
};

#endif // LOCATION_H