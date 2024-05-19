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
  // Software functions
  virtual void set_position(string position);
  virtual void set_language(string languages);
  virtual void set_finished(string finsihed);
  virtual void set_projects_current(string currentProjects);

  virtual string get_position();
  virtual string get_languages();
  virtual string get_projects_current();
  virtual string get_finished();


  // Finances functions
  virtual void check_turnover_profit(int turnoverMonth, int profitMonth);
         
  virtual void set_turnover(int turnoverMonth);
  virtual void set_profit(int profitMonth);
  virtual void set_budget(int Budget);
  virtual void set_expense(int Expense);

  
  virtual int get_turnover();
  virtual int get_profit();
  virtual int get_budget();
  virtual int get_expense();

  //Customer functions
  virtual int get_bankAccount();
  virtual void set_bankAccount(int bank_num);

  virtual string get_bank();
  virtual void set_bank(string BANK);

  virtual string get_purchase_history();
  virtual int get_spendings();
  virtual int get_clientId();

  virtual string get_notes();
  virtual void set_notes(string new_note);

  //Design functions
  // /virtual string get_position();
  // virtual void set_position(string position);

  // virtual string get_finished();
  // virtual void add_finished(string amount_design_finished);

  virtual string get_design_current();
  virtual void set_design_current(string design_current);


  // Sales
  virtual float get_conversion_rate();
  virtual void set_conversion_rate(float con_rate);

  virtual int get_cars_sold();
  virtual void add_cars_sold(int sales);

  virtual float get_revenue();
  virtual void add_revenue(float rev);
  

  // Researh Development
  virtual void add_finished(string finished);

  virtual string get_research();
  virtual void set_research(string current);

  virtual string get_expertise();
  virtual void add_expertise(string expert);

  // Employee functions
  virtual int get_ID();

  virtual bool get_attendance(int day);
  virtual void set_attendance(bool attending, int day);

  virtual int get_performance();
  virtual void set_performance(int performance);

  virtual string get_date_joined();

  virtual float get_salary_hourly();
  virtual void set_salary_hourly(float salary_hourly);

  virtual float get_hours_weekly();
  virtual void set_hours_weekly(float hours_weekly);

  //HumanResources
  //virtual string get_position();
  //virtual void set_position(std::string new_position);

  virtual int get_trained();
  virtual void add_trained(int trained);

  virtual int get_hired();
  virtual void add_hired(int hired);

  virtual int get_fired();
  virtual void add_fired(int fired);

  virtual int get_retired();
  virtual void add_retired(int retired);

  
  //Investor
  virtual float get_amount_of_investment();
  virtual void set_amount_of_investment(float amount);
  
  //Manager
  virtual string get_password();
  virtual void set_password(string pass);

  //virtual string get_position();
  //virtual void set_position(string pos);

  //Marketing
  virtual float get_success_rate();
  virtual void set_success_rate(float success);

  //Supplier

  virtual int get_amount_of_cargo();
  virtual string* get_cargo();
  virtual float get_cost_annually();

  virtual void set_amount_of_cargo(int amountCargo);
  virtual void set_cargo(string* cargo, int amount);
  void set_cost_annually(float costAnnually);
  
  
  //VIP
  virtual string get_VIP_type();
  virtual void set_VIP_type(string VIP_type);

  virtual int get_referrals();
  virtual void set_referrals(int referals);

  virtual void displayPrizes();
  virtual bool buy_prize(string prizeName);



// Manufacturing
virtual string get_certification();
virtual void add_certification(string certification);
virtual int get_cars_complete();
virtual void add_cars_complete(int cars_complete);

};


#endif