#include <typeinfo>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>
#include <stdexcept>
#include <thread>
#include <chrono>
#include "Location.h"
#include "Customer.h"
#include "Design.h"
#include "Employee.h"
#include "Finances.h"
#include "HumanResources.h"
#include "Investor.h"
#include "Manager.h"
#include "Manufacturing.h"
#include "Marketing.h"
#include "Person.h"
#include "ResearchDev.h"
#include "Sales.h"
#include "Software.h"
#include "Supplier.h"
#include "VIP.h"


//Initialisation
Location::Location() {
    address = "none";
    people = new Person*[0];    //Creats an array with 0 size as people will be added with a function
    curr_size = 0;
};
Location::Location(std::string address) {
    this->address = address;
    people = new Person*[0];
    curr_size = 0;
};

// add person code using the person
bool Location::addPerson(Person* new_person) {
    Person** new_people = new Person*[curr_size + 1]; // Creates a new array of size one larger than the old one
    for (int i = 0; i < curr_size; i++) {new_people[i] = people[i];} // Copies the old array to the new array
    new_people[curr_size] = new_person; // Creates the new person at the end of the array
    curr_size++; // Increments curr_size for next time

    delete[] people; // Deletes the old array so there isnt a memory leak
    people = new_people; // Makes the old pointer now point to the new array
    return true;       
}

// remove person code using the name of the person (can be easily changed to other traits)
bool Location::rmPerson(const std::string& name) {

    int index = -1; // Sets index at -1 to setup for the no found clause
    for (int i = 0; i < curr_size; i ++){ // Searches all the people for a matching name
        if (people[i]->get_name() == name){
            index = i;
            break;
        }
    }

    if (index == -1) {return false;} // Clause for if no name found

    for (int i = index; i < curr_size - 1; i++){ // Shifts the array so that there are no holes where the removed employee is
        people[i] = people[i + 1];
    }
    curr_size--; // Updates the size

    // Code to remove the extra size of the dynamic array
    Person** new_people = new Person*[curr_size]; // Creates a new array of correct size
    for (int i = 0; i < curr_size; i++){ // Copies the old array to the new array
        new_people[i] = people[i];
    }

    delete[] people; // Deletes the old array so there isnt a memory leak

    people = new_people; // Makes the old pointer now point to the new array
    
    return true;
}


// Getters
std::string Location::get_address() {return address;};
int Location::get_curr_size() {return curr_size;};

//Setters
void Location::set_address(std::string address) {this->address = address;};

//Deconstructor
Location::~Location() {delete[] people;}


//Functions

// Password checking function
bool Location::Access(std::string username, std::string password){
    int index = -1;                                                 // Sets index at -1 to setup for the no found clause
    for (int i = 0; i < curr_size; i ++){           // Searches all the names in location to find the index
        if (people[i]->get_name() == username){
            index = i;
            break;
        }
    }

    if (username == "admin" && password == "admin"){
        return true;
    }

    if (index == -1){                                               // Clause for if no name found
        std::cout << "Username incorrect." << std::endl;
        return false;
    }

    if (people[index]->get_password() == password){       // Checking if the password matches

        if (strcmp(typeid(*people[index]).name(), "7Manager") == 0){ // In GCC compiling this works as typeid will show 7 representing the characters in the class then the class name
            //std::cout << "Access granted." << std::endl;
            return true;
        }
    }

    //std::cout << "Username or password is incorrect. " << std::endl; // If no other check it hit then the username must not match the password
    return false;

}

//Since we only have c++11 we need to create the fileexists function
bool Location::fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

//Splits the string into 3 parts to setup for file reading
std::vector<std::string> Location::splitString(const std::string& input) {
    std::vector<std::string> parts;
    std::istringstream iss(input);
    std::string part;

    // Extract the first part
    if (std::getline(iss, part, ' ')) {
        parts.push_back(part);
    } else {
        parts.push_back("");
    }

    // Extract the second part
    if (std::getline(iss, part, ' ')) {
        parts.push_back(part);
    } else {
        parts.push_back("");
    }

    // Extract the rest of the input as the third part
    if (std::getline(iss, part)) {
        parts.push_back(part);
    } else {
        parts.push_back("");
    }

    return parts;
}

//Converts a string to an integer and handles invalid inputs
int Location::toInt(std::string input) {
    bool valid = true;
    for (char c : input) {
        if (!isdigit(c)) {
            valid = false;
            break;
        }
    }
    if (valid) {return std::stoi(input);} else {return 0;}
}

//Converts a string to a float and handles invalid inputs
float Location::toFloat(const std::string& input) {
    bool valid = true;
    bool decimalPointFound = false;

    for (char c : input) {
        if (c == '.') {
            if (decimalPointFound) {
                valid = false;
                break;
            }
            decimalPointFound = true;
        } else if (!std::isdigit(c)) {
            valid = false;
            break;
        }
    }

    if (valid && !input.empty() && input != ".") {
        try {
            return std::stof(input); // Convert valid string to float
        } catch (const std::invalid_argument& e) {
            return 0.0f; // In case of invalid argument exception
        } catch (const std::out_of_range& e) {
            return 0.0f; // In case of out of range exception
        }
    } else {
        return 0.0f; // Return 0.0 for invalid input
    }
}

//This function will interprate a string and use it 
void Location::runCommand(std::string command) {
    std::vector<std::string> parts = splitString(command);
    if (command == "save"){
        std::string fileName;
        std::cout << "Enter the name of your save file (make sure to include .txt): ";
        std::cin >> fileName;
        Save(fileName);
    
    } else if (command == "help"){
        std::cout << "\nThere are 6 types of commands; get, set, rm, add, e and save.\n\n";
        std::cout << "save - save your progress so you can load it later.\n\n";
        std::cout << "get info: name - is the main command to get all the information based on the input name.\n";
        std::cout << "get names - is the command to list all of the avaliable names.\n\n";
        std::cout << "set: variable: name - is the base command for setting data for a variable based on someone's name.\n";
        std::cout << "variable: age, phonenumber, address, id, hourlysalary, weeklyhours, attendance, datejoined, performance,\n" 
        "position, banknumber, bank, spendings, purchasehistory, notes, finisheddesigns, currentdesigns, turnover, profit,\n"
        "budget, expense, trained, hired, fired, retired, investment, password, certification, carscomplete, success,\n" 
        "finishedresearch, currentresearch, expertise, conversion, sold, revenue, languages, finishedprojects, currentprojects,\n" 
        "cargoamount, annualcost, cargo, referrals\n\n";
        std::cout << "rm: name - is the command used to remove a person based on their name.\n\n";
        std::cout << "add: class: name - is the command to add a class with a new person name.\n";
        std::cout << "class: Customer, Design, Finances, HumanResources, Investor, Manager, Manufacturing, ResearchDev, Sales,\n"
        "Software, Supplier, VIP\n\n";
        std::cout << "save - is the function to save your data into a file which can be loaded back in.\n\n";
        std::cout << "e - is the function to exit, note you should save before exiting.\n\n";
    
    } else if (parts[0] == "get"){
        if (parts[1] == "names"){
            std::cout << "Names: \n\n";
            for (int i = 0; i < curr_size; i++){
                std::cout << people[i]->get_name() << " - " << typeid(*people[i]).name() << std::endl;
            }
        }
        if (parts[1] == "info"){
            std::string role;
            int index; 
            for (int i = 0; i < curr_size; i++){
                if (people[i]->get_name() == parts[2]){
                    index = i;
                    role = typeid(*people[i]).name();
                }
            }
            if (role == "8Customer") { /////////////////////////////////////////////////////////////
                std::cout << "Customer " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "Bank number: " << people[index]->get_bankAccount() << std::endl;
                std::cout << "Bank: " << people[index]->get_bank() << std::endl;
                std::cout << "Client ID: " << people[index]->get_clientId() << std::endl;
                std::cout << "Spendings: " << people[index]->get_spendings() << std::endl;
                std::cout << "Purchas History: " << people[index]->get_purchase_history() << std::endl;
                std::cout << "Notes: " << people[index]->get_notes() << std::endl;

            } else if (role == "6Design") {/////////////////////////////////////////////////////////////
                std::cout << "Designer " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "ID: " << people[index]->get_ID() << std::endl;
                std::cout << "Hourly Salary: " << people[index]->get_salary_hourly() << std::endl;
                std::cout << "Weekly Hours: " << people[index]->get_hours_weekly() << std::endl;
                for (int j = 0; j < 7; j++){
                    if (people[index]->get_attendance(j)){
                        std::cout << "Day " << j + 1 << " : True\n"; 
                    } else {std::cout << "Day " << j + 1 << " : False\n";}
                }
                std::cout << "Date Joined: " << people[index]->get_date_joined() << std::endl;
                std::cout << "Performance out of 10: " << people[index]->get_performance() << std::endl;
                
                std::cout << "Position: " << people[index]->get_position() << std::endl;
                std::cout << "Finished Designs: " << people[index]->get_finished() << std::endl;
                std::cout << "Current Designs: " << people[index]->get_design_current() << std::endl;
                
            } else if (role == "8Finances"){/////////////////////////////////////////////////////////////
                std::cout << "Finances " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                 std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "ID: " << people[index]->get_ID() << std::endl;
                std::cout << "Hourly Salary: " << people[index]->get_salary_hourly() << std::endl;
                std::cout << "Weekly Hours: " << people[index]->get_hours_weekly() << std::endl;
                for (int j = 0; j < 7; j++){
                    if (people[index]->get_attendance(j)){
                        std::cout << "Day " << j + 1 << " : True\n"; 
                    } else {std::cout << "Day " << j + 1 << " : False\n";}
                }
                std::cout << "Date Joined: " << people[index]->get_date_joined() << std::endl;
                std::cout << "Performance out of 10: " << people[index]->get_performance() << std::endl;
                
                std::cout << "Position: " << people[index]->get_position() << std::endl;
                std::cout << "Turnover: " << people[index]->get_turnover() << std::endl;
                std::cout << "Profit: " << people[index]->get_profit() << std::endl;
                std::cout << "Budget: " << people[index]->get_budget() << std::endl;
                std::cout << "Expense: " << people[index]->get_expense() << std::endl;
                
            } else if (role == "14HumanResources"){/////////////////////////////////////////////////////////////
                std::cout << "HumanResources " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "ID: " << people[index]->get_ID() << std::endl;
                std::cout << "Hourly Salary: " << people[index]->get_salary_hourly() << std::endl;
                std::cout << "Weekly Hours: " << people[index]->get_hours_weekly() << std::endl;
                for (int j = 0; j < 7; j++){
                    if (people[index]->get_attendance(j)){
                        std::cout << "Day " << j + 1 << " : True\n"; 
                    } else {std::cout << "Day " << j + 1 << " : False\n";}
                }
                std::cout << "Date Joined: " << people[index]->get_date_joined() << std::endl;
                std::cout << "Performance out of 10: " << people[index]->get_performance() << std::endl;
                
                std::cout << "Position: " << people[index]->get_position() << std::endl;  
                std::cout << "Amount of trained people: " << people[index]->get_trained() << std::endl; 
                std::cout << "Amount of hired: " << people[index]->get_hired() << std::endl; 
                std::cout << "Amount of fired: " << people[index]->get_fired() << std::endl;  
                std::cout << "Amount of retired: " << people[index]->get_retired() << std::endl;
                                                             
            } else if (role == "8Investor"){/////////////////////////////////////////////////////////////
                std::cout << "Investor " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "amount of investment: " << people[index]->get_amount_of_investment() << std::endl;

            } else if (role == "7Manager"){/////////////////////////////////////////////////////////////   
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "Hourly Salary: " << people[index]->get_salary_hourly() << std::endl;
                std::cout << "Weekly Hours: " << people[index]->get_hours_weekly() << std::endl;
                std::cout << "ID: " << people[index]->get_ID() << std::endl;
                for (int j = 0; j < 7; j++){
                    if (people[index]->get_attendance(j)){
                        std::cout << "Day " << j + 1 << " : True\n"; 
                    } else {std::cout << "Day " << j + 1 << " : False\n";}
                }
                std::cout << "Date Joined: " << people[index]->get_date_joined() << std::endl;
                std::cout << "Performance out of 10: " << people[index]->get_performance() << std::endl;
                
                std::cout << "Position: " << people[index]->get_position() << std::endl;  
                std::cout << "Password: " << people[index]->get_password() << std::endl;              
            } else if (role == "13Manufacturing"){/////////////////////////////////////////////////////////////
                std::cout << "Manufacturing " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                 std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "ID: " << people[index]->get_ID() << std::endl;
                std::cout << "Hourly Salary: " << people[index]->get_salary_hourly() << std::endl;
                std::cout << "Weekly Hours: " << people[index]->get_hours_weekly() << std::endl;
                for (int j = 0; j < 7; j++){
                    if (people[index]->get_attendance(j)){
                        std::cout << "Day " << j + 1 << " : True\n"; 
                    } else {std::cout << "Day " << j + 1 << " : False\n";}
                }
                std::cout << "Date Joined: " << people[index]->get_date_joined() << std::endl;
                std::cout << "Performance out of 10: " << people[index]->get_performance() << std::endl;
                
                std::cout << "Position: " << people[index]->get_position() << std::endl; 
                std::cout << "Certification : " << people[index]->get_certification() << std::endl;  
                std::cout << "Cars_complete : " << people[index]->get_cars_complete() << std::endl; 
                  
            } else if (role == "9Marketing"){/////////////////////////////////////////////////////////////       
                std::cout << "Marketing " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                 std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "ID: " << people[index]->get_ID() << std::endl;
                std::cout << "Hourly Salary: " << people[index]->get_salary_hourly() << std::endl;
                std::cout << "Weekly Hours: " << people[index]->get_hours_weekly() << std::endl;
                for (int j = 0; j < 7; j++){
                    if (people[index]->get_attendance(j)){
                        std::cout << "Day " << j + 1 << " : True\n"; 
                    } else {std::cout << "Day " << j + 1 << " : False\n";}
                }
                std::cout << "Date Joined: " << people[index]->get_date_joined() << std::endl;
                std::cout << "Performance out of 10: " << people[index]->get_performance() << std::endl;
                
                std::cout << "Position: " << people[index]->get_position() << std::endl; 
                std::cout << "Success rate: " << people[index]->get_success_rate() << std::endl; 
                
            } else if (role == "11ResearchDev"){/////////////////////////////////////////////////////////////
                std::cout << "ResearchDev " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                 std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "ID: " << people[index]->get_ID() << std::endl;
                std::cout << "Hourly Salary: " << people[index]->get_salary_hourly() << std::endl;
                std::cout << "Weekly Hours: " << people[index]->get_hours_weekly() << std::endl;
                for (int j = 0; j < 7; j++){
                    if (people[index]->get_attendance(j)){
                        std::cout << "Day " << j + 1 << " : True\n"; 
                    } else {std::cout << "Day " << j + 1 << " : False\n";}
                }
                std::cout << "Date Joined: " << people[index]->get_date_joined() << std::endl;
                std::cout << "Performance out of 10: " << people[index]->get_performance() << std::endl;
                
                std::cout << "Position: " << people[index]->get_position() << std::endl; 
                std::cout << "Finished researches: " << people[index]->get_finished() << std::endl; 
                std::cout << "Current research: " << people[index]->get_research() << std::endl; 
                std::cout << "Expertise: " << people[index]->get_expertise() << std::endl; 
                
            } else if (role == "5Sales"){/////////////////////////////////////////////////////////////      
                std::cout << "Sales " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                 std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "ID: " << people[index]->get_ID() << std::endl;
                std::cout << "Hourly Salary: " << people[index]->get_salary_hourly() << std::endl;
                std::cout << "Weekly Hours: " << people[index]->get_hours_weekly() << std::endl;
                for (int j = 0; j < 7; j++){
                    if (people[index]->get_attendance(j)){
                        std::cout << "Day " << j + 1 << " : True\n"; 
                    } else {std::cout << "Day " << j + 1 << " : False\n";}
                }
                std::cout << "Date Joined: " << people[index]->get_date_joined() << std::endl;
                std::cout << "Performance out of 10: " << people[index]->get_performance() << std::endl;
                
                std::cout << "Position: " << people[index]->get_position() << std::endl; 
                 std::cout << "Conversion rate: " << people[index]->get_conversion_rate() << std::endl; 
                  std::cout << "Sold cars: " << people[index]->get_cars_complete() << std::endl; 
                   std::cout << "Revenue: " << people[index]->get_revenue() << std::endl; 
                   
            } else if (role == "8Software"){////////////////////////////////////////////////////////////
                std::cout << "Software " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                 std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "ID: " << people[index]->get_ID() << std::endl;
                std::cout << "Hourly Salary: " << people[index]->get_salary_hourly() << std::endl;
                std::cout << "Weekly Hours: " << people[index]->get_hours_weekly() << std::endl;
                for (int j = 0; j < 7; j++){
                    if (people[index]->get_attendance(j)){
                        std::cout << "Day " << j + 1 << " : True\n"; 
                    } else {std::cout << "Day " << j + 1 << " : False\n";}
                }
                std::cout << "Date Joined: " << people[index]->get_date_joined() << std::endl;
                std::cout << "Performance out of 10: " << people[index]->get_performance() << std::endl;
                
                std::cout << "Position: " << people[index]->get_position() << std::endl; 
                std::cout << "Languages: " << people[index]->get_languages() << std::endl;
                std::cout << "current projects: " << people[index]->get_projects_current() << std::endl;
                std::cout << "Finished projects: " << people[index]->get_finished() << std::endl;

            } else if (role == "8Supplier"){/////////////////////////////////////////////////////////////
                std::cout << "Supplier " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                 std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "Amount of cargo: " << people[index]->get_amount_of_cargo() << std::endl;
                std::cout << "Annually cost: " << people[index]->get_cost_annually() << std::endl;
                std::cout << "Cargo: " << people[index]->get_cargo() << std::endl;

            } else if (role == "3VIP"){/////////////////////////////////////////////////////////////
                std::cout << "VIP " << parts[2] << " has information: \n\n";
                std::cout << "Age: " << people[index]->get_age() << std::endl;
                std::cout << "Phone number: " << people[index]->get_phone() << std::endl;
                std::cout << "Name: " << people[index]->get_name() << std::endl;
                std::cout << "Address: " << people[index]->get_address() << std::endl;
                std::cout << "Bank number: " << people[index]->get_bankAccount() << std::endl;
                std::cout << "Bank: " << people[index]->get_bank() << std::endl;
                std::cout << "Client ID: " << people[index]->get_clientId() << std::endl;
                std::cout << "Spendings: " << people[index]->get_spendings() << std::endl;
                std::cout << "Purchas History: " << people[index]->get_purchase_history() << std::endl;
                std::cout << "Notes: " << people[index]->get_notes() << std::endl;
                std::cout << "Referrals: " << people[index]->get_referrals() << std::endl;
            }
        }

    } else if (parts[0] == "set"){
        int index; 
        for (int i = 0; i < get_curr_size(); i++){
            if (people[i]->get_name() == parts[2]){
                index = i;
            }
        }
        if (parts[1] == "age"){
            int age;
            std::string input;
            std::cout << "Enter the age: ";
            std::cin >> input;
            try {
                age = std::stoi(input); // Convert input to an integer
                people[index]->set_age(age);
                std::cout << "Age was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Age set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Age set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "phonenumber"){
            int phoneNumber;
            std::string input;
            std::cout << "Enter phone number: ";
            std::cin >> input;
            try {
                phoneNumber = std::stoi(input);
                people[index]->set_phone(phoneNumber);
                std::cout << "Phone was number set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Age set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Age set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "address"){
            std::string address;
            std::cout << "Enter address: ";
            std::getline(std::cin, address);
            people[index]->set_address(address);
            std::cout << "address was set successfully.\n";
        }
        if (parts[1] == "id") {
            int ID;
            std::string input;
            std::cout << "Enter ID: ";
            std::cin >> input;
            try {
                ID = std::stoi(input);
                people[index]->set_ID(ID);
                std::cout << "ID was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! ID set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! ID set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "hourlysalary") {
            float hourlySalary;
            std::string input;
            std::cout << "Enter Hourly Salary: ";
            std::cin >> input;
            try {
                hourlySalary = std::stof(input);
                people[index]->set_salary_hourly(hourlySalary);
                std::cout << "Hourly Salary was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Hourly Salary set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Hourly Salary set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "weeklyhours") {
            float weeklyHours;
            std::string input;
            std::cout << "Enter Weekly Hours: ";
            std::cin >> input;
            try {
                weeklyHours = std::stof(input);
                people[index]->set_hours_weekly(weeklyHours);
                std::cout << "Weekly Hours was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Weekly Hours set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Weekly Hours set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "attendance"){
            int day;
            int attendance;
            std::cout << "Enter day (Monday = 1 to Sunday = 7): ";
            std::cin >> day;
            if (day < 1 || day > 7) {
                std::cout << "Next time enter a proper number between 1 to 7 (Monday = 1 to Sunday = 7): ";
                return;
            }
            std::cout << "Did employee attend that day? (yes = 1/no = 0): ";
            std::cin >> attendance;
            if (attendance != 1 && attendance != 0) {
                std::cout << "Next time enter a proper attendance response (yes = 1/no = 0): ";
                return;
            }
            day = day - 1;
            people[index]->set_attendance(attendance, day);
            std::cout << "Attendance was set successfully.\n";
        }
        if (parts[1] == "datejoined"){
            std::string dj;
            std::cout << "Enter Date Joined: ";
            std::getline(std::cin, dj);
            people[index]->set_date_joined(dj);
            std::cout << "Date joined was set successfully.\n";
        }
        if (parts[1] == "performance") {
            int performance;
            std::cout << "Enter employee Performance out of 10: ";
            std::cin >> performance;
            
            if (performance > 0 && performance <= 10) {
                people[index]->set_performance(performance);
                std::cout << "Performance was set successfully.\n";
            } else {
                std::cout << "Performance set failed! Enter a value between 1 and 10.\n";
            }
        }
        if (parts[1] == "position"){
            std::string position;
            std::cout << "Enter the employee's position: ";
            std::getline(std::cin, position);
            people[index]->set_position(position);
            std::cout << "Position was set successfully.\n";
        }
        if (parts[1] == "banknumber") {
            int bankNumber;
            std::string input;
            std::cout << "Enter Customer's bank number: ";
            std::cin >> input;
            try {
                bankNumber = std::stoi(input);
                people[index]->set_bankAccount(bankNumber);
                std::cout << "Customer's bank number was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Customer's bank number set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Customer's bank number set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "bank"){
            std::string bank;
            std::cout << "Enter the customer's bank: ";
            std::getline(std::cin, bank);
            people[index]->set_bank(bank);
            std::cout << "Customer's bank was set successfully.\n";
        }
        // std::cout << "Client ID: " << people[index]->get_clientId() << std::endl;
        if (parts[1] == "spendings") {
            int spendings;
            std::string input;
            std::cout << "Enter Customer's spendings: ";
            std::cin >> input;
            try {
                spendings = std::stoi(input);
                people[index]->set_spendings(spendings);
                std::cout << "Customer's spendings was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Customer's spendings set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Customer's spendings set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "purchasehistory"){
            std::string p_history;
            std::cout << "Enter the Purchase History: ";
            std::getline(std::cin, p_history);
            people[index]->set_purchase_history(p_history);
            std::cout << "Purchase History was set successfully.\n";
        }
        if (parts[1] == "notes"){
            std::string notes;
            std::cout << "Enter the notes about customer: ";
            std::getline(std::cin, notes);
            people[index]->set_notes(notes);
            std::cout << "Customer Notes was set successfully.\n";
        }
        if (parts[1] == "finisheddesigns"){
            std::string fin_des;
            std::cout << "Enter the Finished Designs: ";
            std::getline(std::cin, fin_des);
            people[index]->set_finished(fin_des);
            std::cout << "Finished Designs was set successfully.\n";
        }
        if (parts[1] == "currentdesigns"){
            std::string cur_des;
            std::cout << "Enter the Current Designs: ";
            std::getline(std::cin, cur_des);
            people[index]->set_design_current(cur_des);
            std::cout << "Current Designs was set successfully.\n";
        }
        if (parts[1] == "turnover") {
            int Turnover;
            std::string input;
            std::cout << "Enter Turnover: ";
            std::cin >> input;
            try {
                Turnover = std::stoi(input);
                people[index]->set_turnover(Turnover);
                std::cout << "Turnover was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Turnover set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Turnover set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "profit") {
            int Profit;
            std::string input;
            std::cout << "Enter Profit: ";
            std::cin >> input;
            try {
                Profit = std::stoi(input);
                people[index]->set_profit(Profit);
                std::cout << "Profit was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Profit set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Profit set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "budget") {
            int Budget;
            std::string input;
            std::cout << "Enter Budget: ";
            std::cin >> input;
            try {
                Budget = std::stoi(input);
                people[index]->set_budget(Budget);
                std::cout << "Budget was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Profit set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Profit set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "expense") {
            int Expense;
            std::string input;
            std::cout << "Enter expenses: ";
            std::cin >> input;
            try {
                Expense = std::stoi(input);
                people[index]->set_expense(Expense);
                std::cout << "Expenses was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Expenses set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Expenses set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "trained") {
            int trained;
            std::string input;
            std::cout << "Enter number of trained employees: ";
            std::cin >> input;
            try {
                trained = std::stoi(input);
                people[index]->set_trained(trained);
                std::cout << "Number of trained employees was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Number of trained employees set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range!  Number of trained employees set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "hired") {
            int hired;
            std::string input;
            std::cout << "Enter number of trained employees: ";
            std::cin >> input;
            try {
                hired = std::stoi(input);
                people[index]->set_hired(hired);
                std::cout << "Number of hired employees was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Number of hired employees set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Number of hired employees set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "fired") {
            int fired;
            std::string input;
            std::cout << "Enter number of trained employees: ";
            std::cin >> input;
            try {
                fired = std::stoi(input);
                people[index]->set_fired(fired);
                std::cout << "Number of fired employees was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Number of fired employees set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Number of fired employees set failed. " << e.what() << std::endl;
            }
        } 
        if (parts[1] == "retired") {
            int retired;
            std::string input;
            std::cout << "Enter number of retired employees: ";
            std::cin >> input;
            try {
                retired = std::stoi(input);
                people[index]->set_retired(retired);
                std::cout << "Number of retired employees was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Number of retired employees set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Number of retired employees set failed. " << e.what() << std::endl;
            }
        }  
        if (parts[1] == "investment") {
            float investment;
            std::string input;
            std::cout << "Enter investment amount: ";
            std::cin >> input;
            try {
                investment = std::stof(input);
                people[index]->set_amount_of_investment(investment);
                std::cout << "Investment was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Investment set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Investment set failed. " << e.what() << std::endl;
            }
        }  
        if (parts[1] == "password"){
            std::string Password;
            std::string check;
            std::cout << "Enter the password: ";
            std::cin >> Password;
            std::cout << "Enter password again: ";
            std::cin >> check;
            if (check != Password){
                std::cout << "Password entered didn't match.\n";
                return;
            }
            people[index]->set_password(Password);
            std::cout << "Password was set successfully.\n";
        }
        if (parts[1] == "certification"){
            std::string Certification;
            std::cout << "Enter the Employee's certification: ";
            std::getline(std::cin, Certification);
            people[index]->set_certification(Certification);
            std::cout << "Certification was set successfully.\n";
        }
        if (parts[1] == "carscomplete") {
            int complete;
            std::string input;
            std::cout << "Enter number of cars completed: ";
            std::cin >> input;
            try {
                complete = std::stoi(input);
                people[index]->set_cars_complete(complete);
                std::cout << "Number of cars completed was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Number of cars completed set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Number of cars completed set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "success") {
            float success;
            std::string input;
            std::cout << "Enter the Employee's success rate: ";
            std::cin >> input;
            try {
                success = std::stof(input);
                people[index]->set_success_rate(success);
                std::cout << "Success rate was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Success rate set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Success rate set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "finishedresearch"){
            std::string fin_res;
            std::cout << "Enter Finished research: ";
            std::getline(std::cin, fin_res);
            people[index]->set_finished(fin_res);
            std::cout << "Finished research was set successfully.\n";
        }
        if (parts[1] == "currentresearch"){
            std::string cur_res;
            std::cout << "Enter Employee's current research: ";
            std::getline(std::cin, cur_res);
            people[index]->set_research(cur_res);
            std::cout << "Current research was set successfully.\n";
        }
        if (parts[1] == "expertise"){
            std::string Expertise;
            std::cout << "Enter the Employee's expertise: ";
            std::getline(std::cin, Expertise);
            people[index]->set_expertise(Expertise);
            std::cout << "Expertise was set successfully.\n";
        }
        if (parts[1] == "conversion") {
            float Conversion;
            std::string input;
            std::cout << "Enter the Conversion rate: ";
            std::cin >> input;
            try {
                Conversion = std::stof(input);
                people[index]->set_conversion_rate(Conversion);
                std::cout << "Conversion rate was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Conversion rate set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Conversion rate set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "sold") {
            int sold_cars;
            std::string input;
            std::cout << "Enter the number of cars sold: ";
            std::cin >> input;
            try {
                sold_cars = std::stoi(input);
                people[index]->set_cars_sold(sold_cars);
                std::cout << "Number of cars sold was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Number of cars sold set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Number of cars sold set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "revenue") {
            float Revenue;
            std::string input;
            std::cout << "Enter Revenue: ";
            std::cin >> input;
            try {
                Revenue = std::stof(input);
                people[index]->set_revenue(Revenue);
                std::cout << "Revenue was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Revenue set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Revenue set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "languages"){
            std::string languages;
            std::cout << "Enter the Employee's languages: ";
            std::getline(std::cin, languages);
            people[index]->set_language(languages);
            std::cout << "Languages was set successfully.\n";
        }
        if (parts[1] == "finishedprojects"){
            std::string fin_proj;
            std::cout << "Enter the Employee's Finished projects: ";
            std::getline(std::cin, fin_proj);
            people[index]->set_finished(fin_proj);
            std::cout << "Finished projects was set successfully.\n";
        }
        if (parts[1] == "currentprojects"){
            std::string cur_proj;
            std::cout << "Enter the Employee's Current projects: ";
            std::getline(std::cin, cur_proj);
            people[index]->set_projects_current(cur_proj);
            std::cout << "Current projects was set successfully.\n";
        }
        if (parts[1] == "cargoamount") {
            int amount_cargo;
            std::string input;
            std::cout << "Enter Amount of cargo: ";
            std::cin >> input;
            try {
                amount_cargo = std::stof(input);
                people[index]->set_amount_of_cargo(amount_cargo);
                std::cout << "Amount of cargo was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Amount of cargo set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Amount of cargo set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "annualcost") {
            float Annual_cost;
            std::string input;
            std::cout << "Enter Revenue: ";
            std::cin >> input;
            try {
                Annual_cost = std::stof(input);
                people[index]->set_cost_annually(Annual_cost);
                std::cout << "Annual cost was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Annual cost set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Annual cost set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "cargo"){
            std::string cargo;
            std::cout << "Enter the cargo name: ";
            std::getline(std::cin, cargo);
            people[index]->set_cargo(cargo);
            std::cout << "Cargo name(s) was set successfully.\n";
        }
        if (parts[1] == "referrals") {
            int referrals;
            std::string input;
            std::cout << "Enter Amount of cargo: ";
            std::cin >> input;
            try {
                referrals = std::stof(input);
                people[index]->set_referrals(referrals);
                std::cout << "Amount of Referrals was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Amount of Referrals set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Amount of Referrals set failed. " << e.what() << std::endl;
            }
        }
        if (parts[1] == "name") {
            std::string name;
            std::cout << "Enter the name: ";
            std::getline(std::cin, name);
            try {
                people[index]->set_name(name);
                std::cout << "Name was set successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input! Name set failed. " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Input out of range! Name set failed. " << e.what() << std::endl;
            }
        }

    } else if (parts[0] == "rm"){
        std::string name = parts[1] + " " + parts[2];
        if(rmPerson(name)){
            std::cout << name << " was successfully removed.\n";
        } else {std::cout << name << " was not removed, please check your spelling.\n";}

    } else if (parts[0] == "add"){
        for (int i = 0; i < get_curr_size(); i++){
            if (parts[2] == people[i]->get_name()){
                std::cout << "A person with this name already exists in your data base, please rename the person or remove the existing person.\n";
                return;
            }
        }
        if (parts[1] == "Customer"){
            std::string input;
            int age;
            int phone;
            std::string name;
            std::string address;
            int bank_number;
            int spendings;
            int clientId;
            std::string bank;
            std::string purchase_history;
            std::string notes;
            
            std::cout << "Please enter Customer age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter Customer phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            // std::cout << "Please enter Customer name: ";
            // std::getline(std::cin, name);
            // if (name.empty()) {name = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter Customer address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}
      
            std::cout << "Please enter Customer bank number: ";
            std::cin >> input;
            bank_number = toInt(input);

            std::cout << "Please enter Customer spendings: ";
            std::cin >> input;
            spendings = toInt(input);

            std::cout << "Please enter Customer client ID: ";
            std::cin >> input;
            clientId = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter Customer bank: ";
            std::getline(std::cin, bank);
            if (bank.empty()) {bank = "none";}

            std::cout << "Please enter Customer purchase history: ";
            std::getline(std::cin, purchase_history);
            if (purchase_history.empty()) { purchase_history = "none"; }

            std::cout << "Please enter Customer notes: ";
            std::getline(std::cin, notes);
            if (notes.empty()) {notes = "none";}

            Customer *customer = new Customer(bank_number, spendings, clientId, bank, purchase_history, notes, age, phone, name, address);

            addPerson(customer);

        } else if (parts[1] == "Design"){
            std::string input;
            float salary_hourly;
            float hours_weekly;
            std::string date_joined;
            int age;
            int phone;
            std::string name;
            std::string address;
            std::string position;
            std::string design_finished;
            std::string design_current;
            
            std::cout << "Please enter Design salary hourly: ";
            std::cin >> input;
            salary_hourly = toFloat(input);

            std::cout << "Please enter Design hours weekly: ";
            std::cin >> input;
            hours_weekly = toFloat(input);

            std::cout << "Please enter Design age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter Design phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter Design joined date: ";
            std::getline(std::cin, date_joined);
            if (date_joined.empty()) {date_joined = "none";}

            std::cout << "Please enter Design address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter Design position: ";
            std::getline(std::cin, position);
            if (position.empty()) {position = "none";}

            std::cout << "Please enter Design finished designs: ";
            std::getline(std::cin, design_finished);
            if (design_finished.empty()) {design_finished = "none";}

            std::cout << "Please enter Design current design: ";
            std::getline(std::cin, design_current);
            if (design_current.empty()) {design_current = "none";}

            Design *design = new Design(salary_hourly, hours_weekly, date_joined, age, phone, name, address, position, design_finished, design_current);
            addPerson(design);
            
        } else if (parts[1] == "Finances"){
            std::string input;
            float salary_hourly;
            float hours_weekly;
            std::string date_joined;
            int age;
            int phone;
            std::string name;
            std::string address;
            std::string position;
            int turnover_monthly;
            int profit_monthly;
            int budget;
            int expense;

            std::cout << "Please enter Finances salary hourly: ";
            std::cin >> input;
            salary_hourly = toFloat(input);

            std::cout << "Please enter Finances hours weekly: ";
            std::cin >> input;
            hours_weekly = toFloat(input);

            std::cout << "Please enter Finances age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter Finances phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cout << "Please enter Finances monthly turnover: ";
            std::cin >> input;
            turnover_monthly = toInt(input);

            std::cout << "Please enter Finances monthly profit: ";
            std::cin >> input;
            profit_monthly = toInt(input);

            std::cout << "Please enter Finances budget: ";
            std::cin >> input;
            budget = toInt(input);

            std::cout << "Please enter Finances expense: ";
            std::cin >> input;
            expense = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter Finances joined date: ";
            std::getline(std::cin, date_joined);
            if (date_joined.empty()) {date_joined = "none";}
            
            std::cout << "Please enter Finances address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter Finances position: ";
            std::getline(std::cin, position);
            if (position.empty()) {position = "none";}

            Finances *finances = new Finances(salary_hourly, hours_weekly, date_joined, age, phone, name, address, position, turnover_monthly, profit_monthly, budget, expense);
            addPerson(finances);
            
        } else if (parts[1] == "HumanResources"){
            std::string input;
            float salary_hourly;
            float hours_weekly;
            std::string date_joined;
            int age;
            int phone;
            std::string name;
            std::string address;
            std::string position;
            int no_trained;
            int no_hired;
            int no_fired;
            int no_retired;
            
            std::cout << "Please enter HumanResources salary hourly: ";
            std::cin >> input;
            salary_hourly = toFloat(input);

            std::cout << "Please enter HumanResources hours weekly: ";
            std::cin >> input;
            hours_weekly = toFloat(input);

            std::cout << "Please enter HumanResources age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter HumanResources phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter HumanResources joined date: ";
            std::getline(std::cin, date_joined);
            if (date_joined.empty()) {date_joined = "none";}
            
            std::cout << "Please enter HumanResources address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter HumanResources position: ";
            std::getline(std::cin, position);
            if (position.empty()) {position = "none";}

            std::cout << "Please enter HumanResources number of trained: ";
            std::cin >> input;
            no_trained = toInt(input);

            std::cout << "Please enter HumanResources number of hired: ";
            std::cin >> input;
            no_hired = toInt(input);

            std::cout << "Please enter HumanResources number of fired: ";
            std::cin >> input;
            no_fired = toInt(input);

            std::cout << "Please enter HumanResources number of retired: ";
            std::cin >> input;
            no_retired = toInt(input);

            HumanResources* humanResources = new HumanResources(salary_hourly, hours_weekly, date_joined, age, phone, name, address, position);
            
            humanResources->set_trained(no_trained);
            humanResources->set_hired(no_hired);
            humanResources->set_fired(no_fired);
            humanResources->set_retired(no_retired);
            addPerson(humanResources);
            
        } else if (parts[1] == "Investor"){
            std::string input;
            int age;
            int phone;
            std::string name ;
            std::string address ;
            float amount_of_investment;

            std::cout << "Please enter Investor amount of investment: ";
            std::cin >> input;
            amount_of_investment = toFloat(input);

            std::cout << "Please enter Investor age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter Investor phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter Investor address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            Investor* investor = new Investor(age, phone, name, address, amount_of_investment);
            addPerson(investor);


        } else if (parts[1] == "Manager"){
            std::string input;
            float salary_hourly;
            float hours_weekly;
            std::string date_joined ;
            int age;
            int phone;
            std::string name;
            std::string address;
            std::string password;
            std::string position;

            std::cout << "Please enter Manager salary hourly: ";
            std::cin >> input;
            salary_hourly = toFloat(input);

            std::cout << "Please enter Manager hours weekly: ";
            std::cin >> input;
            hours_weekly = toFloat(input);

            std::cout << "Please enter Manager age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter Manager phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer
            
            std::cout << "Please enter Manager joined date: ";
            std::getline(std::cin, date_joined);
            if (date_joined.empty()) {date_joined = "none";}
            
            std::cout << "Please enter Manager address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter Manager position: ";
            std::getline(std::cin, position);
            if (position.empty()) {position = "none";}

            std::cout << "Please enter Manager password: ";
            std::getline(std::cin, password);
            if (password.empty()) {password = "none";}
            
            Manager* manager = new Manager(salary_hourly, hours_weekly, date_joined, age, phone, name,  address, password, position);
            addPerson(manager);

            
            
        } else if (parts[1] == "Manufacturing"){
            std::string input;
            float salary_hourly;
            float hours_weekly;
            std::string date_joined;
            int age;
            int phone;
            std::string name;
            std::string address;
            std::string position;
            std::string certification;
            int cars_complete;
            
            std::cout << "Please enter Manufacturing salary hourly: ";
            std::cin >> input;
            salary_hourly = toFloat(input);

            std::cout << "Please enter Manufacturing hours weekly: ";
            std::cin >> input;
            hours_weekly = toFloat(input);

            std::cout << "Please enter Manufacturing age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter Manufacturing phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter Manufacturing joined date: ";
            std::getline(std::cin, date_joined);
            if (date_joined.empty()) {date_joined = "none";}

            std::cout << "Please enter Manufacturing address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter Manufacturing certification: ";
            std::getline(std::cin, certification);
            if (certification.empty()) {certification = "none";}

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter how many cars Manufacturing have completed: ";
            std::cin >> input;
            cars_complete = toInt(input);

            Manufacturing *manufacturing = new Manufacturing(salary_hourly, hours_weekly, date_joined, age, phone, name, address, position, certification, cars_complete);
            addPerson(manufacturing);
            
            
        } else if (parts[1] == "Marketing"){
            std::string input;
            float salary_hourly;
            float hours_weekly;
            std::string date_joined;
            int age;
            int phone;
            std::string name;
            std::string address;
            std::string position;
            float success_rate;
            
            std::cout << "Please enter Marketing salary hourly: ";
            std::cin >> input;
            salary_hourly = toFloat(input);

            std::cout << "Please enter Marketing hours weekly: ";
            std::cin >> input;
            hours_weekly = toFloat(input);

            std::cout << "Please enter Marketing age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter Marketing phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter Marketing joined date: ";
            std::getline(std::cin, date_joined);
            if (date_joined.empty()) {date_joined = "none";}

            std::cout << "Please enter Marketing address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter Marketing position: ";
            std::getline(std::cin, position);
            if (position.empty()) {position = "none";}

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter Marketing success rate: ";
            std::cin >> input;
            success_rate = toFloat(input);

            Marketing *marketing = new Marketing(salary_hourly, hours_weekly, date_joined, age, phone, name, address, position, success_rate);
            addPerson(marketing);
            
        } else if (parts[1] == "ResearchDev"){
            std::string input;
            float salary_hourly;
            float hours_weekly;
            std::string date_joined;
            int age;
            int phone;
            std::string name;
            std::string address;
            std::string position;
            std::string finished;
            std::string current;
            std::string expertise;

            
            std::cout << "Please enter ResearchDev salary hourly: ";
            std::cin >> input;
            salary_hourly = toFloat(input);

            std::cout << "Please enter ResearchDev hours weekly: ";
            std::cin >> input;
            hours_weekly = toFloat(input);

            std::cout << "Please enter ResearchDev age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter ResearchDev phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter ResearchDev joined date: ";
            std::getline(std::cin, date_joined);
            if (date_joined.empty()) {date_joined = "none";}

            std::cout << "Please enter ResearchDev address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter ResearchDev position: ";
            std::getline(std::cin, position);
            if (position.empty()) {position = "none";}

            std::cout << "Please enter ResearchDev finished research: ";
            std::getline(std::cin, finished);
            if (finished.empty()) {finished = "none";}
            
            std::cout << "Please enter ResearchDev current research: ";
            std::getline(std::cin, current);
            if (current.empty()) {current = "none";}

            std::cout << "Please enter ResearchDev expertise: ";
            std::getline(std::cin, expertise);
            if (expertise.empty()) {expertise = "none";}

            ResearchDev *researchdev = new ResearchDev(salary_hourly, hours_weekly, date_joined, age, phone, name, address, position, finished, current, expertise);
            addPerson(researchdev);
            
        } else if (parts[1] == "Sales"){
            std::string input;
            float salary_hourly;
            float hours_weekly;
            std::string date_joined;
            int age;
            int phone;
            std::string name;
            std::string address;
            std::string position;
            float conversion_rate;
            int cars_sold;
            float revenue;
            
            std::cout << "Please enter Sales salary hourly: ";
            std::cin >> input;
            salary_hourly = toFloat(input);

            std::cout << "Please enter Sales hours weekly: ";
            std::cin >> input;
            hours_weekly = toFloat(input);

            std::cout << "Please enter Sales age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter Sales phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter Sales joined date: ";
            std::getline(std::cin, date_joined);
            if (date_joined.empty()) {date_joined = "none";}

            std::cout << "Please enter Sales address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter Sales position: ";
            std::getline(std::cin, position);
            if (position.empty()) {position = "none";}

            std::cout << "Please enter Sales conversion rate: ";
            std::cin >> input;
            conversion_rate = toFloat(input);
            
            std::cout << "Please enter how many cars Sales have sold: ";
            std::cin >> input;
            cars_sold = toFloat(input);

            std::cout << "Please enter Sales revenue: ";
            std::cin >> input;
            revenue = toFloat(input);

            Sales *sales = new Sales(salary_hourly, hours_weekly, date_joined, age, phone, name, address, position, conversion_rate, cars_sold, revenue);
            addPerson(sales);
            
        } else if (parts[1] == "Software"){
            std::string input;
            float salary_hourly;
            float hours_weekly;
            std::string date_joined;
            int age;
            int phone;
            std::string name;
            std::string address;
            std::string position;
            std::string languages;
            std::string projects_finished;
            std::string projects_current;
            
            
            std::cout << "Please enter their Software salary hourly: ";
            std::cin >> input;
            salary_hourly = toFloat(input);

            std::cout << "Please enter Software hours weekly: ";
            std::cin >> input;
            hours_weekly = toFloat(input);
            
            std::cout << "Please enter Software age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter Software phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter Software joined date: ";
            std::getline(std::cin, date_joined);
            if (date_joined.empty()) {date_joined = "none";}

            std::cout << "Please enter Software address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter Software position: ";
            std::getline(std::cin, position);
            if (position.empty()) {position = "none";}

            std::cout << "Please enter Software known languages: ";
            std::getline(std::cin, languages);
            if (languages.empty()) {languages = "none";}

            std::cout << "Please enter Software current project: ";
            std::getline(std::cin, projects_current);
            if (projects_current.empty()) {projects_current = "none";}

            std::cout << "Please enter Software finished projects: ";
            std::getline(std::cin, projects_finished);
            if (projects_finished.empty()) {projects_finished = "none";}

            Software *software = new Software(salary_hourly, hours_weekly, date_joined, age, phone, name, address, position);
            software->set_language(languages);
            software->set_projects_current(projects_current);
            software->set_finished(projects_finished);
            addPerson(software);

        } else if (parts[1] == "Supplier"){
            std::string input;
            int age;
            int phone;
            std::string name;
            std::string address;
            int amount_cargo;
            float cost_annually;
            std::string cargo;
            
            std::cout << "Please enter Supplier age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter Supplier phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter Supplier address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            std::cout << "Please enter what Supplier cargo is: ";
            std::getline(std::cin, cargo);
            if (cargo.empty()) {address = "none";}

            std::cout << "Please enter the amount of Supplier cargo (int): ";
            std::cin >> input;
            amount_cargo = toInt(input);

            std::cout << "Please enter Supplier cost annually in $: ";
            std::cin >> input;
            cost_annually = toFloat(input);
            
            Supplier *supplier = new Supplier(age, phone, name, address, amount_cargo, cost_annually, cargo);

            addPerson(supplier);
            
        } else if (parts[1] == "VIP"){
            std::string input;
            int age;
            int phone;
            std::string name;
            std::string address;
            int bank_number;
            int spendings;
            int clientId;
            std::string bank;
            std::string purchase_history;
            std::string notes;
            int referrals;
            
            std::cout << "Please enter VIP age: ";
            std::cin >> input;
            age = toInt(input);

            std::cout << "Please enter VIP phone number: ";
            std::cin >> input;
            phone = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            name = parts[2];
            if (name.empty()) {name = "none";}

            std::cout << "Please enter VIP address: ";
            std::getline(std::cin, address);
            if (address.empty()) {address = "none";}

            std::cout << "Please enter VIP bank number: ";
            std::cin >> input;
            bank_number = toInt(input);

            std::cout << "Please enter VIP spendings: ";
            std::cin >> input;
            spendings = toInt(input);

            std::cout << "Please enter VIP client ID: ";
            std::cin >> input;
            clientId = toInt(input);

            std::cin.ignore(); // Clear the newline character left in the input buffer

            std::cout << "Please enter VIP bank: ";
            std::getline(std::cin, bank);
            if (bank.empty()) {bank = "none";}

            std::cout << "Please enter VIP purchase history: ";
            std::getline(std::cin, purchase_history);
            if (purchase_history.empty()) { purchase_history = "none"; }

            std::cout << "Please enter VIP notes: ";
            std::getline(std::cin, notes);
            if (notes.empty()) {notes = "none";}

            std::cout << "Please enter VIP number of referrals: ";
            std::cin >> input;
            referrals = toInt(input);

            VIP *vip = new VIP(bank_number, spendings, clientId, bank, purchase_history, notes, age, phone, name, address, referrals);

            addPerson(vip);
        } else {
            std::cout << "Please enter one of the class options; Customer, VIP, Investor, Supplier, Design, Finances, HumanResources, Manager, Manufacturing, Marketing, ResearchDev, Sales or Software\n";
        }
    }


}

// Save file functions
// Save data
void Location::Save(std::string file){
    std::ofstream saveFile(file);

    if (saveFile.is_open()) {
        saveFile << "location_address: " << get_address() << "\n";
        saveFile << "curr_size: " << get_curr_size() << "\n";
        for (int i = 0; i < get_curr_size(); i++){
            if (strcmp(typeid(*people[i]).name(), "8Customer") != 0 && strcmp(typeid(*people[i]).name(), "3VIP") != 0 && strcmp(typeid(*people[i]).name(), "8Investor") != 0 && strcmp(typeid(*people[i]).name(), "8Supplier") != 0){
                saveFile << "counter: " << people[i]->get_counter() << "\n";
                break;
            } else {saveFile << "counter: 0\n";}
        }
        
        for (int i = 0; i < get_curr_size(); i++){
            if (strcmp(typeid(*people[i]).name(), "8Customer") == 0){
                saveFile << i << "type: customer\n";
                saveFile << i << "customer_age: " << people[i]->get_age() << "\n";
                saveFile << i << "customer_phone: " << people[i]->get_phone() << "\n";
                saveFile << i << "customer_name: " << people[i]->get_name() << "\n";
                saveFile << i << "customer_address: " << people[i]->get_address() << "\n";
                
                saveFile << i << "customer_bank_number: " << people[i]->get_bankAccount() << "\n";
                saveFile << i << "customer_spendings: " << people[i]->get_spendings() << "\n";
                saveFile << i << "customer_clientId: " << people[i]->get_clientId() << "\n";
                saveFile << i << "customer_bank: " << people[i]->get_bank() << "\n";
                saveFile << i << "customer_purchase_history: " << people[i]->get_purchase_history() << "\n";
                saveFile << i << "customer_notes: " << people[i]->get_notes() << "\n";
                
            } else if (strcmp(typeid(*people[i]).name(), "6Design") == 0){
                saveFile << i << "type: design\n";
                saveFile << i << "design_age: " << people[i]->get_age() << "\n";
                saveFile << i << "design_phone: " << people[i]->get_phone() << "\n";
                saveFile << i << "design_name: " << people[i]->get_name() << "\n";
                saveFile << i << "design_address: " << people[i]->get_address() << "\n";

                saveFile << i << "design_ID: " << people[i]->get_ID() << "\n";
                saveFile << i << "design_salary_hourly: " << people[i]->get_salary_hourly() << "\n";
                saveFile << i << "design_hours_weekly: " << people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "design_attendance" << j << ": " << people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "design_date_joined: " << people[i]->get_date_joined() << "\n";
                saveFile << i << "design_performance: " << people[i]->get_performance() << "\n";

                saveFile << i << "design_position: " << people[i]->get_position() << "\n";
                saveFile << i << "design_finished: " << people[i]->get_finished() << "\n";
                saveFile << i << "design_current: " << people[i]->get_design_current() << "\n";

            } else if (strcmp(typeid(*people[i]).name(), "8Finances") == 0){
                saveFile << i << "type: finances\n";
                saveFile << i << "finances_age: " << people[i]->get_age() << "\n";
                saveFile << i << "finances_phone: " << people[i]->get_phone() << "\n";
                saveFile << i << "finances_name: " << people[i]->get_name() << "\n";
                saveFile << i << "finances_address: " << people[i]->get_address() << "\n";

                saveFile << i << "finances_ID: " << people[i]->get_ID() << "\n";
                saveFile << i << "finances_salary_hourly: " << people[i]->get_salary_hourly() << "\n";
                saveFile << i << "finances_hours_weekly: " << people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "finances_attendance" << j << ": " << people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "finances_date_joined: " << people[i]->get_date_joined() << "\n";
                saveFile << i << "finances_performance: " << people[i]->get_performance() << "\n";

                saveFile << i << "finances_positions: " << people[i]->get_position() << "\n";
                saveFile << i << "finances_turnover_monthly: " << people[i]->get_turnover() << "\n";
                saveFile << i << "finances_profit_monthly: " << people[i]->get_profit() << "\n";
                saveFile << i << "finances_budget: " << people[i]->get_budget() << "\n";;
                saveFile << i << "finances_expense: " << people[i]->get_expense() << "\n";

            } else if (strcmp(typeid(*people[i]).name(), "14HumanResources") == 0){
                saveFile << i << "type: humanResources\n";
                saveFile << i << "humanResources_age: " << people[i]->get_age() << "\n";
                saveFile << i << "humanResources_phone: " << people[i]->get_phone() << "\n";
                saveFile << i << "humanResources_name: " << people[i]->get_name() << "\n";
                saveFile << i << "humanResources_address: " << people[i]->get_address() << "\n";
                
                saveFile << i << "humanResources_ID: " << people[i]->get_ID() << "\n";
                saveFile << i << "humanResources_salary_hourly: " << people[i]->get_salary_hourly() << "\n";
                saveFile << i << "humanResources_hours_weekly: " << people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "humanResources_attendance" << j << ": " << people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "humanResources_date_joined: " << people[i]->get_date_joined() << "\n";
                saveFile << i << "humanResources_performance: " << people[i]->get_performance() << "\n";
                
                saveFile << i << "humanResources_position: " << people[i]->get_position() << "\n";
                saveFile << i << "humanResources_trained: " << people[i]->get_trained() << "\n";
                saveFile << i << "humanResources_hired: " << people[i]->get_hired() << "\n";
                saveFile << i << "humanResources_fired: " << people[i]->get_fired() << "\n";
                saveFile << i << "humanResources_retired: " << people[i]->get_retired() << "\n";
                
            } else if (strcmp(typeid(*people[i]).name(), "8Investor") == 0){
                saveFile << i << "type: investor\n";
                saveFile << i << "investor_age: " << people[i]->get_age() << "\n";
                saveFile << i << "investor_phone: "<< people[i]->get_phone() << "\n";
                saveFile << i << "investor_name: " << people[i]->get_name() << "\n";
                saveFile << i << "investor_address: " << people[i]->get_address() << "\n";
                
                saveFile << i << "investor_ID: " << people[i]->get_ID() << "\n";
                saveFile << i << "investor_salary_hourly: " << people[i]->get_salary_hourly() << "\n";
                saveFile << i << "investor_hours_weekly: " << people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "investor_attendance" << j << ": " << people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "investor_date_joined: " << people[i]->get_date_joined() << "\n";
                saveFile << i << "investor_performance: " << people[i]->get_performance() << "\n";
                
                saveFile << i << "investor_amount_of_investment" << people[i]->get_amount_of_investment() << "\n";

            } else if (strcmp(typeid(*people[i]).name(), "7Manager") == 0){
                saveFile << i << "type: manager\n";
                saveFile << i << "manager_age: " << people[i]->get_age() << "\n";
                saveFile << i << "manager_phone: "<< people[i]->get_phone() << "\n";
                saveFile << i << "manager_name: " << people[i]->get_name() << "\n";
                saveFile << i << "manager_address: " << people[i]->get_address() << "\n";

                saveFile << i << "manager_ID: " << people[i]->get_ID() << "\n";
                saveFile << i << "manager_salary_hourly: " << people[i]->get_salary_hourly() << "\n";
                saveFile << i << "manager_hours_weekly: " << people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "manager_attendance" << j << ": " << people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "manager_date_joined: " << people[i]->get_date_joined() << "\n";
                saveFile << i << "manager_performance: " << people[i]->get_performance() << "\n";
    
                saveFile << i << "manager_position: " << people[i]->get_position() << "\n";
                saveFile << i << "manager_password: " << people[i]->get_password() << "\n";
                
            } else if (strcmp(typeid(*people[i]).name(), "13Manufacturing") == 0){
                saveFile << i << "type: manufacturing\n";
                saveFile << i << "manufacturing_age: " << people[i]->get_age() << "\n";
                saveFile << i << "manufacturing_phone: " << people[i]->get_phone() << "\n";
                saveFile << i << "manufacturing_name: "<< people[i]->get_name() << "\n";
                saveFile << i << "manufacturing_address: " << people[i]->get_address() << "\n";

                saveFile << i << "manufacturing_ID: " << people[i]->get_ID() << "\n";
                saveFile << i << "manufacturing_salary_hourly: " << people[i]->get_salary_hourly() << "\n";
                saveFile << i << "manufacturing_hours_weekly: " << people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "manufacturing_attendance" << j << ": " << people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "manufacturing_date_joined: " << people[i]->get_date_joined() << "\n";
                saveFile << i << "manufacturing_performance: " << people[i]->get_performance() << "\n";

                saveFile << i << "manufacturing_position: " << people[i]->get_position() << "\n";
                saveFile << i << "manufacturing_certification: " << people[i]->get_certification() << "\n";
                saveFile << i << "manufacturing_cars_complete: " << people[i]->get_cars_complete() << "\n";
                
            } else if (strcmp(typeid(*people[i]).name(), "9Marketing") == 0){
                saveFile << i << "type: marketing\n";
                saveFile << i << "marketing_age: " << people[i]->get_age() << "\n";
                saveFile << i << "marketing_phone: " << people[i]->get_phone() << "\n";
                saveFile << i << "marketing_name: "<< people[i]->get_name() << "\n";
                saveFile << i << "marketing_address: " << people[i]->get_address() << "\n";
                
                saveFile << i << "marketing_ID: " << people[i]->get_ID() << "\n";
                saveFile << i << "marketing_salary_hourly: " << people[i]->get_salary_hourly() << "\n";
                saveFile << i << "marketing_hours_weekly: " << people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "marketing_attendance" << j << ": " << people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "marketing_date_joined: " << people[i]->get_date_joined() << "\n";
                saveFile << i << "marketing_performance: " << people[i]->get_performance() << "\n";
                
                saveFile << i << "marketing_position: " << people[i]->get_position() << "\n";
                saveFile << i << "marketing_performance: " << people[i]->get_success_rate() << "\n";

            } else if (strcmp(typeid(*people[i]).name(), "11ResearchDev") == 0){
                saveFile << i << "type: researchDev\n";
                saveFile << i << "researchDev_age: " << people[i]->get_age() << "\n";
                saveFile << i << "researchDev_phone: " << people[i]->get_phone() << "\n";
                saveFile << i << "researchDev_name: "<< people[i]->get_name() << "\n";
                saveFile << i << "researchDev_address: " << people[i]->get_address() << "\n";
                
                saveFile << i << "researchDev_ID: " << people[i]->get_ID() << "\n";
                saveFile << i << "researchDev_salary_hourly: " << people[i]->get_salary_hourly() << "\n";
                saveFile << i << "researchDev_hours_weekly: " << people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "researchDev_attendance" << j << ": " << people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "researchDev_date_joined: " << people[i]->get_date_joined() << "\n";
                saveFile << i << "researchDev_performance: " << people[i]->get_performance() << "\n";
                
                saveFile << i << "researchDev_position:  " << people[i]->get_position() << "\n";
                saveFile << i << "finished_research: " << people[i]->get_finished() << "\n";
                saveFile << i << "current_research: " << people[i]->get_research() << "\n";
                saveFile << i << "expertise: " << people[i]->get_expertise() << "\n";

            } else if (strcmp(typeid(*people[i]).name(), "5Sales") == 0){
                saveFile << i << "type: sales\n";
                saveFile << i << "sales_age: " << people[i]->get_age() << "\n";
                saveFile << i << "sales_phone: "<< people[i]->get_phone() << "\n";
                saveFile << i << "sales_name: " << people[i]->get_name() << "\n";
                saveFile << i << "sales_address: " << people[i]->get_address() << "\n";
                
                saveFile << i << "sales_ID: " << people[i]->get_ID() << "\n";
                saveFile << i << "sales_salary_hourly: " << people[i]->get_salary_hourly() << "\n";
                saveFile << i << "sales hours_weekly: " << people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "sales_attendance" << j << ": " << people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "sales_date_joined: " << people[i]->get_date_joined() << "\n";
                saveFile << i << "sales_performance: " << people[i]->get_performance() << "\n";
                
                saveFile << i << "sales_position: " << people[i]->get_position() << "\n";
                saveFile << i << "sales_conversion_rate: " << people[i]->get_conversion_rate() << "\n";
                saveFile << i << "sales_cars_sold: " << people[i]->get_cars_sold() << "\n";
                saveFile << i << "sales_revenue: " << people[i]->get_revenue() << "\n";
 

            } else if (strcmp(typeid(*people[i]).name(), "8Software") == 0){
                saveFile << i << "type: software\n";
                saveFile << i << "software_age: " << people[i]->get_age() << "\n";
                saveFile << i << "software_phone: "<< people[i]->get_phone() << "\n";
                saveFile << i << "software_name: " << people[i]->get_name() << "\n";
                saveFile << i << "software_address: " << people[i]->get_address() << "\n";
                    
                saveFile << i << "software_positions: " << people[i]->get_position() << "\n";
                saveFile << i << "software_languages: " << people[i]->get_languages() << "\n";
                saveFile << i << "software_projects_finished: " << people[i]->get_finished() << "\n";
                saveFile << i << "software_projects_current: " << people[i]->get_projects_current() << "\n";

                saveFile << i << "software_ID : " << people[i]->get_ID() << "\n";
                saveFile << i << "software_salary_hourly: " << people[i]->get_salary_hourly() << "\n";
                saveFile << i << "software_hours_weekly: " << people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "software_attendance" << j << ": " << people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "software_date_joined: " << people[i]->get_date_joined() << "\n";
                saveFile << i << "software_performance: " << people[i]->get_performance() << "\n";
                  

            } else if (strcmp(typeid(*people[i]).name(), "8Supplier") == 0){
                saveFile << i << "type: supplier\n";
                saveFile << i << "supplier_age: " << people[i]->get_age() << "\n";
                saveFile << i << "supplier_phone: " << people[i]->get_phone() << "\n";
                saveFile << i << "supplier_name: " << people[i]->get_name() << "\n";
                saveFile << i << "supplier_address: " << people[i]->get_address() << "\n";
                
                saveFile << i << "supplier_amount_cargo: " << people[i]->get_amount_of_cargo() << "\n";
                saveFile << i << "supplier_cost_annually: " << people[i]->get_cost_annually() << "\n";
                saveFile << i << "supplier_cargo: " << people[i]->get_cargo() << "\n";
            
            } else if (strcmp(typeid(*people[i]).name(), "3VIP") == 0){
                saveFile << i << "type: VIP\n";
                saveFile << i << "VIP_referrals: " << people[i]->get_referrals() << "\n";
                saveFile << i << "VIP_age: " << people[i]->get_age() << "\n";
                saveFile << i << "VIP_phone: " << people[i]->get_phone() << "\n";
                saveFile << i << "VIP_name: " << people[i]->get_name() << "\n";
                saveFile << i << "VIP_address: " << people[i]->get_address() << "\n";
                saveFile << i << "VIP_bank_number: " << people[i]->get_bankAccount() << "\n";
                saveFile << i << "VIP_spendings: " << people[i]->get_spendings() << "\n";
                saveFile << i << "VIP_clientId: " << people[i]->get_clientId() << "\n";
                saveFile << i << "VIP_bank: " << people[i]->get_bank() << "\n";
                saveFile << i << "VIP_purchase_history: " << people[i]->get_purchase_history() << "\n";
                saveFile << i << "VIP_notes: " << people[i]->get_notes() << "\n";
                
            }
        } 

    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

//Load data
bool Location::Load(std::string file){
    std::ifstream saveFile(file);
    std::string line;

    if (saveFile.is_open()){

        std::string address;
        int curr_size;
        int counter;

        std::getline(saveFile, line);
        address = line.substr(line.find(": ") + 2);
        set_address(address);

        std::getline(saveFile, line);
        curr_size = std::stoi(line.substr(line.find(": ") + 2));

        std::getline(saveFile, line);
        counter = std::stoi(line.substr(line.find(": ") + 2));

        for (int i = 0; i < curr_size; i ++){

            std::getline(saveFile, line);
            std::string type = line.substr(line.find("type: ") + 6);
            //cout << line.substr(line.find("type: ") + 6) << endl;

            if (type == "customer"){
                Customer *customer = new Customer();
                    try{
                        std::getline(saveFile, line); //std::cout << "Reading line for age: " << line << std::endl;
                        customer->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                        customer->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                        customer->set_name(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                        customer->set_address(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for bank_number: " << line << std::endl;
                        customer->set_bankAccount(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for spendings: " << line << std::endl;
                        customer->set_spendings(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for clientId: " << line << std::endl;
                        customer->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for bank: " << line << std::endl;
                        customer->set_bank(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for purchase_history: " << line << std::endl;
                        customer->set_purchase_history(line.substr(line.find(": ") + 2));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for notes: " << line << std::endl;
                        customer->set_notes(line.substr(line.find(": ") + 2));
                    
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                    
                addPerson(customer);
                
            } else if (type == "design") {
                Design *design = new Design();
                    try{
                        std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                        design->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                        design->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                        design->set_name(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                        design->set_address(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for ID: " << line << std::endl;
                        design->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for salary_hourly: " << line << std::endl;
                        design->set_salary_hourly(std::stof(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for hours_weekly: " << line << std::endl;
                        design->set_hours_weekly(std::stof(line.substr(line.find(": ") + 2)));

                        for (int j = 0; j < 7; j++) {
                            std::getline(saveFile, line); //std::cout << "Reading line for attendance " << j << ": " << line << std::endl;
                            design->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                        }
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for date_joined: " << line << std::endl;
                        design->set_date_joined(line.substr(line.find(": ") + 2));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for performance: " << line << std::endl;
                        design->set_performance(std::stoi(line.substr(line.find(": ") + 2)));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                        design->set_position(line.substr(line.find(": ") + 2));
                        //
                        std::getline(saveFile, line); //std::cout << "Reading line for finished: " << line << std::endl;
                        design->set_finished(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for current: " << line << std::endl;
                        design->set_design_current(line.substr(line.find(": ") + 2));
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                addPerson(design);
                
            } else if (type == "finances") {
                Finances *finances = new Finances();
                    try{
                        std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                        finances->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                        finances->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                        finances->set_name(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                        finances->set_address(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for ID: " << line << std::endl;
                        finances->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for salary_hourly: " << line << std::endl;
                        finances->set_salary_hourly(std::stof(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for hours_weekly: " << line << std::endl;
                        finances->set_hours_weekly(std::stof(line.substr(line.find(": ") + 2)));

                        for (int j = 0; j < 7; j++) {
                            std::getline(saveFile, line); //std::cout << "Reading line for attendance " << j << ": " << line << std::endl;
                            finances->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                        }
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for date_joined: " << line << std::endl;
                        finances->set_date_joined(line.substr(line.find(": ") + 2));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for performance: " << line << std::endl;
                        finances->set_performance(std::stoi(line.substr(line.find(": ") + 2)));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                        finances->set_position(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for turnover: " << line << std::endl;
                        finances->set_turnover(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                        finances->set_profit(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                        finances->set_budget(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                        finances->set_expense(std::stoi(line.substr(line.find(": ") + 2)));
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }

                addPerson(finances);
            } else if (type == "humanResources") {
                HumanResources *humanResources = new HumanResources();
                    try{
                        std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                        humanResources->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                        humanResources->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                        humanResources->set_name(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                        humanResources->set_address(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for ID: " << line << std::endl;
                        humanResources->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for salary_hourly: " << line << std::endl;
                        humanResources->set_salary_hourly(std::stof(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for hours_weekly: " << line << std::endl;
                        humanResources->set_hours_weekly(std::stof(line.substr(line.find(": ") + 2)));

                        for (int j = 0; j < 7; j++) {
                            std::getline(saveFile, line); //std::cout << "Reading line for attendance " << j << ": " << line << std::endl;
                            humanResources->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                        }
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for date_joined: " << line << std::endl;
                        humanResources->set_date_joined(line.substr(line.find(": ") + 2));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for performance: " << line << std::endl;
                        humanResources->set_performance(std::stoi(line.substr(line.find(": ") + 2)));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                        humanResources->set_position(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for trained: " << line << std::endl;
                        humanResources->set_trained(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for hired: " << line << std::endl;
                        humanResources->set_hired(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for fired: " << line << std::endl;
                        humanResources->set_fired(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for retired: " << line << std::endl;
                        humanResources->set_retired(std::stoi(line.substr(line.find(": ") + 2)));

                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                addPerson(humanResources);
                
            } else if (type == "investor") {
                Investor *investor = new Investor();
                    try{ 
                        std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                        investor->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                        investor->set_phone(std::stoi(line.substr(line.find(": ") + 2)));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                        investor->set_name(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                        investor->set_address(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for ID: " << line << std::endl;
                        investor->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for salary_hourly: " << line << std::endl;
                        investor->set_salary_hourly(std::stof(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for hours_weekly: " << line << std::endl;
                        investor->set_hours_weekly(std::stof(line.substr(line.find(": ") + 2)));

                        for (int j = 0; j < 7; j++) {
                            std::getline(saveFile, line); //std::cout << "Reading line for attendance " << j << ": " << line << std::endl;
                            investor->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                        }
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for date_joined: " << line << std::endl;
                        investor->set_date_joined(line.substr(line.find(": ") + 2));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for performance: " << line << std::endl;
                        investor->set_performance(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for amount_of_investment: " << line << std::endl;
                        investor->set_amount_of_investment(std::stof(line.substr(line.find(": ") + 2)));

                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }

                addPerson(investor);

            } else if (type == "manager") {
                Manager *manager = new Manager();
                    try{
                        std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                        manager->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                        manager->set_phone(std::stoi(line.substr(line.find(": ") + 2)));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                        manager->set_name(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                        manager->set_address(line.substr(line.find(": ") + 2));

                        std::getline(saveFile, line); //std::cout << "Reading line for ID: " << line << std::endl;
                        manager->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for salary_hourly: " << line << std::endl;
                        manager->set_salary_hourly(std::stof(line.substr(line.find(": ") + 2)));

                        std::getline(saveFile, line); //std::cout << "Reading line for hours_weekly: " << line << std::endl;
                        manager->set_hours_weekly(std::stof(line.substr(line.find(": ") + 2)));

                        for (int j = 0; j < 7; j++) {
                            std::getline(saveFile, line); //std::cout << "Reading line for attendance " << j << ": " << line << std::endl;
                            manager->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                        }
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for date_joined: " << line << std::endl;
                        manager->set_date_joined(line.substr(line.find(": ") + 2));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for performance: " << line << std::endl;
                        manager->set_performance(std::stoi(line.substr(line.find(": ") + 2)));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                        manager->set_position(line.substr(line.find(": ") + 2));
                        
                        std::getline(saveFile, line); //std::cout << "Reading line for password: " << line << std::endl;
                        manager->set_password(line.substr(line.find(": ") + 2));
                    
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                    
                addPerson(manager);  

            } else if (type == "manufacturing") {
               Manufacturing *manufacturing = new Manufacturing();
               try {
                    std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                    manufacturing->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                    manufacturing->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                    manufacturing->set_name(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                    manufacturing->set_address(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for ID: " << line << std::endl;
                    manufacturing->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for salary_hourly: " << line << std::endl;
                    manufacturing->set_salary_hourly(std::stof(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for hours_weekly: " << line << std::endl;
                    manufacturing->set_hours_weekly(std::stof(line.substr(line.find(": ") + 2)));

                    for (int j = 0; j < 7; j++) {
                        std::getline(saveFile, line); //std::cout << "Reading line for attendance " << j << ": " << line << std::endl;
                        manufacturing->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                    }

                    std::getline(saveFile, line); //std::cout << "Reading line for date_joined: " << line << std::endl;
                    manufacturing->set_date_joined(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for performance: " << line << std::endl;
                    manufacturing->set_performance(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                    manufacturing->set_position(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for certification: " << line << std::endl;
                    manufacturing->set_certification(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for cars_complete: " << line << std::endl;
                    manufacturing->set_cars_complete(std::stoi(line.substr(line.find(": ") + 2)));

                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                addPerson(manufacturing);    

            } else if (type == "researchDev") {
                ResearchDev *researchDev = new ResearchDev();
                try {
                    std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                    researchDev->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                    researchDev->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                    researchDev->set_name(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                    researchDev->set_address(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for ID: " << line << std::endl;
                    researchDev->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for salary_hourly: " << line << std::endl;
                    researchDev->set_salary_hourly(std::stof(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for hours_weekly: " << line << std::endl;
                    researchDev->set_hours_weekly(std::stof(line.substr(line.find(": ") + 2)));

                    for (int j = 0; j < 7; j++) {
                        std::getline(saveFile, line); //std::cout << "Reading line for attendance " << j << ": " << line << std::endl;
                        researchDev->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                    }

                    std::getline(saveFile, line); //std::cout << "Reading line for date_joined: " << line << std::endl;
                    researchDev->set_date_joined(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for performance: " << line << std::endl;
                    researchDev->set_performance(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                    researchDev->set_position(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for finished: " << line << std::endl;
                    researchDev->set_finished(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for research: " << line << std::endl;
                    researchDev->set_research(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for expertise: " << line << std::endl;
                    researchDev->set_expertise(line.substr(line.find(": ") + 2));

                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                addPerson(researchDev);      

            } else if (type == "marketing") {
                Marketing *marketing = new Marketing();
                try {
                    std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                    marketing->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                    marketing->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                    marketing->set_name(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                    marketing->set_address(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for ID: " << line << std::endl;
                    marketing->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for salary_hourly: " << line << std::endl;
                    marketing->set_salary_hourly(std::stof(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for hours_weekly: " << line << std::endl;
                    marketing->set_hours_weekly(std::stof(line.substr(line.find(": ") + 2)));

                    for (int j = 0; j < 7; j++) {
                        std::getline(saveFile, line); //std::cout << "Reading line for attendance " << j << ": " << line << std::endl;
                        marketing->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                    }

                    std::getline(saveFile, line); //std::cout << "Reading line for date_joined: " << line << std::endl;
                    marketing->set_date_joined(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for performance: " << line << std::endl;
                    marketing->set_performance(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                    marketing->set_position(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for success_rate: " << line << std::endl;
                    marketing->set_success_rate(std::stof(line.substr(line.find(": ") + 2)));

                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                addPerson(marketing);
            } else if (type == "sales") {
                Sales *sales = new Sales();
                try {
                    std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                    sales->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                    sales->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                    sales->set_name(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                    sales->set_address(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for ID: " << line << std::endl;
                    sales->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for salary_hourly: " << line << std::endl;
                    sales->set_salary_hourly(std::stof(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for hours_weekly: " << line << std::endl;
                    sales->set_hours_weekly(std::stof(line.substr(line.find(": ") + 2)));

                    for (int j = 0; j < 7; j++) {
                        std::getline(saveFile, line); //std::cout << "Reading line for attendance " << j << ": " << line << std::endl;
                        sales->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                    }

                    std::getline(saveFile, line); //std::cout << "Reading line for date_joined: " << line << std::endl;
                    sales->set_date_joined(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for performance: " << line << std::endl;
                    sales->set_performance(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                    sales->set_position(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for conversion_rate: " << line << std::endl;
                    sales->set_conversion_rate(std::stof(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for cars_sold: " << line << std::endl;
                    sales->set_cars_sold(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for revenue: " << line << std::endl;
                    sales->set_revenue(std::stof(line.substr(line.find(": ") + 2)));

                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                addPerson(sales);
            } else if (type == "software") {
                Software *software = new Software();
                try {
                    std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                    software->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                    software->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                    software->set_name(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                    software->set_address(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for position: " << line << std::endl;
                    software->set_position(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for language: " << line << std::endl;
                    software->set_language(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for finished: " << line << std::endl;
                    software->set_finished(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for projects_current: " << line << std::endl;
                    software->set_projects_current(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for ID: " << line << std::endl;
                    software->set_ID(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for salary_hourly: " << line << std::endl;
                    software->set_salary_hourly(std::stof(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for hours_weekly: " << line << std::endl;
                    software->set_hours_weekly(std::stof(line.substr(line.find(": ") + 2)));

                    for (int j = 0; j < 7; j++) {
                        std::getline(saveFile, line); //std::cout << "Reading line for attendance " << j << ": " << line << std::endl;
                        software->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                    }

                    std::getline(saveFile, line); //std::cout << "Reading line for date_joined: " << line << std::endl;
                    software->set_date_joined(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for performance: " << line << std::endl;
                    software->set_performance(std::stoi(line.substr(line.find(": ") + 2)));

                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                addPerson(software);

            } else if (type == "supplier") {
                Supplier *supplier = new Supplier();
                try {
                    std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                    supplier->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                    supplier->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                    supplier->set_name(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                    supplier->set_address(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for amount_of_cargo: " << line << std::endl;
                    supplier->set_amount_of_cargo(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for cost_annually: " << line << std::endl;
                    supplier->set_cost_annually(std::stof(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for cargo: " << line << std::endl;
                    supplier->set_cargo(line.substr(line.find(": ") + 2));

                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                addPerson(supplier);
            } else if (type == "VIP") {
                VIP *vip = new VIP();
                try {
                    std::getline(saveFile, line); //std::cout << "Reading line for referrals: " << line << std::endl;
                    vip->set_referrals(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); ////std::cout << "Reading line for age: " << line << std::endl;
                    vip->set_age(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for phone: " << line << std::endl;
                    vip->set_phone(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for name: " << line << std::endl;
                    vip->set_name(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for address: " << line << std::endl;
                    vip->set_address(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for bank_number: " << line << std::endl;
                    vip->set_bankAccount(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for spendings: " << line << std::endl;
                    vip->set_spendings(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for clientID: " << line << std::endl;
                    vip->set_clientId(std::stoi(line.substr(line.find(": ") + 2)));

                    std::getline(saveFile, line); //std::cout << "Reading line for bank: " << line << std::endl;
                    vip->set_bank(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for purchase_history: " << line << std::endl;
                    vip->set_purchase_history(line.substr(line.find(": ") + 2));

                    std::getline(saveFile, line); //std::cout << "Reading line for notes: " << line << std::endl;
                    vip->set_notes(line.substr(line.find(": ") + 2));

                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Out of range: " << e.what() << " - Line content: " << line << std::endl;
                        return false;
                    }
                addPerson(vip);
            } else {
                std::cerr << "Unable to open file for loading." << std::endl;
                return false;
            }
        }
    
    people[0]->set_counter(counter);
    }

    return true;
    
}


void Location::clear(){
    system("clear");

    std::string lines[] = {
        "        BBBBBBq  BBBBBBE    BBBBBBBQ     BBQBi  BQBB     BBBBQBBi     iBBBBBBBBi    BQBQBBBBb",
        "        BBQBBBB  BBBBBBP    QBBBBBBB     BBBBB  BBBB    iBBBQBBB2    rQBBBQQBBBBi   BBBBQBQBZ",
        "        BBBBBBB iBBBBBB5    BBBBBQBB     QBBBB  BBBQ    IBBBBBBBB    BBBBB  BQBBB   BBBBBrrLi",
        "        BBQBBBQ vBBBBBBS   rBBBZUBBBi    BBBBBE BBBB    QBBBYQBBB    BBBBB  BBBBB   BBBBB",
        "        BBBBgBBiqBQMBBB2   SBBB7iBBQX    BBBBQB BBBB    BBBB bBBB    BBBBQ  7iir7   BBBBB",
        "        BBBB7BBgBB2PBBQS   BBBBi BBBB    BBBBBQQQBBB    BBQB KBBBv   BBBQB          BBBBBBBBi",
        "        BBBBigBBBBr5BBBI   BBBB  BBBB    BBQBBBBBBBB   iBQBQ 7BBBD   BBBBB BBQBBB   BBBBBBBB7",
        "        BBBB 5QBBB KQBB5   BBBB  BBBQi   BBBD1BBBBBB   SBBBd iBBBB   BBBBB sQBBBB   QBBBBi i",
        "        BQBQ iBBBB PBBBI  rBBQBQBBBQBJ   BBBQ BBBQBB   BBBBBBBBBBB   BBBBB  BBBBB   BBBBB",
        "        BBBB  BBQB gBBB5  PBBBBBBBBBBB   BBBB 5BBBQB   BQBBBBBQBBBi  BBBBB  BBBBB   BBBBB",
        "        BBBB  BBBg MBQBI  BBBBBi QBBBB   BBBB  QBQBB   BBBBQ iBBBBP  bBBBBi BBBBB   BQBBBBBBB",
        "        BBBBi QBBX BQBQg  QBBBQ  BQBBBi  BBBB  BBBBB  jBBBBZ  BBQBB   QBBBBBBBBBB   QBBBBBBBB",
        "        gPPZ  1bZi udqZr  RqqqK  rEKPDi  DPPE  iEKPg  vEPKEi  dqqPR    rQBBR  PPq   qPqXKKPbP\n",
        "                             Code By: Victor, Elijah, and Kurt\n",
        "                                     Location: " + address + "\n\n"
    };

    for (const auto& line : lines) {
        std::cout << line << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // Adjust the delay as needed
    }
}