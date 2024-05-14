#include "Marketing.h"
#include <iostream>
#include <string.h>
using namespace std;

Marketing::Marketing(){"position", 0};
Marketing::Marketing(string new_position, float success){
    
};

string Marketing::get_position(){return position;};
void Marketing::set_position(string new_position){
    position = new_position;

};

float Marketing::get_success_rate(){return success_rate;};
void Marketing::set_success_rate(float success){
    success_rate = success;

};