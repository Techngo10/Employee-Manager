#include "Software.h"

//Initialisation
Software::Software()
    : Employee(), positions("none"), languages("none"), projects_finished("none"), projects_current("none") {}
Software::Software(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, std::string position)
    : Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), positions(position), languages("none"), projects_finished("none"), projects_current("none") {}

//Getters
std::string Software::get_position() {return positions;};
std::string Software::get_languages() {return languages;};
std::string Software::get_projects_current() {return projects_current;};
std::string Software::get_finished() {return projects_finished;};

//Setters
void Software::set_position(std::string position) {this->positions = position;};
void Software::set_language(std::string languages) {this->languages = languages;};
void Software::set_finished(std::string projects_finished) {this->projects_finished = projects_finished;};
void Software::set_projects_current(std::string projects_current) {this->projects_current = projects_current;};