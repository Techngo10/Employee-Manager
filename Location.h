#ifndef LOCATION_H
#define LOCATION_H

#include "Person.h"
#include <vector>

class Location{
    private:
        std::string address;
        int curr_size;

        //Functions to be used internally
        std::vector<std::string> splitString(const std::string& input);                  //To split a string for interpretation
        int toInt(std::string input);                                                    //To convert an input to an integer (0 if invalid input)
        float toFloat(const std::string& input);                                         //To convert an input to a float (0 if invalid input)

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


        //Functions
        bool fileExists(const std::string& filename);                                   //To check if a file exists
        void clear();                                                                   //To clear all the information shown on the screen
        bool Access(std::string username, std::string password);                        //To try a password and username
        void runCommand(std::string command);                                           //To run a command
        void Save(std::string file);                                                    //To save the data
        bool Load(std::string file);                                                    //To load the data
};

#endif // LOCATION_H