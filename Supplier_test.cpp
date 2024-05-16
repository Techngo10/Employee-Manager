#include "Supplier.h"
#include <iostream>
using namespace std;

int main(){
    string cargos[2] = {"wheel", "engine"};
    string* cargos1 = cargos;
    Supplier supplier(22, 12345, "Bob Peter", "West Terrace", 2, 120000.4, cargos1);

    cout << "Amount of cargo: " << supplier.get_amount_of_cargo()<< endl;
    cout << "cost annually: " << supplier.get_cost_annually() << endl;
    string* items = supplier.get_cargo();
    for(int i  = 0 ; i < supplier.get_amount_of_cargo() ; i++){
        cout << "cargo item: " << items[i] << endl;
    }
    cout << "begin setting";
    supplier.set_amount_of_cargo(4);
    string newCargos[4] = {"Item 4", "Item 5", "Item 6", "Item 7"};
    string* cargos2 = newCargos;
    supplier.set_cargo(cargos2, 4);
    supplier.set_cost_annually(1500.012);
    cout << "Amount of cargo: " << supplier.get_amount_of_cargo()<< endl;
    cout << "cost annually: " << supplier.get_cost_annually() << endl;
    items = supplier.get_cargo();
    for(int j  = 0 ; j < supplier.get_amount_of_cargo() ; j++){
        cout << "cargo item: " << items[j] << endl;
    }

    return 0;
}
