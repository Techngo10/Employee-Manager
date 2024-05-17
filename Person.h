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

  int get_age() const;
  void set_age(int new_age);

  int get_phone() const;
  void set_phone(int new_phone);

  string get_name() const;
  void set_name(string new_name);

  string get_address() const;
  void set_address(string new_address);

  bool operator==(const Person& other) const;


  // Virtual functions
  virtual void set_position(string position);
  virtual string get_position();
  
};

#endif