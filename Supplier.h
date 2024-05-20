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
        string cargo;

    public:
        Supplier();
        Supplier(int age, int phone, string name, string address, int amountCargo, float costAnnually, string cargo);

        int get_amount_of_cargo();
        string get_cargo();
        float get_cost_annually();

        void set_amount_of_cargo(int amountCargo);
        void set_cargo(string cargo);
        void set_cost_annually(float costAnnually);

};


#endif