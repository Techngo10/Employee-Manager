#ifndef MARKETING_H
#define MARKETING_H

#include <iostream>
#include <string.h>
using namespace std;

class Marketing {
    private:
        string position;
        float success_rate;

    public:
        Marketing();
        Marketing(string new_position, float success);

        string get_position();
        void set_position(string new_position);

        float get_success_rate();
        void set_success_rate(float success);

};

#endif //MARKETING_H
