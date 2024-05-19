#include "Person.h"

#include <ctime>
#include <iostream>
using namespace std;

Person::Person() {
  age = 0, phone_number = 0, name = "name", address = "address";
};
Person::Person(int new_age, int new_phone, string new_name,
               string new_address) {
  age = new_age;
  phone_number = new_phone;
  name = new_name;
  address = new_address;
};

int Person::get_age() const { return age; };
void Person::set_age(int new_age) { age = new_age; };

int Person::get_phone() const { return phone_number; };
void Person::set_phone(int new_phone) { phone_number = new_phone; };

string Person::get_name() const { return name; };
void Person::set_name(string new_name) { name = new_name; };

string Person::get_address() const { return address; };
void Person::set_address(string new_address) { address = new_address; };

bool Person::operator==(const Person& other) const {
  return (age == other.age && phone_number == other.phone_number &&
          name == other.name && address == other.address);
}

// Virtual functions
// Software functions

void Person::set_position(string position) {(void)position;};
void Person::set_language(string languages) {(void)languages;};
void Person::set_finished(string finished) {(void)finished;};
void Person::set_projects_current(string currentProjects) {(void)currentProjects;};

string Person::get_position() { return ""; };
string Person::get_languages() { return ""; };
string Person::get_projects_current() { return ""; };
string Person::get_finished() { return ""; };


// Finances functions
void Person::check_turnover_profit(int turnoverMonth, int profitMonth){(void)turnoverMonth; (void)profitMonth;};
        
 
void Person::set_turnover(int turnoverMonth){(void)turnoverMonth;};
void Person::set_profit(int profitMonth){(void)profitMonth;};
void Person::set_budget(int Budget){(void)Budget;};
void Person::set_expense(int Expense){(void)Expense;};
 
 
int Person::get_turnover(){ return 0; };
int Person::get_profit(){ return 0; };
int Person::get_budget(){ return 0; };
int Person::get_expense(){ return 0; };



//Customer functions
int Person::get_bankAccount() {return 0;};
void Person::set_bankAccount(int bank_num) {(void)bank_num;};

string Person::get_bank() {return "";};
void Person::set_bank(string BANK) {(void)BANK;};

string Person::get_purchase_history() {return "";};
int Person::get_spendings() {return 0;};
int Person::get_clientId() {return 0;};

string Person::get_notes() {return "";};
void Person::set_notes(string new_note) {(void)new_note;};


//Design functions
string Person::get_design_current() {return "";};
void Person::set_design_current(string design_current) {(void)design_current;};

//Sales functions
float Person::get_conversion_rate() {return 0;};
void Person::set_conversion_rate(float con_rate) {(void)con_rate;};

int Person::get_cars_sold() {return 0;};
void Person::add_cars_sold(int sales) {(void)sales;};

float Person::get_revenue() {return 0;};
void Person::add_revenue(float rev) {(void)rev;};

//Research Development functions

// string Person::get_finished() {return "";};
// void Person::add_finished(string finished) {};

string Person::get_research() {return "";};
void Person::set_research(string current) {(void)current;};

string Person::get_expertise() {return "";};
void Person::add_expertise(string expert) {(void)expert;};

//Marketing functions
float Person::get_success_rate() {return 0;};
void Person::set_success_rate(float success) {(void)success;};

//HumanResources
int Person::get_trained() {return 0;};
void Person::add_trained(int trained) {(void)trained;};

int Person::get_hired() {return 0;};
void Person::add_hired(int hired) {(void)hired;};

int Person::get_fired() {return 0;};
void Person::add_fired(int fired) {(void)fired;};

int Person::get_retired() {return 0;};
void Person::add_retired(int retired) {(void)retired;};

//Manufactoring
string Person::get_certification(){ return "";};
void Person::add_certification(string certification) {(void)certification;};
int Person::get_cars_complete(){return 0;};
void Person::add_cars_complete(int cars_complete) {(void)cars_complete;};

//VIP
string Person::get_VIP_type(){ return "";};
void Person::set_VIP_type(string VIP_type) {(void)VIP_type;};

int Person::get_referrals(){return 0;};
void Person::set_referrals(int referals){(void)referals;};

void Person::displayPrizes(){};
bool Person::buy_prize(string prizeName){(void)prizeName; return true;};

//Supplier
int Person::get_amount_of_cargo() {return 0;};
string* Person::get_cargo() {string* cargo = new string[0]; return cargo;};
float Person::get_cost_annually() {return 0;};

void Person::set_amount_of_cargo(int amountCargo) {(void)amountCargo;};
void Person::set_cargo(string* cargo, int amount) {(void)cargo; (void)amount;};
void Person::set_cost_annually(float costAnnually) {(void)costAnnually;};

//Employee functions
int Person::get_ID() {return 0;};

bool Person::get_attendance(int day) {(void)day; return true;};
void Person::set_attendance(bool attending, int day) {(void)attending; (void)day;};

int Person::get_performance() {return 0;};
void Person::set_performance(int performance) {(void)performance;};

string Person::get_date_joined() {return "";};

float Person::get_salary_hourly() {return 0;};
void Person::set_salary_hourly(float salary_hourly) {(void)salary_hourly;};

float Person::get_hours_weekly() {return 0;};
void Person::set_hours_weekly(float hours_weekly) {(void)hours_weekly;};

//Investor
float Person::get_amount_of_investment(){ return 0;};
void Person::set_amount_of_investment(float amount){(void)amount;};

//Manager
string Person::get_password() {return "";};
void Person::set_password(string pass) {(void)pass;};
