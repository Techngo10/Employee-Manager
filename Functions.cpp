#include "Functions.h"
#include <typeinfo>
#include <string>
#include <cstring>

// Password checking function
bool Access(Location *location, std::string& perms, std::string username, std::string password){
    int index = -1;                                                 // Sets index at -1 to setup for the no found clause
    for (int i = 0; i < location->get_curr_size(); i ++){           // Searches all the names in location to find the index
        if (location->people[i]->get_name() == username){
            index = i;
            break;
        }
    }

    if (index == -1){                                               // Clause for if no name found
        std::cout << "Username incorrect." << std::endl;
        return false;
    }

    if (location->people[index]->get_password() == password){       // Checking if the password matches

        if (strcmp(typeid(*location->people[index]).name(), "7Manager") == 0){ // In GCC compiling this works as typeid will show 7 representing the characters in the class then the class name
            perms = "Manager";                                      // A permission level is returned for later use
            std::cout << "Access granted." << std::endl;
            return true;
        }
    }

    std::cout << "Username or password is incorrect. " << std::endl; // If no other check it hit then the username must not match the password
    return false;

}