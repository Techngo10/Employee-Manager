#include "Location.h"

#include <iostream>

#include "Software.h"
#include "Finances.h"
#include "Design.h"
#include "Manufacturing.h"
#include "HumanResources.h"
#include "ResearchDev.h"
#include "Sales.h"
#include "Marketing.h"

int main() {
  // Create a location
  Location location("123 Main St");

  // Add some people
  Person person1(25, 123456789, "Alice", "123 Main St");
  Person person2(30, 987654321, "Bob", "456 Elm St");
  Person person3(35, 555555555, "Charlie", "789 Oak St");
  Software software1(20, 40, "17th May", 20, 0412312451, "Victor", "city", "Top Programmer");
  Finances finances1(10, 12, "12nd June", 33, 999000, "Peter", "USA", "finacial planner", 9999, 99999, 100000, 200);
  Sales sales1(15, 20, "21 July", 32, 123410, "John", "somewhere", "Sales Junior", 20.22, 50000, 20000);

  location.addPerson(&person1);
  location.addPerson(&person2);
  location.addPerson(&person3);
  location.addPerson(&software1);
  location.addPerson(&finances1);
  location.addPerson(&sales1);

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

  std::cout << "turnover of finances1: "
            << location.people[4]->get_turnover() << std::endl;
  std::cout << "profit of the finances1: "
            << location.people[4]->get_profit() << std::endl;
  std::cout << "budget of the finances1: "
            << location.people[4]->get_budget() << std::endl;
  std::cout << "expense of the finances1: "
            << location.people[4]->get_expense() << std::endl;


  //  Sales
  location.people[5]->set_position("Manager");
  location.people[5]->set_conversion_rate(10.22);
  location.people[5]->add_cars_sold(20);
  location.people[5]->add_revenue(10000);


  return 0;
}