#ifndef INVESTOR_H
#define INVESTOR_H

#include "Person.h"
#include <iostream>
#include <string.h>
 
using namespace std;
class Investor : public Person{
    private: 
        float amount_of_investmwnt;
    
    public:
        Investor();
        Investor(int age, int phone, string name, string address, float investment);
        ~Investor();

        float get_amount_of_investment();
        void set_amount_of_investment(float amount);

        // Check Finances, Sales, Marketing of company

};

#endif