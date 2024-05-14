#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    Person Person1;
    cout << "Name: " << Person1.get_name() << endl;
    cout << "Age: " << Person1.get_age() << endl;
    cout << "Phone Number: " << Person1.get_phone() << endl;
    cout << "Address: " << Person1.get_address() << endl;

    Person Person2(30, 1234567890, "John", "I Live Here");
    cout << "Name: " << Person2.get_name() << endl;
    cout << "Age: " << Person2.get_age() << endl;
    cout << "Phone Number: " << Person2.get_phone() << endl;
    cout << "Address: " << Person2.get_address() << endl;

    Person2.set_address("New Address");
    Person2.set_age(32);

    cout << "Updated Address: " << Person2.get_address() << endl;
    cout << "Updated Age: " << Person2.get_age() << endl;

    return 0;
}