#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <iostream>
#include "Person.h"
using namespace std;

class Software{
    private:
        Person **Positions;
        string **Languages;
        int amount_projects_finished;
        string projects_current;

    public:
        Software();
        Software(std::string &position, string &languages, int amount_projects_finished, string projects_current);
        string get_position();
        string get_languages();
        string get_projects_current();
        int get_finished();

        void set_position(string &position);
        void add_language(string &languages);
        void add_finished(int num);
        void set_projects_current(string currentProjects);

};

#endif