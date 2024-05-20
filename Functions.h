#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include "Location.h"

bool Access(Location *location, std::string& perms, std::string username, std::string password);

void Save(Location *location, std::string file);

void Load(Location *location, std::string file);

#endif // FUNCTIONS_H