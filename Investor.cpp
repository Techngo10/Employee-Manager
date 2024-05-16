#include "Investor.h"
#include <iostream>
#include <string.h>
 
using namespace std;

Investor::Investor() : Person(), amount_of_investment(0.0) {};

Investor::Investor(int age, int phone, string name, string address, float investment) :
 Person(age,phone,name,address), amount_of_investment(investment) {};

Investor::~Investor() {};

float Investor::get_amount_of_investment() {
    return amount_of_investment;
};

void Investor::set_amount_of_investment(float amount) {
    amount_of_investment = amount;
};