#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>
#include <string.h>
using namespace std;
class Finances{
    private:
        string Positions;
        int turnover_monthly;
        int profit_monthly;
        int budget;
        int expense;

    public:
        Finances();
        Finances(string position, int turnoverMonth, int profitMonth, int Budget, int Expense);

        void check_turnover_profit(int turnoverMonth, int profitMonth);
        
        string get_position();
        int get_turnover();
        int get_profit();
        int get_budget();
        int get_expense();

        void set_position(string position);
        void set_turnover(int turnoverMonth);
        void set_profit(int profitMonth);
        void set_budget(int Budget);
        void set_expense(int Expense);
};


#endif
