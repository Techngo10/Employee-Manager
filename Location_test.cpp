#include "Location.h"

#include <iostream>

#include "Functions.h"
#include "Software.h"
#include "Finances.h"
#include "Design.h"
#include "Manufacturing.h"
#include "HumanResources.h"
#include "ResearchDev.h"
#include "Sales.h"
#include "Marketing.h"
#include "Manager.h"
#include "Supplier.h"
#include "Customer.h"

int main() {
// Create a location
Location location("123 Main St");
 
// Add some people
Software software1(20, 40, "17th May", 20, 0412312451, "Victor", "city", "Top Programmer");
Software software2(2, 40, "17th May", 20, 0412312451, "Victor", "city", "Top Programmer");
Software software3(20, 40, "17th May", 20, 0412312451, "Victor", "city", "Top Programmer");
Software software4(20, 40, "17th May", 20, 0412312451, "Victor", "city", "Top Programmer");
Finances finances1(10, 12, "12nd June", 33, 999000, "Peter", "USA", "finacial planner", 9999, 99999, 100000, 200);
Sales sales1(15, 20, "21 July", 32, 123410, "John", "somewhere", "Sales Junior", 20.22, 50000, 20000); 
Design design1(22, 12, "2nd Dec", 34, 34566543, "Lee", "Mel", "car designer", "wheel design; outlook design", "software system design");
Manufacturing manufacturing1(12, 33, "3rd Nov", 22, 123321, "Jones", "Japan", "engine manufacturer", "United Manufacturing", 89);
HumanResources humanresources1 (31, 33.9, "10th mar", 20, 234432, "Copper", "Germany", "retirement manager");
ResearchDev researchDev1(66, 20, "24ed Jan", 56, 45666, "Jacky", "Henly St", "major researcher", "energy saving", "accurate GPS", "energy");
Marketing marketing1(49.1, 22.12, "12th July", 29, 999000, "Charile", "William St", "South America region manager", 5) ;
Manager manager1(50, 40, "2nd Feb", 29, 041532153, "Kurt", "Hutt Street", "123", "General Manager");
Customer customer1(1, 1, 1, "", "", "", 10, 1, "", "");

string cargos[2] = {"wheel", "engine"};
string* cargos1 = cargos;
Supplier supplier(22, 12345, "Bob Peter", "West Terrace", 2, 120000.4, cargos1);

location.addPerson(&software1);
location.addPerson(&software2);
location.addPerson(&software3);
location.addPerson(&software4);
location.addPerson(&finances1);
location.addPerson(&sales1);
location.addPerson(&design1);
location.addPerson(&manufacturing1);
location.addPerson(&humanresources1);
location.addPerson(&researchDev1);
location.addPerson(&marketing1);
location.addPerson(&manager1);
location.addPerson(&supplier);
location.addPerson(&customer1);

// Print initial people
std::cout << "People in the location:" << std::endl;
for (int i = 0; i < location.get_curr_size(); ++i) {
  std::cout << "Name: " << location.people[i]->get_name()
            << ", Age: " << location.people[i]->get_age() << std::endl;
}

// // Remove a person
// location.rmPerson("Bob");

// // Print remaining people
// std::cout << "\nAfter removing Bob:" << std::endl;
// for (int i = 0; i < location.get_curr_size(); ++i) {
//   std::cout << "Name: " << location.people[i]->get_name()
//             << ", Age: " << location.people[i]->get_age() << std::endl;
// }

// Software functions

location.people[3]->set_position("Manager");
location.people[3]->set_language("C++, C");
location.people[3]->set_finished("project 1");
location.people[3]->set_projects_current("computer science");

std::cout << "Current project of the software1: "
          << location.people[3]->get_position() << std::endl;
std::cout << "Current language of the software1: "
          << location.people[3]->get_languages() << std::endl;
std::cout << "Current projects of the software1: "
          << location.people[3]->get_projects_current() << std::endl;
std::cout << "Current finished projects of the software1: "
          << location.people[3]->get_finished() << std::endl;


  // finances functions

location.people[4] -> set_position("fincial analysist");
location.people[4] -> set_turnover(556677);
location.people[4] -> set_profit(550000);
location.people[4] -> set_budget(100000);
location.people[4] -> set_expense(2000);

location.people[4]->check_turnover_profit(location.people[4]->get_turnover(), location.people[4]->get_profit());

std::cout << "turnover of finances1: " << location.people[4]->get_turnover() << std::endl;
std::cout << "profit of the finances1: " << location.people[4]->get_profit() << std::endl;           
std::cout << "budget of the finances1: " << location.people[4]->get_budget() << std::endl;            
std::cout << "expense of the finances1: " << location.people[4]->get_expense() << std::endl;

//Sales
location.people[5]->set_position("Manager");
location.people[5]->set_conversion_rate(10.22);
location.people[5]->add_cars_sold(20);
location.people[5]->add_revenue(10000);

std::cout << "Sales Position: " << location.people[5]->get_position() << std::endl;
std::cout << "Conversion Rate: " << location.people[5]->get_conversion_rate() << std::endl; 
std::cout << "Cars Sold: " << location.people[5]->get_cars_sold() << std::endl;
std::cout << "Revenue: " << location.people[5]->get_revenue() << std::endl;

//Design
location.people[6]->set_position("motorbike designer");
location.people[6]->set_finished("wheel design; outlook design; software system design") ;
location.people[6]->set_design_current("motorbike color" );

std::cout << location.people[6]->get_position() << std::endl;
std::cout << location.people[6]->get_finished() << std::endl;
std::cout << location.people[6]->get_design_current() << std::endl;


// Manufacturing
location.people[7]->set_position("Top Manufacturer"); 
location.people[7]->add_certification("Metal Work; Welder;");
location.people[7]->add_cars_complete(109);

std::cout <<location.people[7]->get_position() << std::endl;
std::cout << location.people[7]->get_certification() << std::endl;
std::cout << location.people[7]->get_cars_complete()<< std::endl;

//HumanResources
location.people[8]->set_position("applyment manager");
location.people[8]->add_trained(11);
location.people[8]->add_hired(22);
location.people[8]->add_fired(33);
location.people[8]->add_retired(44);
std::cout <<location.people[8]->get_position() << std::endl;
std::cout <<location.people[8]->get_trained() << std::endl;
std::cout <<location.people[8]->get_hired() << std::endl;
std::cout <<location.people[8]->get_fired() << std::endl;
std::cout <<location.people[8]->get_retired() << std::endl;

//ResearchDev
location.people[9]->set_position("research manager");
location.people[9]->add_finished("finished idk");
location.people[9]->set_research(" concistent driving");
location.people[9]->add_expertise("AI driving");
std::cout <<location.people[9]->get_position()<< std::endl;
std::cout <<location.people[9]->get_finished()<< std::endl;
std::cout <<location.people[9]->get_research()<< std::endl;
std::cout <<location.people[9]->get_expertise()<< std::endl;

//marketing
 location.people[10]->set_position("AUS region manager");
 location.people[10]->set_success_rate(2.11);
 std::cout <<location.people[10]->get_position() << std::endl;
 std::cout <<location.people[10]->get_success_rate() << std::endl;


  //Testing access function

  string Permission;

  Access(&location, Permission, "Kurt", "123");
  
  cout << "Permission level: " << Permission << endl;

Save(&location, "savetest.txt");



  return 0;
}