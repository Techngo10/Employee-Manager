#include "Employee.h"

//Sets static counter to 0
int Employee::_counter = 0;

//Initialisation
Employee::Employee() : Person(), ID(_counter), salary_hourly(0), hours_weekly(0), date_joined(""), performance(5) {
    for (int i = 0; i < 5; i++) {attendance[i] = true;} // Monday -> Friday
    attendance[5] = false; // Saturday
    attendance[6] = false; // Sunday
    _counter++;
}
Employee::Employee( float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address)
    :  Person(age, phone, name, address), ID(_counter), salary_hourly(salary_hourly), hours_weekly(hours_weekly), date_joined(date_joined), performance(5) {
    for (int i = 0; i < 5; i++) {attendance[i] = true;} // Monday -> Friday
    attendance[5] = false; // Saturday
    attendance[6] = false; // Sunday
    _counter++;
}

//Getters
int Employee::get_counter() {return _counter;};
int Employee::get_ID() {return ID;};
bool Employee::get_attendance(int day) {
    if(day >= 0 && day <=6) {return attendance[day];} // get attendance for day
    return false; // default false if out of range
};
int Employee::get_performance() {return performance;};
std::string Employee::get_date_joined() {return date_joined;};
float Employee::get_salary_hourly() {return salary_hourly;};
float Employee::get_hours_weekly() {return hours_weekly;};

//Setters
void Employee::set_counder(int counter) {_counter = counter;};
void Employee::set_ID(int ID) {this->ID = ID;};
void Employee::set_attendance(bool attending, int day) {
    if(day >= 0 && day <=6) {attendance[day] = attending;} // set attendacnce to desired value
};
void Employee::set_performance(int performance) {this->performance = performance;};
void Employee::set_date_joined(std::string date_joined) {this->date_joined = date_joined;};
void Employee::set_salary_hourly(float salary_hourly) {this->salary_hourly = salary_hourly;};
void Employee::set_hours_weekly(float hours_weekly) {this->hours_weekly = hours_weekly;};
