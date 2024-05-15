#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;
int Employee::_counter = 0;
Employee::Employee() : ID(_counter), salary_hourly(0), hours_weekly(0), date_joined(""), performance(5) {
    for (int i = 0; i < 5; i++) {
        attendance[i] = true; // Monday -> Friday
    }
    attendance[5] = false; // Saturday
    attendance[6] = false; // Sunday
    _counter++;
}

Employee::Employee( float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address)
    :  ID(_counter), Person(age, phone, name, address), salary_hourly(salary_hourly), hours_weekly(hours_weekly), date_joined(date_joined), performance(5) {
    for (int i = 0; i < 5; i++) {
        attendance[i] = true; // Monday -> Friday
    }
    attendance[5] = false; // Saturday
    attendance[6] = false; // Sunday
    _counter++;
}

int Employee::get_ID() {return ID;};
//void Employee::set_ID(int ID) {this->ID = ID;};

bool Employee::get_attendance(int day) {
    if(day >= 0 && day <=6){ // if valid day
        return attendance[day]; // get attendance
    }
    return false; // default false if out of range
};
void Employee::set_attendance(bool attending, int day) {
    if(day >= 0 && day <=6){ // if valid day
        attendance[day] = attending; // set attendacnce to desired
    }
};

int Employee::get_performance() {return performance;};
void Employee::set_performance(int performance) {this->performance = performance;};

string Employee::get_date_joined() {return date_joined;};

float Employee::get_salary_hourly() {return salary_hourly;};
void Employee::set_salary_hourly(float salary_hourly) {this->salary_hourly = salary_hourly;};

float Employee::get_hours_weekly() {return hours_weekly;};
void Employee::set_hours_weekly(float hours_weekly) {this->hours_weekly = hours_weekly;};
