#include "Supplier.h"
#include <iostream>
#include <string.h>
using namespace std;

        Supplier::Supplier():Person(), amount_cargo(0), cost_annually(0.0), Cargo(nullptr){};
        Supplier::Supplier(int age, int phone, string name, string address, int amountCargo, float costAnnually, string* cargos):
        Person(age,phone, name, address),  amount_cargo(amountCargo), cost_annually(costAnnually){
            Cargo = new string[amount_cargo];
            for (int i = 0; i < amount_cargo; i++) {
                Cargo[i] = cargos[i];
    }
        };
        Supplier::~Supplier(){
            delete[] Cargo;
        };

        int Supplier::get_amount_of_cargo(){
             return amount_cargo;
        };
        string* Supplier::get_cargo(){
            return Cargo;
        };
        float Supplier::get_cost_annually(){
            return cost_annually;
        };


        void Supplier::set_amount_of_cargo(int amountCargo){
            amount_cargo = amountCargo;
        };
        void Supplier::set_cargo(string* cargo, int amount){
            delete[] Cargo;
            Cargo = new string[amount];
            for (int i = 0; i < amount; i++) {
                Cargo[i] = cargo[i];
    }
        };
        void Supplier::set_cost_annually(float costAnnually){
            cost_annually = costAnnually;
        };