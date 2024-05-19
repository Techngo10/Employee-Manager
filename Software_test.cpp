#include "Person.h"
#include "Software.h"
#include "Employee.h"

#include <iostream>
#include <string.h>
using namespace std;
 
int main(){
    Software developer1;
        cout << "developer1: " << developer1.get_finished()<< endl;
        cout <<"developer1: " <<developer1.get_languages() << endl;
        cout <<"developer1: " <<developer1.get_position() <<endl;
        cout <<"developer1: " <<developer1.get_projects_current()<<endl;
        cout <<"developer1: " <<developer1.get_ID() << endl;

    Software developer2(50.05, 40.25, "11-01-2024", 30, 12345, "Jone", "Richmod", "AI Developer");
        cout <<  "developer2: " <<developer2.get_finished()<< endl;
        cout << "developer2: " <<developer2.get_languages() << endl;
        cout <<  "developer2: " <<developer2.get_position() << endl;
        cout <<  "developer2: " <<developer2.get_projects_current()<<endl;
        cout << "developer2: " <<developer2.get_ID() << endl;

        developer2.set_finished("Project 5");
        cout << "developer2: " <<developer2.get_finished()<< endl;
        developer2.set_language("python");
        cout <<"developer2: " <<developer2.get_languages() << endl;
        developer2.set_position("Big Data");
        cout << "developer2: " <<developer2.get_position() << endl;
        developer2.set_projects_current("creat Big Data");
        cout << "developer2: " <<developer2.get_projects_current()<<endl;

    return 0;


}