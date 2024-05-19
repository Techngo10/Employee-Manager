#include <iostream>
#include <string>
#include "EmployeeManager.h" // Your header file containing employee management logic

int main() {
    EmployeeManager manager; // Create an instance of the employee manager

    manager.displayMenu();

    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "help") {
            manager.displayHelp();
           
        } else if (command == "add") {
            manager.addPerson();

        } else if (command == "remove") {
            

            
        } else if (command == "list") {
           

        } else if (command.substr(0, 6) == "salary") {

            // Parse the employee ID from the command and call the appropriate function
        } else if (command == "quit") {

            // Exit the program
            break;
        } else {
            std::cout << "Invalid command. Type 'help' to see available commands." << std::endl;
        }
    }

    return 0;
}
