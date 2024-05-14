#include "Finances.h"
#include <iostream>
#include <string>
using namespace std;

        Finances::Finances(){Positions = "none"; turnover_monthly = 0; profit_monthly = 0; budget = 0; expense = 0;};
        Finances::Finances(string position, int turnoverMonth, int profitMonth, int Budget, int Expense){
            Positions = position ;
            turnover_monthly = turnoverMonth;
            profit_monthly = profitMonth; 
            budget = Budget; 
            expense = Expense;
        };

  
       void Finances::check_turnover_profit(int turnoverMonth, int profitMonth) {
            if (profitMonth > turnoverMonth) {
                cout << "Profit cannot be bigger than turnover.\n";
                cout << "Enter turnover again: ";
                cin >> this->turnover_monthly;
                
                cout << "Enter profit again: ";
                cin >> this->profit_monthly;
                
    }
}

        string Finances::get_position(){return Positions;};
        int  Finances::get_turnover(){return turnover_monthly;};
        int  Finances::get_profit(){return profit_monthly;};
        int  Finances::get_budget(){return budget;};
        int  Finances::get_expense(){return expense;};

        void  Finances::set_position(string position){Positions = position;};
        void  Finances::set_turnover(int turnoverMonth){turnover_monthly = turnoverMonth;};
        void  Finances::set_profit(int profitMonth){profit_monthly = profitMonth;};
        void  Finances::set_budget(int Budget){budget = Budget;};
        void  Finances::set_expense(int Expense){expense = Expense;};