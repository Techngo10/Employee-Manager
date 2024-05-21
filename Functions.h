#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include "Location.h"

bool Access(Location *location, std::string username, std::string password);

bool fileExists(const std::string& filename);

std::vector<std::string> splitString(const std::string& input);

int toInt(std::string input);

float toFloat(const std::string& input);

void runCommand(Location *location, std::string command);

void Save(Location *location, std::string file);

bool Load(Location *location, std::string file);

#endif // FUNCTIONS_H