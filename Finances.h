#ifndef FINANCES_H
#define FINANCES_H

#include "Employee.h"

class Finances: public Employee{
    private:
        std::string position;
        int turnover_monthly;
        int profit_monthly;
        int budget;
        int expense;

    public:
        //Initialisation
        Finances();
        Finances(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, 
        std::string position, int turnover_monthly, int profit_monthly, int budget, int expense);

        //Function to check the profit vs the turnover
        void check_turnover_profit(int turnover_monthly, int profit_monthly);
        
        //Getters
        std::string get_position();
        int get_turnover();
        int get_profit();
        int get_budget();
        int get_expense();

        //Setters
        void set_position(std::string position);
        void set_turnover(int turnover_monthly);
        void set_profit(int profit_monthly);
        void set_budget(int budget);
        void set_expense(int expense);
};


#endif