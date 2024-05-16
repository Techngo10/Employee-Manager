#include "ResearchDev.h"
#include <iostream>
#include <string>
using namespace std;

// Initialise Default values and changeable values
ResearchDev::ResearchDev() : position("none"), finished_research("none"), current_research("none"), expertise("none") {}
ResearchDev::ResearchDev(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string new_position, string finished, string current, string expert)
: Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), position(new_position), finished_research(finished), current_research(current), expertise(expert) {}

// Getter and Setters for Research Development variables
string ResearchDev::get_position(){return position;};
void ResearchDev::set_position(string new_position){position = new_position;};

string ResearchDev::get_finished(){return finished_research;};
void ResearchDev::add_finished(string finished){finished_research = finished;};

string ResearchDev::get_research(){return current_research;};
void ResearchDev::set_research(string current){current_research = current;};

string ResearchDev::get_expertise(){return expertise;};
void ResearchDev::add_expertise(string expert){expertise = expert;};
