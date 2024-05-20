#ifndef SALES_H
#define SALES_H

#include "Employee.h"
#include <iostream>
#include <string.h>
using namespace std;

class Sales : public Employee {
    private:
        string position;
        float conversion_rate;
        int cars_sold;
        float revenue;

    public:
        Sales();
        Sales(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, 
        string new_position, float con_rate, int sales, float rev);

        string get_position();
        void set_position(string new_position);

        float get_conversion_rate();
        void set_conversion_rate(float con_rate);

        int get_cars_sold();
        void set_cars_sold(int sales);

        float get_revenue();
        void set_revenue(float rev);


};

#endif //SALES_H