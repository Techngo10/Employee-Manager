#include "Finances.h"

Finances::Finances(): Employee(), position("none"), turnover_monthly(0), profit_monthly(0), budget(0), expense(0) {};
Finances::Finances(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, std::string position, int turnover_monthly, int profit_monthly, int budget, int expense) 
: Employee( salary_hourly, hours_weekly, date_joined, age, phone, name, address), position(position), turnover_monthly(turnover_monthly), profit_monthly(profit_monthly), budget(budget), expense(expense) {};

//Check turnover function
void Finances::check_turnover_profit(int turnover_monthly, int profit_monthly) {
    if (profit_monthly > turnover_monthly) {
        cout << "Profit cannot be bigger than turnover.\n";
        cout << "Enter turnover again: ";
        cin >> this->turnover_monthly;
                
        cout << "Enter profit again: ";
        cin >> this->profit_monthly;
                
    }
}

std::string Finances::get_position() {return position;};
int  Finances::get_turnover() {return turnover_monthly;};
int  Finances::get_profit() {return profit_monthly;};
int  Finances::get_budget() {return budget;};
int  Finances::get_expense() {return expense;};

void  Finances::set_position(std::string position) {this->position = position;};
void  Finances::set_turnover(int turnover_monthly) {this->turnover_monthly = turnover_monthly;};
void  Finances::set_profit(int profit_monthly) {this->profit_monthly = profit_monthly;};
void  Finances::set_budget(int budget) {this->budget = budget;};
void  Finances::set_expense(int expense) {this->expense = expense;};