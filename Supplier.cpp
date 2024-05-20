#include "Supplier.h"
#include <iostream>
#include <string.h>
using namespace std;

        Supplier::Supplier():Person(), amount_cargo(0), cost_annually(0.0), cargo(0){};
        Supplier::Supplier(int age, int phone, string name, string address, int amountCargo, float costAnnually, string cargo):
        Person(age, phone, name, address),  amount_cargo(amountCargo), cost_annually(costAnnually), cargo(cargo) {};

        int Supplier::get_amount_of_cargo(){
             return amount_cargo;
        };
        string Supplier::get_cargo(){
            return cargo;
        };
        float Supplier::get_cost_annually(){
            return cost_annually;
        };


        void Supplier::set_amount_of_cargo(int amountCargo){
            amount_cargo = amountCargo;
        };
        void Supplier::set_cargo(string cargo){
            this->cargo = cargo;
        };
        void Supplier::set_cost_annually(float costAnnually){
            cost_annually = costAnnually;
        };