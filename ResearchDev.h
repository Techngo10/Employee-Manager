#ifndef RESEARCHDEV_H
#define RESEARCHDEV_H

#include <iostream>
#include <string>

using namespace std;

class ResearchDev {
    private:
        std::string position;
        std::string finished_research;
        std::string current_research;
        std::string expertise;

    public:
        ResearchDev();
        ResearchDev(std::string new_position, std::string finished, std::string current, std::string expert);

        std::string get_position();
        void set_position(std::string new_position);

        std::string get_finished();
        void add_finished(std::string finished);

        std::string get_research();
        void set_research(std::string current);

        std::string get_expertise();
        void add_expertise(std::string expert);

};

#endif