#ifndef MANAGER_H
#define MANAGER_H 

#include "Employee.h"
#include "Software.h"
#include "Finances.h"
#include "Design.h"
#include "Manufacturing.h"
#include "HumanResources.h"
#include "ResearchDev.h"
#include "Sales.h"
#include "Marketing.h"
 
#include <iostream>
#include <string.h>
using namespace std;

class Manager : public Employee {
    private:
        string password; 
        string position;
        int level;

    public:
        Manager();
        Manager(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address,
         string pass, string pos);

        string get_password();
        void set_password(string pass);

        string get_position();
        void set_position(string pos);

};

#endif

        // string get_position();
        // string get_languages();
        // string get_projects_current();
        // int get_finished();

        // Manager::Software()