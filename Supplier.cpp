#include "Supplier.h"

//Initialisation
Supplier::Supplier():Person(), amount_cargo(0), cost_annually(0.0), cargo("none"){};
Supplier::Supplier(int age, int phone, std::string name, std::string address, int amountCargo, float costAnnually, std::string cargo):
Person(age, phone, name, address),  amount_cargo(amountCargo), cost_annually(costAnnually), cargo(cargo) {};

//Getter
int Supplier::get_amount_of_cargo(){return amount_cargo;};
std::string Supplier::get_cargo(){return cargo;};
float Supplier::get_cost_annually(){return cost_annually;};
//Setter
void Supplier::set_amount_of_cargo(int amountCargo){amount_cargo = amountCargo;};
void Supplier::set_cargo(std::string cargo){this->cargo = cargo;};
void Supplier::set_cost_annually(float costAnnually){cost_annually = costAnnually;};