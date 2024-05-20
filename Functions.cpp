#include "Functions.h"
#include <typeinfo>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
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
// #include "Salary.h"
#include "Sales.h"
#include "Software.h"
#include "Supplier.h"
#include "VIP.h"

// Password checking function
bool Access(Location *location, std::string& perms, std::string username, std::string password){
    int index = -1;                                                 // Sets index at -1 to setup for the no found clause
    for (int i = 0; i < location->get_curr_size(); i ++){           // Searches all the names in location to find the index
        if (location->people[i]->get_name() == username){
            index = i;
            break;
        }
    }

    if (index == -1){                                               // Clause for if no name found
        std::cout << "Username incorrect." << std::endl;
        return false;
    }

    if (location->people[index]->get_password() == password){       // Checking if the password matches

        if (strcmp(typeid(*location->people[index]).name(), "7Manager") == 0){ // In GCC compiling this works as typeid will show 7 representing the characters in the class then the class name
            perms = "Manager";                                      // A permission level is returned for later use
            std::cout << "Access granted." << std::endl;
            return true;
        }
    }

    std::cout << "Username or password is incorrect. " << std::endl; // If no other check it hit then the username must not match the password
    return false;

}

// Save file functions
// Save data
void Save(Location *location, std::string file){
    std::ofstream saveFile(file);

    if (saveFile.is_open()) {
        saveFile << "location_address: " << location->get_address() << "\n";
        saveFile << "curr_size: " << location->get_curr_size() << "\n";
        for (int i = 0; i < location->get_curr_size(); i++){
            if (strcmp(typeid(*location->people[i]).name(), "8Customer") != 0 && strcmp(typeid(*location->people[i]).name(), "3VIP") != 0 && strcmp(typeid(*location->people[i]).name(), "8Investor") != 0 && strcmp(typeid(*location->people[i]).name(), "8Supplier") != 0){
                saveFile << "counter: " << location->people[i]->get_counter() << "\n";
                break;
            } else {saveFile << "counter: 0\n";}
        }
        
        for (int i = 0; i < location->get_curr_size(); i++){
            if (strcmp(typeid(*location->people[i]).name(), "8Customer") == 0){
                saveFile << i << "type: customer\n";
                saveFile << i << "customer_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "customer_phone: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "customer_name: " << location->people[i]->get_name() << "\n";
                saveFile << i << "customer_address: " << location->people[i]->get_address() << "\n";
                
                saveFile << i << "customer_bank_number: " << location->people[i]->get_bankAccount() << "\n";
                saveFile << i << "customer_spendings: " << location->people[i]->get_spendings() << "\n";
                saveFile << i << "customer_clientId: " << location->people[i]->get_clientId() << "\n";
                saveFile << i << "customer_bank: " << location->people[i]->get_bank() << "\n";
                saveFile << i << "customer_purchase_history: " << location->people[i]->get_purchase_history() << "\n";
                saveFile << i << "customer_notes: " << location->people[i]->get_notes() << "\n";
                
            } else if (strcmp(typeid(*location->people[i]).name(), "6Design") == 0){
                saveFile << i << "type: design\n";
                saveFile << i << "design_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "design_phone: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "design_name: " << location->people[i]->get_name() << "\n";
                saveFile << i << "design_address: " << location->people[i]->get_address() << "\n";

                saveFile << i << "design_ID: " << location->people[i]->get_ID() << "\n";
                saveFile << i << "design_salary_hourly: " << location->people[i]->get_salary_hourly() << "\n";
                saveFile << i << "design_hours_weekly: " << location->people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "design_attendance" << j << ": " << location->people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "design_date_joined: " << location->people[i]->get_date_joined() << "\n";
                saveFile << i << "design_performance: " << location->people[i]->get_performance() << "\n";

                saveFile << i << "design_position: " << location->people[i]->get_position() << "\n";
                saveFile << i << "design_finished: " << location->people[i]->get_finished() << "\n";
                saveFile << i << "design_current: " << location->people[i]->get_design_current() << "\n";

            } else if (strcmp(typeid(*location->people[i]).name(), "8Finances") == 0){
                saveFile << i << "type: finances\n";
                saveFile << i << "finances_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "finances_phone: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "finances_name: " << location->people[i]->get_name() << "\n";
                saveFile << i << "finances_address: " << location->people[i]->get_address() << "\n";

                saveFile << i << "finances_ID: " << location->people[i]->get_ID() << "\n";
                saveFile << i << "finances_salary_hourly: " << location->people[i]->get_salary_hourly() << "\n";
                saveFile << i << "finances_hours_weekly: " << location->people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "finances_attendance" << j << ": " << location->people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "finances_date_joined: " << location->people[i]->get_date_joined() << "\n";
                saveFile << i << "finances_performance: " << location->people[i]->get_performance() << "\n";

                saveFile << i << "finances_positions: " << location->people[i]->get_position() << "\n";
                saveFile << i << "finances_turnover_monthly: " << location->people[i]->get_turnover() << "\n";
                saveFile << i << "finances_profit_monthly: " << location->people[i]->get_profit() << "\n";
                saveFile << i << "finances_budget: " << location->people[i]->get_budget() << "\n";;
                saveFile << i << "finances_expense: " << location->people[i]->get_expense() << "\n";

            } else if (strcmp(typeid(*location->people[i]).name(), "14HumanResources") == 0){
                saveFile << i << "type: humanResources\n";
                saveFile << i << "humanResources_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "humanResources_phone: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "humanResources_name: " << location->people[i]->get_name() << "\n";
                saveFile << i << "humanResources_address: " << location->people[i]->get_address() << "\n";
                
                saveFile << i << "humanResources_ID: " << location->people[i]->get_ID() << "\n";
                saveFile << i << "humanResources_salary_hourly: " << location->people[i]->get_salary_hourly() << "\n";
                saveFile << i << "humanResources_hours_weekly: " << location->people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "humanResources_attendance" << j << ": " << location->people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "humanResources_date_joined: " << location->people[i]->get_date_joined() << "\n";
                saveFile << i << "humanResources_performance: " << location->people[i]->get_performance() << "\n";
                
                saveFile << i << "humanResources_position: " << location->people[i]->get_position() << "\n";
                saveFile << i << "humanResources_trained: " << location->people[i]->get_trained() << "\n";
                saveFile << i << "humanResources_hired: " << location->people[i]->get_hired() << "\n";
                saveFile << i << "humanResources_fired: " << location->people[i]->get_fired() << "\n";
                saveFile << i << "humanResources_retired: " << location->people[i]->get_retired() << "\n";
                
            } else if (strcmp(typeid(*location->people[i]).name(), "8Investor") == 0){
                saveFile << i << "type: investor\n";
                saveFile << i << "investor_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "investor_name: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "investor_phone: "<< location->people[i]->get_name() << "\n";
                saveFile << i << "investor_address: " << location->people[i]->get_address() << "\n";
                
                saveFile << i << "investor_ID: " << location->people[i]->get_ID() << "\n";
                saveFile << i << "investor_salary_hourly: " << location->people[i]->get_salary_hourly() << "\n";
                saveFile << i << "investor_hours_weekly: " << location->people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "investor_attendance" << j << ": " << location->people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "investor_date_joined: " << location->people[i]->get_date_joined() << "\n";
                saveFile << i << "investor_performance: " << location->people[i]->get_performance() << "\n";
                
                saveFile << i << "investor_amount_of_investment" << location->people[i]->get_amount_of_investment() << "\n";

            } else if (strcmp(typeid(*location->people[i]).name(), "7Manager") == 0){
                saveFile << i << "type: manager\n";
                saveFile << i << "manager_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "manager_name: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "manager_phone: "<< location->people[i]->get_name() << "\n";
                saveFile << i << "manager_address: " << location->people[i]->get_address() << "\n";

                saveFile << i << "manager_ID: " << location->people[i]->get_ID() << "\n";
                saveFile << i << "manager_salary_hourly: " << location->people[i]->get_salary_hourly() << "\n";
                saveFile << i << "manager_hours_weekly: " << location->people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "manager_attendance" << j << ": " << location->people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "manager_date_joined: " << location->people[i]->get_date_joined() << "\n";
                saveFile << i << "manager_performance: " << location->people[i]->get_performance() << "\n";
    
                saveFile << i << "manager_password: " << location->people[i]->get_password() << "\n";
                saveFile << i << "manager_position: " << location->people[i]->get_position() << "\n";
                
            } else if (strcmp(typeid(*location->people[i]).name(), "13Manufacturing") == 0){
                saveFile << i << "type: manufacturing\n";
                saveFile << i << "manufacturing_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "manufacturing_name: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "manufacturing_phone: "<< location->people[i]->get_name() << "\n";
                saveFile << i << "manufacturing_address: " << location->people[i]->get_address() << "\n";

                saveFile << i << "manufacturing_ID: " << location->people[i]->get_ID() << "\n";
                saveFile << i << "manufacturing_salary_hourly: " << location->people[i]->get_salary_hourly() << "\n";
                saveFile << i << "manufacturing_hours_weekly: " << location->people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "manufacturing_attendance" << j << ": " << location->people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "manufacturing_date_joined: " << location->people[i]->get_date_joined() << "\n";
                saveFile << i << "manufacturing_performance: " << location->people[i]->get_performance() << "\n";

                saveFile << i << "manufacturing_position: " << location->people[i]->get_position() << "\n";
                saveFile << i << "manufacturing_certification: " << location->people[i]->get_certification() << "\n";
                saveFile << i << "manufacturing_cars_complete: " << location->people[i]->get_cars_complete() << "\n";
                
            } else if (strcmp(typeid(*location->people[i]).name(), "9Marketing") == 0){
                saveFile << i << "type: marketing\n";
                saveFile << i << "marketing_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "marketing_name: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "marketing_phone: "<< location->people[i]->get_name() << "\n";
                saveFile << i << "marketing_address: " << location->people[i]->get_address() << "\n";
                
                saveFile << i << "marketing_ID: " << location->people[i]->get_ID() << "\n";
                saveFile << i << "marketing_salary_hourly: " << location->people[i]->get_salary_hourly() << "\n";
                saveFile << i << "marketing_hours_weekly: " << location->people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "marketing_attendance" << j << ": " << location->people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "marketing_date_joined: " << location->people[i]->get_date_joined() << "\n";
                saveFile << i << "marketing_performance: " << location->people[i]->get_performance() << "\n";
                
                saveFile << i << "marketing_position: " << location->people[i]->get_position() << "\n";
                saveFile << i << "marketing_performance: " << location->people[i]->get_success_rate() << "\n";

            } else if (strcmp(typeid(*location->people[i]).name(), "11ResearchDev") == 0){
                saveFile << i << "type: researchDev\n";
                saveFile << i << "researchDev_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "researchDev_name: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "researchDev_phone: "<< location->people[i]->get_name() << "\n";
                saveFile << i << "researchDev_address: " << location->people[i]->get_address() << "\n";
                
                saveFile << i << "researchDev_ID: " << location->people[i]->get_ID() << "\n";
                saveFile << i << "researchDev_salary_hourly: " << location->people[i]->get_salary_hourly() << "\n";
                saveFile << i << "researchDev_hours_weekly: " << location->people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "researchDev_attendance" << j << ": " << location->people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "researchDev_date_joined: " << location->people[i]->get_date_joined() << "\n";
                saveFile << i << "researchDev_performance: " << location->people[i]->get_performance() << "\n";
                
                saveFile << i << "researchDev_position:  " << location->people[i]->get_position() << "\n";
                saveFile << i << "finished_research: " << location->people[i]->get_finished() << "\n";
                saveFile << i << "current_research: " << location->people[i]->get_research() << "\n";
                saveFile << i << "expertise: " << location->people[i]->get_expertise() << "\n";

            } else if (strcmp(typeid(*location->people[i]).name(), "5Sales") == 0){
                saveFile << i << "type: sales\n";
                saveFile << i << "sales_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "sales_name: " << location->people[i]->get_name() << "\n";
                saveFile << i << "sales_phone: "<< location->people[i]->get_phone() << "\n";
                saveFile << i << "sales_address: " << location->people[i]->get_address() << "\n";
                
                saveFile << i << "sales_ID: " << location->people[i]->get_ID() << "\n";
                saveFile << i << "sales_salary_hourly: " << location->people[i]->get_salary_hourly() << "\n";
                saveFile << i << "sales hours_weekly: " << location->people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "sales_attendance" << j << ": " << location->people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "sales_date_joined: " << location->people[i]->get_date_joined() << "\n";
                saveFile << i << "sales_performance: " << location->people[i]->get_performance() << "\n";
                
                saveFile << i << "sales_position: " << location->people[i]->get_position() << "\n";
                saveFile << i << "sales_conversion_rate: " << location->people[i]->get_conversion_rate() << "\n";
                saveFile << i << "sales_cars_sold: " << location->people[i]->get_cars_sold() << "\n";
                saveFile << i << "sales_revenue: " << location->people[i]->get_revenue() << "\n";
 

            } else if (strcmp(typeid(*location->people[i]).name(), "8Software") == 0){
                saveFile << i << "type: software\n";
                saveFile << i << "software_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "software_name: " << location->people[i]->get_name() << "\n";
                saveFile << i << "software_phone: "<< location->people[i]->get_phone() << "\n";
                saveFile << i << "software_address: " << location->people[i]->get_address() << "\n";
                    
                saveFile << i << "software_positions: " << location->people[i]->get_position() << "\n";
                saveFile << i << "software_languages: " << location->people[i]->get_languages() << "\n";
                saveFile << i << "software_projects_finished: " << location->people[i]->get_finished() << "\n";
                saveFile << i << "software_projects_current: " << location->people[i]->get_projects_current() << "\n";

                saveFile << i << "software_ID : " << location->people[i]->get_ID() << "\n";
                saveFile << i << "software_salary_hourly: " << location->people[i]->get_salary_hourly() << "\n";
                saveFile << i << "software-hours_weekly: " << location->people[i]->get_hours_weekly() << "\n";
                for (int j = 0; j < 7; j++){
                    saveFile << i << "software_attendance" << j << ": " << location->people[i]->get_attendance(j) << "\n";
                }
                saveFile << i << "software_date_joined: " << location->people[i]->get_date_joined() << "\n";
                saveFile << i << "software_performance: " << location->people[i]->get_performance() << "\n";
                  

            } else if (strcmp(typeid(*location->people[i]).name(), "8Supplier") == 0){
                saveFile << i << "type: supplier\n";
                saveFile << i << "supplier_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "supplier_ phone_number: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "supplier_name: " << location->people[i]->get_name() << "\n";
                saveFile << i << "supplier_address: " << location->people[i]->get_address() << "\n";
                
                saveFile << i << "supplier_amount_cargo: " << location->people[i]->get_amount_of_cargo() << "\n";
                saveFile << i << "supplier_cost_annually: " << location->people[i]->get_cost_annually() << "\n";
                saveFile << i << "supplier_cargo: " << location->people[i]->get_cargo() << "\n";
                saveFile << i << "supplier_amount_of_cargo: " << location->people[i]->get_amount_of_cargo() << "\n";
                
            
            } else if (strcmp(typeid(*location->people[i]).name(), "3VIP") == 0){
                saveFile << i << "type: VIP\n";
                saveFile << i << "VIP_referrals: " << location->people[i]->get_referrals() << "\n";
                saveFile << i << "VIP_age: " << location->people[i]->get_age() << "\n";
                saveFile << i << "VIP_phone: " << location->people[i]->get_phone() << "\n";
                saveFile << i << "VIP_name: " << location->people[i]->get_name() << "\n";
                saveFile << i << "VIP_address: " << location->people[i]->get_address() << "\n";
                saveFile << i << "VIP_bank_number: " << location->people[i]->get_bankAccount() << "\n";
                saveFile << i << "VIP_spendings: " << location->people[i]->get_spendings() << "\n";
                saveFile << i << "VIP_clientId: " << location->people[i]->get_clientId() << "\n";
                saveFile << i << "VIP_bank: " << location->people[i]->get_bank() << "\n";
                saveFile << i << "VIP_purchase_history: " << location->people[i]->get_purchase_history() << "\n";
                saveFile << i << "VIP_notes: " << location->people[i]->get_notes() << "\n";
                
            }
        } 

    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

//Load data
void Load(Location *location, std::string file){
    std::ifstream saveFile(file);
    std::string line;

    if (saveFile.is_open()){
        std::cout << "Check1" << endl;
        std::string address;
        int curr_size;
        int counter;

        std::getline(saveFile, line);
        address = line.substr(line.find(": ") + 2);
        location->set_address(address);

        std::getline(saveFile, line);
        curr_size = std::stoi(line.substr(line.find(": ") + 2));

        std::getline(saveFile, line);
        curr_size = std::stoi(line.substr(line.find(": ") + 2));

        for (int i = 0; i < curr_size; i ++){
            std::getline(saveFile, line);
            std::string type = line.substr(line.find("type: ") + 6);
            //cout << line.substr(line.find("type: ") + 6) << endl;

            if (type == "customer"){
                Customer *customer = new Customer();
                for (int k = 0; k < 10; k++) {
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);

                    if (line.find(std::to_string(i) + "customer_age") != std::string::npos){
                        customer->set_age(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "customer_phone") != std::string::npos){
                        customer->set_phone(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "customer_name") != std::string::npos){
                        customer->set_name(value);
                    } else if (line.find(std::to_string(i) + "customer_address") != std::string::npos){
                        customer->set_address(value);
                    } else if (line.find(std::to_string(i) + "customer_bank_number") != std::string::npos){
                        customer->set_bankAccount(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "customer_spendings") != std::string::npos){
                        customer->set_spendings(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "customer_clientId") != std::string::npos){
                        customer->set_ID(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "customer_bank") != std::string::npos){
                        customer->set_bank(value);
                    } else if (line.find(std::to_string(i) + "customer_purchase_history") != std::string::npos){
                        customer->set_purchase_history(value);
                    } else if (line.find(std::to_string(i) + "customer_notes") != std::string::npos){
                        customer->set_notes(value);
                    } 
                }
                location->addPerson(customer);
                
            } else if (type == "design") {
                Design *design = new Design();
                for (int k = 0; k < 13; k++) {
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);

                    if (line.find(std::to_string(i) + "design_age") != std::string::npos){
                        design->set_age(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "design_phone") != std::string::npos){
                        design->set_phone(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "design_name") != std::string::npos){
                        design->set_name(value);
                    } else if (line.find(std::to_string(i) + "design_address") != std::string::npos){
                        design->set_address(value);
                    } else if (line.find(std::to_string(i) + "design_ID") != std::string::npos){
                        design->set_ID(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "design_salary_hourly") != std::string::npos){
                        design->set_salary_hourly(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "design_hours_weekly") != std::string::npos){
                        design->set_hours_weekly(std::stoi(value));
                    } for (int j = 0; j < 7; j++){
                        if (line.find(std::to_string(i) + "design_attendance" + std::to_string(j)) != std::string::npos){
                                design->set_attendance(std::stoi(value), j);
                            }
                    } if (line.find(std::to_string(i) + "design_date_joined") != std::string::npos){
                        design->set_date_joined(value);
                    } else if (line.find(std::to_string(i) + "performance") != std::string::npos){
                        design->set_performance(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "design_position") != std::string::npos){
                        design->set_position(value);
                    } else if (line.find(std::to_string(i) + "design_finsihed") != std::string::npos){
                        design->set_finished(value);
                    } else if (line.find(std::to_string(i) + "design_current") != std::string::npos){
                        design->set_design_current(value);
                    }
                }
                location->addPerson(design);
                
            } else if (type == "finances") {
                Finances *finances = new Finances();
                for (int k = 0; k < 15; k++) {
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);

                    if (line.find(std::to_string(i) + "finances_age") != std::string::npos){
                        finances->set_age(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "finances_phone") != std::string::npos){
                        finances->set_phone(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "finances_name") != std::string::npos){
                        finances->set_name(value);
                    } else if (line.find(std::to_string(i) + "finances_address") != std::string::npos){
                        finances->set_address(value);
                    } else if (line.find(std::to_string(i) + "finances_ID") != std::string::npos){
                        finances->set_ID(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "finances_salary_hourly") != std::string::npos){
                        finances->set_salary_hourly(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "finances_hours_weekly") != std::string::npos){
                        finances->set_hours_weekly(std::stoi(value));
                    } for (int j = 0; j < 7; j++){
                        if (line.find(std::to_string(i) + "finances_attendance" + std::to_string(j)) != std::string::npos){
                                finances->set_attendance(std::stoi(value), j);
                            }
                    } if (line.find(std::to_string(i) + "finances_date_joined") != std::string::npos){
                        finances->set_date_joined(value);
                    } else if (line.find(std::to_string(i) + "finances_performance") != std::string::npos){
                        finances->set_performance(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "finances_position") != std::string::npos){
                        finances->set_position(value);
                    } else if (line.find(std::to_string(i) + "finances_turnover") != std::string::npos){
                        finances->set_turnover(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "finances_profit") != std::string::npos){
                        finances->set_profit(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "finances_budget") != std::string::npos){
                        finances->set_budget(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "finances_expense") != std::string::npos){
                        finances->set_expense(std::stoi(value));
                    }
                }
                location->addPerson(finances);
            } else if (type == "humanresources") {
                HumanResources *humanResources = new HumanResources();
                for (int k = 0; k < 15; k++) {
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);

                    if (line.find(std::to_string(i) + "humanResources_age") != std::string::npos){
                        humanResources->set_age(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "humanResources_phone") != std::string::npos){
                        humanResources->set_phone(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "humanResources_name") != std::string::npos){
                        humanResources->set_name(value);
                    } else if (line.find(std::to_string(i) + "humanResources_address") != std::string::npos){
                        humanResources->set_address(value);
                    } else if (line.find(std::to_string(i) + "humanResources_ID") != std::string::npos){
                        humanResources->set_ID(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "humanResources_salary_hourly") != std::string::npos){
                        humanResources->set_salary_hourly(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "humanResources_hours_weekly") != std::string::npos){
                        humanResources->set_hours_weekly(std::stoi(value));
                    } for (int j = 0; j < 7; j++){
                        if (line.find(std::to_string(i) + "humanResources_attendance" + std::to_string(j)) != std::string::npos){
                                humanResources->set_attendance(std::stoi(value), j);
                            }
                    } if (line.find(std::to_string(i) + "humanResources_date_joined") != std::string::npos){
                        humanResources->set_date_joined(value);
                    } else if (line.find(std::to_string(i) + "humanResources_performance") != std::string::npos){
                        humanResources->set_performance(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "humanResources_position") != std::string::npos){
                        humanResources->set_position(value);
                    } else if (line.find(std::to_string(i) + "humanResources_no_trained") != std::string::npos){
                        humanResources->set_trained(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "humanResources_no_hired") != std::string::npos){
                        humanResources->set_hired(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "humanResources_no_fired") != std::string::npos){
                        humanResources->set_fired(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "humanResources_no_retired") != std::string::npos){
                        humanResources->set_retired(std::stoi(value));
                    } 
                }
                location->addPerson(humanResources);
                
            } else if (type == "investor") {
                Investor *investor = new Investor();
                    for (int k = 0; k < 6 ; k++) {
                        std::getline(saveFile, line);
                        std::string value = line.substr(line.find(": ") + 2);       
                        if (line.find(std::to_string(i) + "investor_age") != std::string::npos){
                            investor->set_age(std::stoi(value));
                        } else if (line.find(std::to_string(i) + "investor_phone") != std::string::npos){
                            investor->set_phone(std::stoi(value));
                        } else if (line.find(std::to_string(i) + "investor_name") != std::string::npos){
                            investor->set_name(value);
                        } else if (line.find(std::to_string(i) + "investor_address") != std::string::npos){
                            investor->set_address(value);
                        } else if (line.find(std::to_string(i) + "investor_amount_of_investment") != std::string::npos){
                            investor->set_amount_of_investment(std::stoi(value));
                        }
                    }
                    
                location->addPerson(investor);

            } else if (type == "manager") {
                Manager *manager = new Manager();
                for (int k = 0; k < 13; k++) {
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);

                    if (line.find(std::to_string(i) + "manager_age") != std::string::npos){
                        manager->set_age(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "manager_phone") != std::string::npos){
                        manager->set_phone(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "manager_name") != std::string::npos){
                        manager->set_name(value);
                    } else if (line.find(std::to_string(i) + "manager_address") != std::string::npos){
                        manager->set_address(value);
                    } else if (line.find(std::to_string(i) + "manager_ID") != std::string::npos){
                        manager->set_ID(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "manager_salary_hourly") != std::string::npos){
                        manager->set_salary_hourly(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "manager_hours_weekly") != std::string::npos){
                        manager->set_hours_weekly(std::stoi(value));
                    } for (int j = 0; j < 7; j++){
                        if (line.find(std::to_string(i) + "manager_attendance" + std::to_string(j)) != std::string::npos){
                                manager->set_attendance(std::stoi(value), j);
                            }
                    } if (line.find(std::to_string(i) + "manager_date_joined") != std::string::npos){
                        manager->set_date_joined(value);
                    } else if (line.find(std::to_string(i) + "manager_performance") != std::string::npos){
                        manager->set_performance(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "manager_position") != std::string::npos){
                        manager->set_position(value);
                    } else if (line.find(std::to_string(i) + "manager_password") != std::string::npos){
                        manager->set_password(value);
                    }
                }
                location->addPerson(manager);  

            } else if (type == "manufacturing") {
               Manufacturing *manufacturing = new Manufacturing();
               for (int k = 0; k < 13; k++) {
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);
                    
                    if (line.find(std::to_string(i) + "manufacturing_age") != std::string::npos){
                        manufacturing->set_age(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "manufacturing_phone") != std::string::npos){
                        manufacturing->set_phone(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "manufacturing_name") != std::string::npos){
                        manufacturing->set_name(value);
                    } else if (line.find(std::to_string(i) + "manufacturing_address") != std::string::npos){
                        manufacturing->set_address(value);
                    } else if (line.find(std::to_string(i) + "manufacturing_ID") != std::string::npos){
                        manufacturing->set_ID(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "manufacturing_salary_hourly") != std::string::npos){
                        manufacturing->set_salary_hourly(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "manufacturing_hours_weekly") != std::string::npos){
                        manufacturing->set_hours_weekly(std::stoi(value));
                    } for (int j = 0; j < 7; j++){
                        if (line.find(std::to_string(i) + "manufacturing_attendance" + std::to_string(j)) != std::string::npos){
                                manufacturing->set_attendance(std::stoi(value), j);
                            }
                    } if (line.find(std::to_string(i) + "manufacturing_date_joined") != std::string::npos){
                        manufacturing->set_date_joined(value);
                    } else if (line.find(std::to_string(i) + "performance") != std::string::npos){
                        manufacturing->set_performance(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "position ") != std::string::npos){
                        manufacturing->set_position(value);
                    } else if (line.find(std::to_string(i) + "certification ") != std::string::npos){
                        manufacturing->set_certification(value);   
                    } else if (line.find(std::to_string(i) + "cars_complete ") != std::string::npos){
                        manufacturing->set_cars_complete(std::stoi(value));   
                    }
                }
                location->addPerson(manufacturing);    

            } else if (type == "researchDev") {
                ResearchDev *researchDev = new ResearchDev();
                for (int k = 0; k < 14; k++){
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);
                    
                    if (line.find(std::to_string(i) + "researchDev_age") != std::string::npos){
                        researchDev->set_age(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "researchDev_phone") != std::string::npos){
                        researchDev->set_phone(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "researchDev_name") != std::string::npos){
                        researchDev->set_name(value);
                    } else if (line.find(std::to_string(i) + "researchDev_address") != std::string::npos){
                        researchDev->set_address(value);
                    } else if (line.find(std::to_string(i) + "researchDev_ID") != std::string::npos){
                        researchDev->set_ID(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "researchDev_salary_hourly") != std::string::npos){
                        researchDev->set_salary_hourly(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "researchDev_hours_weekly") != std::string::npos){
                        researchDev->set_hours_weekly(std::stoi(value));
                    } for (int j = 0; j < 7; j++){
                        if (line.find(std::to_string(i) + "researchDev_attendance" + std::to_string(j)) != std::string::npos){
                                researchDev->set_attendance(std::stoi(value), j);
                            }
                    } if (line.find(std::to_string(i) + "researchDev_date_joined") != std::string::npos){
                        researchDev->set_date_joined(value);
                    } else if (line.find(std::to_string(i) + "performance") != std::string::npos){
                        researchDev->set_performance(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "position ") != std::string::npos){
                        researchDev->set_position(value);
                    } else if (line.find(std::to_string(i) + "finished_research ") != std::string::npos){
                        researchDev->set_finished(value);   
                    } else if (line.find(std::to_string(i) + "current research ") != std::string::npos){
                        researchDev->set_research(value);   
                    } else if (line.find(std::to_string(i) + "expertise ") != std::string::npos){
                        researchDev->set_expertise(value);             
                    }
                }
                location->addPerson(researchDev);      

            } else if (type == "marketing") {
                Marketing *marketing = new Marketing();
                for (int k = 0; k < 13; k++) {
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);
                    if (line.find(std::to_string(i) + "marketing_age") != std::string::npos){
                        marketing->set_age(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "marketing_phone") != std::string::npos){
                        marketing->set_phone(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "marketing_name") != std::string::npos){
                        marketing->set_name(value);
                    } else if (line.find(std::to_string(i) + "marketing_address") != std::string::npos){
                        marketing->set_address(value);
                    } else if (line.find(std::to_string(i) + "marketing_ID") != std::string::npos){
                        marketing->set_ID(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "rmarketing_salary_hourly") != std::string::npos){
                        marketing->set_salary_hourly(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "marketing_hours_weekly") != std::string::npos){
                        marketing->set_hours_weekly(std::stoi(value));
                    } for (int j = 0; j < 7; j++){
                        if (line.find(std::to_string(i) + "marketing_attendance" + std::to_string(j)) != std::string::npos){
                                marketing->set_attendance(std::stoi(value), j);
                            }
                    } if (line.find(std::to_string(i) + "marketing_date_joined") != std::string::npos){
                        marketing->set_date_joined(value);
                    } else if (line.find(std::to_string(i) + "performance") != std::string::npos){
                        marketing->set_performance(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "position ") != std::string::npos){
                        marketing->set_position(value);
                    } else if (line.find(std::to_string(i) + "success ") != std::string::npos){
                        marketing->set_success_rate(std::stoi(value));
                    }
                }
                location->addPerson(marketing);
            } else if (type == "sales") {
                 Sales *sales = new Sales();
                 for (int k = 0; k < 14; k++) {
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);
                    if (line.find(std::to_string(i) + "sales_age") != std::string::npos){
                        sales->set_age(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "sales_phone") != std::string::npos){
                        sales->set_phone(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "sales_name") != std::string::npos){
                        sales->set_name(value);
                    } else if (line.find(std::to_string(i) + "sales_address") != std::string::npos){
                        sales->set_address(value);
                    } else if (line.find(std::to_string(i) + "sales_ID") != std::string::npos){
                        sales->set_ID(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "sales_salary_hourly") != std::string::npos){
                        sales->set_salary_hourly(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "sales_hours_weekly") != std::string::npos){
                        sales->set_hours_weekly(std::stoi(value));
                    } for (int j = 0; j < 7; j++){
                        if (line.find(std::to_string(i) + "sales_attendance" + std::to_string(j)) != std::string::npos){
                                sales->set_attendance(std::stoi(value), j);
                            }
                    } if (line.find(std::to_string(i) + "sales_date_joined") != std::string::npos){
                        sales->set_date_joined(value);
                    } else if (line.find(std::to_string(i) + "performance") != std::string::npos){
                        sales->set_performance(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "position ") != std::string::npos){
                        sales->set_position(value);
                    } else if (line.find(std::to_string(i) + " conversation rate ") != std::string::npos){
                        sales->set_conversion_rate(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "add cars sold ") != std::string::npos){
                        sales->set_cars_sold(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "add revenue ") != std::string::npos){
                        sales->set_revenue(std::stoi(value));
                    }
                }
                location->addPerson(sales);
            } else if (type == "software") {
                Software *software = new Software();
                //for (int k = 0; k < 13; k++){
                    std::getline(saveFile, line);
                    software->set_age(std::stoi(line.substr(line.find(": ") + 2)));
                    
                    std::getline(saveFile, line);
                    software->set_phone(std::stoi(line.substr(line.find(": ") + 2)));
                    
                    std::getline(saveFile, line);
                    software->set_name((line.substr(line.find(": ") + 2)));
                    // } if (line.find(std::to_string(i) + "software_phone") != std::string::npos){
                    //     software->set_phone(std::stoi(value));
                    // } else if (line.find(std::to_string(i) + "software_name") != std::string::npos){
                    //     software->set_name(value);
                    // } else if (line.find(std::to_string(i) + "software_address") != std::string::npos){
                    //     software->set_address(value);
                    // } else if (line.find(std::to_string(i) + "software_ID") != std::string::npos){
                    //     software->set_ID(std::stoi(value));
                    // } else if (line.find(std::to_string(i) + "software_salary_hourly") != std::string::npos){
                    //     software->set_salary_hourly(std::stoi(value));
                    // } else if (line.find(std::to_string(i) + "software_hours_weekly") != std::string::npos){
                    //     software->set_hours_weekly(std::stoi(value));
                    // } for (int j = 0; j < 7; j++){
                    //     if (line.find(std::to_string(i) + "software_attendance" + std::to_string(j)) != std::string::npos){
                    //             software->set_attendance(std::stoi(value), j);
                    //         }
                    // } if (line.find(std::to_string(i) + "software_date_joined") != std::string::npos){
                    //     software->set_date_joined(value);
                    // } else if (line.find(std::to_string(i) + "performance") != std::string::npos){
                    //     software->set_performance(std::stoi(value));
                    // } else if (line.find(std::to_string(i) + "position ") != std::string::npos){
                    //     software->set_position(value);
                    // } else if (line.find(std::to_string(i) + " languages ") != std::string::npos){
                    //     software->set_language(value);                   
                    // location->addPerson(software);
                    // } else if (line.find(std::to_string(i) + " projects_finished ") != std::string::npos){
                    //     software->set_finished(value);
                    // } else if (line.find(std::to_string(i) + " projects_current ") != std::string::npos){
                    //     software->set_projects_current(value);                         
                    // }
                //}
                location->addPerson(software);

            } else if (type == "supplier") {
   
                Supplier *supplier = new Supplier();
                for (int k = 0; k < 7; k++){
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);

                    if (line.find(std::to_string(i) + "supplier_age") != std::string::npos){
                        supplier->set_age(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "supplier_phone") != std::string::npos){
                        supplier->set_phone(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "supplier_name") != std::string::npos){
                        supplier->set_name(value);
                    } else if (line.find(std::to_string(i) + "supplier_address") != std::string::npos){
                        supplier->set_address(value);
                    } else if (line.find(std::to_string(i) + "supplier_amountCargo") != std::string::npos){
                        supplier->set_amount_of_cargo(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "supplier_costAnnually") != std::string::npos){
                        supplier->set_cost_annually(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "supplier_cargo") != std::string::npos){
                        supplier->set_cargo(value);
                    }  
                } 

                location->addPerson(supplier);
            } else if (type == "VIP") {
                VIP *vip = new VIP();
                for (int k = 0; k < 5; k++){
                    std::cout << "Check2" << endl;
                    std::getline(saveFile, line);
                    std::string value = line.substr(line.find(": ") + 2);

                    if (line.find(std::to_string(i) + "design_age") != std::string::npos){
                        vip-> set_bankAccount(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "design_phone") != std::string::npos){
                        vip->set_bank(value);
                    } else if (line.find(std::to_string(i) + "design_name") != std::string::npos){
                        vip->set_purchase_history(value);
                    } else if (line.find(std::to_string(i) + "design_address") != std::string::npos){
                        vip->set_spendings(std::stoi(value));
                    } else if (line.find(std::to_string(i) + "design_ID") != std::string::npos){
                        vip->set_notes(value);
                    } 
                }
                
                location->addPerson(vip);

            } else {
                std::cerr << "Unable to open file for loading." << std::endl;
            }
        }
        std::cout << "Check3" << endl;
    }
    
}

