#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "Person.h"
#include <iostream>
#include <string.h>
 
using namespace std;
 
 

class Supplier: public Person {
    private:
        int amount_cargo;
        float cost_annually;
        string* Cargo;

    public:
        Supplier();
        Supplier(int age, int phone, string name, string address, int amountCargo, float costAnnually, string* cargos);
        ~Supplier();

        int get_amount_of_cargo();
        string* get_cargo();
        float get_cost_annually();

        void set_amount_of_cargo(int amountCargo);
        void set_cargo(string* cargo, int amount);
        void set_cost_annually(float costAnnually);

};


#endif