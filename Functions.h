#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include "Location.h"

//Function calls
bool Access(Location *location, std::string username, std::string password);    //To try a password and username
bool fileExists(const std::string& filename);                                   //To check if a file exists
void clear();                                                                   //To clear all the information shown on the screen
std::vector<std::string> splitString(const std::string& input);                 //To split a string for interpretation
int toInt(std::string input);                                                   //To convert an input to an integer (0 if invalid input)
float toFloat(const std::string& input);                                        //To convert an input to a float (0 if invalid input)
void runCommand(Location *location, std::string command);                       //To run a command
void Save(Location *location, std::string file);                                //To save the data
bool Load(Location *location, std::string file);                                //To load the data

#endif // FUNCTIONS_H