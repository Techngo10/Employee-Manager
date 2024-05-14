#include "ResearchDev.h"
#include <iostream>
#include <string>
using namespace std;

// Initialise Default values and changeable values
ResearchDev::ResearchDev(){position = "position", finished_research = "none", current_research = "none", expertise = "none";};
ResearchDev::ResearchDev(std::string new_position, std::string finished, std::string current, std::string expert){
    position = new_position;
    finished_research = finished;
    current_research = current;
    expertise = expert;
};

// Getter and Setters for Research Development variables
std::string ResearchDev::get_position(){return position;};
void ResearchDev::set_position(std::string new_position){position = new_position;};

std::string ResearchDev::get_finished(){return finished_research;};
void ResearchDev::add_finished(std::string finished){finished_research = finished;};

std::string ResearchDev::get_research(){return current_research;};
void ResearchDev::set_research(std::string current){current_research = current;};

std::string ResearchDev::get_expertise(){return expertise;};
void ResearchDev::add_expertise(std::string expert){expertise = expert;};
