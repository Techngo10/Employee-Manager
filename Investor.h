#ifndef INVESTOR_H
#define INVESTOR_H

#include "Person.h"
 
class Investor : public Person{
    private: 
        float amount_of_investment;
    
    public:
        //Initialisation
        Investor();
        Investor(int age, int phone, std::string name, std::string address, float amount_of_investment);

        //Getters
        float get_amount_of_investment();

        //Setters
        void set_amount_of_investment(float amount_of_investment);

};

#endif