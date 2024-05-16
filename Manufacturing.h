#ifndef MANUFACTURING_H
#define MANUFACTURING_H

#include <iostream>
#include <string.h>
#include "Employee.h"
using namespace std;

class Manufacturing : public Employee {
    private:
        string position;
        string certification;
        int cars_complete;

    public:
        Manufacturing();
        Manufacturing(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string position, string certification, int cars_complete);

        string get_position();
        void set_position(string position);

        string get_certification();
        void add_certification(string certification);

        int get_cars_complete();
        void add_cars_complete(int cars_complete);



};

#endif