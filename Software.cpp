#include <iostream>
#include "Person.h"
#include "Software.h"
using namespace std;

Software::Software(){
    amount_projects_finished = 0; 
    projects_current = "none";
    Positions = "none";
    Languages = "none";
    
};

Software::Software( string position, string languages, int amountProjectsFinished, string projectCurrent){
    amount_projects_finished = amountProjectsFinished;
    projects_current = projectCurrent;
    Positions =  position;
    Languages = languages;

};
string Software::get_position(){return Positions;};
string Software::get_languages(){return Languages;};
string Software::get_projects_current(){return projects_current;};
int Software::get_finished(){return amount_projects_finished;};


void Software::set_position(string position){
    Positions = position;
};

void Software::add_language(string languages){
    Languages = languages;
};

void Software::add_finished(int num){ amount_projects_finished += num;};
void Software::set_projects_current(string currentProjects){projects_current = currentProjects;};