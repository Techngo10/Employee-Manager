#include "Investor.h"

//Initialisation
Investor::Investor() : Person(), amount_of_investment(0.0) {};
Investor::Investor(int age, int phone, std::string name, std::string address, float amount_of_investment) 
: Person(age,phone,name,address), amount_of_investment(amount_of_investment) {};

//Getters
float Investor::get_amount_of_investment() {return amount_of_investment;};

//Setters
void Investor::set_amount_of_investment(float amount_of_investment) {this->amount_of_investment = amount_of_investment;};