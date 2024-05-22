#include "Person.h"

//Initialisation
Person::Person() : age(0), phone_number(0), name("none"), address("none") {};
Person::Person(int age, int phone_number, std::string name, std::string address) : age(age), phone_number(phone_number), name(name), address(address) {};

//Getters
int Person::get_age() const {return age;};
int Person::get_phone() const {return phone_number;};
std::string Person::get_name() const {return name;};
std::string Person::get_address() const {return address;};

//Setters
void Person::set_age(int new_age) {age = new_age;};
void Person::set_phone(int new_phone) {phone_number = new_phone;};
void Person::set_name(std::string new_name) {name = new_name;};
void Person::set_address(std::string new_address) {address = new_address;};

//Operator
bool Person::operator==(const Person& other) const {
  return (age == other.age && phone_number == other.phone_number &&
          name == other.name && address == other.address);
}

// Virtual functions
// Software functions

void Person::set_position(std::string position) {(void)position;};
void Person::set_language(std::string languages) {(void)languages;};
void Person::set_finished(std::string finished) {(void)finished;};
void Person::set_projects_current(std::string currentProjects) {(void)currentProjects;};

std::string Person::get_position() { return ""; };
std::string Person::get_languages() { return ""; };
std::string Person::get_projects_current() { return ""; };
std::string Person::get_finished() { return ""; };


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

std::string Person::get_bank() {return "";};
void Person::set_bank(std::string BANK) {(void)BANK;};

std::string Person::get_purchase_history() {return "";};
void Person::set_purchase_history(std::string history){(void)history;};
void Person::set_spendings(int spendings) {(void)spendings;};
int Person::get_spendings() {return 0;};
int Person::get_clientId() {return 0;};
void Person::set_clientId(int clientId) {(void)clientId;};

std::string Person::get_notes() {return "none";};
void Person::set_notes(std::string new_note) {(void)new_note;};


//Design functions
std::string Person::get_design_current() {return "";};
void Person::set_design_current(std::string design_current) {(void)design_current;};

//Sales functions
float Person::get_conversion_rate() {return 0;};
void Person::set_conversion_rate(float con_rate) {(void)con_rate;};

int Person::get_cars_sold() {return 0;};
void Person::set_cars_sold(int sales) {(void)sales;};

float Person::get_revenue() {return 0;};
void Person::set_revenue(float rev) {(void)rev;};

//Research Development functions
//void Person::set_finished(std::string finished) {(void)finished;};

// std::string Person::get_finished() {return "";};
// void Person::set_finished(std::string finished) {};

std::string Person::get_research() {return "";};
void Person::set_research(std::string current) {(void)current;};

std::string Person::get_expertise() {return "";};
void Person::set_expertise(std::string expert) {(void)expert;};

//Marketing functions
float Person::get_success_rate() {return 0;};
void Person::set_success_rate(float success) {(void)success;};

//HumanResources
int Person::get_trained() {return 0;};
void Person::set_trained(int no_trained) {(void)no_trained;};

int Person::get_hired() {return 0;};
void Person::set_hired(int no_hired) {(void)no_hired;};

int Person::get_fired() {return 0;};
void Person::set_fired(int no_fired) {(void)no_fired;};

int Person::get_retired() {return 0;};
void Person::set_retired(int no_retired) {(void)no_retired;};

//Manufactoring
std::string Person::get_certification(){ return "";};
void Person::set_certification(std::string certification) {(void)certification;};
int Person::get_cars_complete(){return 0;};
void Person::set_cars_complete(int cars_complete) {(void)cars_complete;};

//VIP
std::string Person::get_VIP_type(){ return "";};
void Person::set_VIP_type(std::string VIP_type) {(void)VIP_type;};

int Person::get_referrals(){return 0;};
void Person::set_referrals(int referals){(void)referals;};

void Person::displayPrizes(){};
bool Person::buy_prize(std::string prizeName){(void)prizeName; return true;};

//Supplier
int Person::get_amount_of_cargo() {return 0;};
std::string Person::get_cargo() {return "";};
float Person::get_cost_annually() {return 0;};

void Person::set_amount_of_cargo(int amountCargo) {(void)amountCargo;};
void Person::set_cargo(std::string cargo) {(void)cargo;};
void Person::set_cost_annually(float costAnnually) {(void)costAnnually;};

//Employee functions
int Person::get_ID() {return 0;};
void Person::set_ID(int ID) {(void)ID;}

int Person::get_counter() {return 0;};
void Person::set_counter(int counter) {(void)counter;};

bool Person::get_attendance(int day) {(void)day; return true;};
void Person::set_attendance(bool attending, int day) {(void)attending; (void)day;};

int Person::get_performance() {return 0;};
void Person::set_performance(int performance) {(void)performance;};

std::string Person::get_date_joined() {return "";};
void Person::set_date_joined(std::string date_joined) {(void)date_joined;}

float Person::get_salary_hourly() {return 0;};
void Person::set_salary_hourly(float salary_hourly) {(void)salary_hourly;};

float Person::get_hours_weekly() {return 0;};
void Person::set_hours_weekly(float hours_weekly) {(void)hours_weekly;};

//Investor
float Person::get_amount_of_investment(){ return 0;};
void Person::set_amount_of_investment(float amount){(void)amount;};

//Manager
std::string Person::get_password() {return "";};
void Person::set_password(std::string pass) {(void)pass;};
