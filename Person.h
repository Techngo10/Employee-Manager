#ifndef PERSON_H
#define PERSON_H

#include <ctime>
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
  int age;
  int phone_number;
  string name;
  string address;

public:
  Person();
  Person(int new_age, int new_phone, string new_name, string new_address);

  int get_age();
  void set_age(int new_age);

  int get_phone();
  void set_phone(int new_phone);

  string get_name();
  void set_name(string new_name);

  string get_address();
  void set_address(string new_address);
  
};

#endif