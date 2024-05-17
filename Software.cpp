#include <iostream>
#include <string.h>
#include "Software.h"
using namespace std;

Software::Software():Employee(), Positions("none"), projects_finished(""), projects_current("none"), Languages("none"){};

Software::Software(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string position)
:  Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), Positions(position), projects_finished(""),projects_current("none"), Languages("none"){};

string Software::get_position(){return Positions;};
string Software::get_languages(){return Languages;};
string Software::get_projects_current(){return projects_current;};
string Software::get_finished(){return projects_finished;};



void Software::set_position(string position){
    Positions = position;
};
void Software::set_language(string languages){
    Languages = languages;
};
void Software::set_finished(string finished){ 
    projects_finished = finished;
};
void Software::set_projects_current(string currentProjects){
    projects_current = currentProjects;
};