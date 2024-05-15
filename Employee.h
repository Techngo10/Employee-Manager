#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Employee: public Person{
private:
    int ID;
    float salary_hourly;
    float hours_weekly;
    bool attendance[7];
    string date_joined;
    int performance;
 
public:
    static int _counter;
    Employee();
    Employee(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address);

    int get_ID();
    //void set_ID(int ID);

    bool get_attendance(int day);
    void set_attendance(bool attending, int day);

    int get_performance();
    void set_performance(int performance);

    string get_date_joined();

    float get_salary_hourly();
    void set_salary_hourly(float salary_hourly);

    float get_hours_weekly();
    void set_hours_weekly(float hours_weekly);

};


 
#endif // EMPLOYEE_H
 