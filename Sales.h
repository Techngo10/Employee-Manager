#ifndef SALES_H
#define SALES_H

#include "Employee.h"

class Sales : public Employee {
    private:
        std::string position;
        float conversion_rate;
        int cars_sold;
        float revenue;

    public:
        //Initialisation
        Sales();
        Sales(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, 
        std::string position, float conversion_rate, int cars_sold, float revenue);
        
        //Getters
        std::string get_position();
        float get_conversion_rate();
        int get_cars_sold();
        float get_revenue();

        //Setters
        void set_position(std::string position);
        void set_conversion_rate(float conversion_rate);
        void set_cars_sold(int cars_sold);
        void set_revenue(float revenue);


};

#endif //SALES_H