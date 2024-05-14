#include "Person.h"
#include "Software.h"

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    Software developer1;
    cout << developer1.get_finished()<< endl;
    cout <<developer1.get_languages() << endl;
    cout <<developer1.get_position() <<endl;
     cout <<developer1.get_projects_current()<<endl;

    Software developer2("AI developer", "C++, Java", 3, "AI environmental development");
        cout << developer2.get_finished()<< endl;
        cout <<developer2.get_languages() << endl;
        cout << developer2.get_position() << endl;
        cout << developer2.get_projects_current()<<endl;

        developer2.add_finished(1);
        cout << developer2.get_finished()<< endl;
        developer2.add_language("python");
        cout <<developer2.get_languages() << endl;
        developer2.set_position("Big Data");
        cout << developer2.get_position() << endl;
        developer2.set_projects_current("creat Big Data");
        cout << developer2.get_projects_current()<<endl;


}