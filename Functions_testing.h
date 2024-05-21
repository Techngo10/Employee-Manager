#ifndef FUNCTIONSTESTING_H
#define FUNCTIONSTESTING_H


#include <iostream>
#include <string>
#include "Location.h"

bool Access(Location *location, std::string& perms, std::string username, std::string password);

void Save(Location *location, std::string file);

void Load(Location *location, const std::string& file);




#endif