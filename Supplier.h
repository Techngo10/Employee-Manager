#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "Person.h"

class Supplier: public Person {
    private:
        int amount_cargo;
        float cost_annually;
        std::string cargo;

    public:
    //Initialisation
        Supplier();
        Supplier(int age, int phone, std::string name, std::string address, int amountCargo, float costAnnually, std::string cargo);

    //Getter
        int get_amount_of_cargo();
        std::string get_cargo();
        float get_cost_annually();
        
    //Setter
        void set_amount_of_cargo(int amountCargo);
        void set_cargo(std::string cargo);
        void set_cost_annually(float costAnnually);

};


#endif //SUPPLIER_H