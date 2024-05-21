#include <iostream>
#include "Functions.h"
#include "Software.h" // Assuming Software class is used in Access function
#include "Location.h"

int main() {
    // Create a location
    Location location("123 Main St");

    // Add some people
    Software software1(20, 40, "17th May", 20, 0412312451, "Victor", "city", "Top Programmer");
    location.addPerson(&software1);

    // Add another Software person
    Software software2(25, 45, "21st May", 25, 0412312452, "Alice", "town", "Junior Programmer");
    location.addPerson(&software2);

    // Set attributes for software1
    location.people[0]->set_position("Manager");
    location.people[0]->set_language("C++, C");
    location.people[0]->set_finished("project 1");
    location.people[0]->set_projects_current("computer science");

    // Set attributes for software2
    location.people[1]->set_position("Developer");
    location.people[1]->set_language("Java, Python");
    location.people[1]->set_finished("project 2");
    location.people[1]->set_projects_current("web development");

    // Save data to a file
    Save(&location, "savetest.txt");

    // Load data from the file
    Location loadedLocation;
    Load(&loadedLocation, "savetest.txt");

    // Print loaded data
    std::cout << "People loaded from the file:" << std::endl;
    for (int i = 0; i < loadedLocation.get_curr_size(); ++i) {
        std::cout << "Name: " << loadedLocation.people[i]->get_name()
                  << ", Age: " << loadedLocation.people[i]->get_age() << std::endl;
        // Access and print other attributes as needed
    }

    return 0;
}
