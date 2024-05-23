//#include "Functions.h"
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

 
int main(){

    Location location;

    location.clear();
    std::string input;
    std::cout << "Do you want to load a file or start new or exit (l/n/e) : ";
    std::getline(std::cin, input);
    
    while (input != "n" && input != "l" && input != "e") {
        std::cout << "Please enter l, n, or e: ";
        std::getline(std::cin, input);
    }

    if (input == "e"){
        location.clear();
        std::cout << "Program shutting down.\n";
        return 0;
    }

    if (input == "l"){
        std::cout << "Loading your location.\n";
        std::string fileName;
        std::cout << "Please enter your file name: ";
        std::getline(std::cin, fileName);
        if (fileName == "e"){
            location.clear();
            std::cout << "Program shutting down.\n";
            return 0;
        }
        while (location.fileExists(fileName) != true){
            std::cout << "Please enter correct file name: ";
            std::getline(std::cin, fileName);
            if (fileName == "e"){
                location.clear();
                std::cout << "Program shutting down.\n";
                return 0;
            }
        }

        bool loaded = false;

        for (int i = 0; i < 5; i++){
            if (!location.Load(fileName)){
                std::cout << "Error loading file, either change your file or choose the correct name.\n";
                std::cout<<"You have "<< 4-i << " chances left.\n";
                std::cout << "Please enter your file name: ";
                std::getline(std::cin, fileName);
                if (fileName == "e"){
                    location.clear();
                    std::cout << "Program shutting down.\n";
                    return 0;
                }
            } else {loaded = true; break;}
        }

        if (!loaded){
            location.clear();
            std::cout << "Please go back and check your load file is correct.\n";
            return 0;
        } 

        location.clear();
        
        std::cout << "File succesfully loaded\n";

        /////////////////////////////////////////////////
        std::string username;
        std::string password;

        std::cin.ignore(); // location.clear newline left in buffer from previous std::cin

        for (int attempts = 5; attempts > 0; attempts--) {
            std::cout << "Username: ";
            std::getline(std::cin, username);

            std::cout << "Password: ";
            std::getline(std::cin, password);

            if (location.Access(username, password)) {
                location.clear();
                std::cout << "Welcome back!\n";
                break;
            } else {
                location.clear();
                std::cout << "Sorry, you can't access. Only manager and administrator can log in.\n";
                if (attempts > 1) {
                    std::cout << "You have " << attempts - 1 << " chances left.\n";
                }
                if (attempts == 1){
                    location.clear();
                    std::cout << "Program shutting down.\n";
                    return 0;
                }
            }
        }
        std::string n_input = "";

        while(n_input != "e"){
            std::getline(std::cin, n_input);
            location.clear();
            location.runCommand(n_input);
        }

        std::string save;
        do {
        std::cout << "Do you want to save (y/n): ";
        std::cin >> save;
        } while (save != "y" && save != "n");

        if (save == "y") {
            location.runCommand("save");
        }
        std::cout << "Program shutting down.\n";
        return 0;
    }
    ///////////////////////////////////////////////

    if (input == "n"){
        std::string n_input = "";
        std::cout << "\nCreateing a new Location.\n"<< std::endl;

        std::cout << "Please enter the address of the location: ";


        std::getline(std::cin, n_input);
        location.set_address(n_input);

        location.clear();

        std::cout << "You must now initialise a manager.\n"<< std::endl;

        std::cout << "Enter the manager's name: ";
        std::getline(std::cin, n_input);

        location.runCommand("add Manager");
        location.people[0]->set_name(n_input);

        location.clear();

        while(n_input != "e"){
            std::getline(std::cin, n_input);
            location.clear();
            location.runCommand(n_input);
        }
 
        std::string save;
        do {
        std::cout << "Do you want to save (y/n): ";
        std::cin >> save;
        } while (save != "y" && save != "n");

        if (save == "y") {
            location.runCommand("save");
        }
        // if (save == "n") {
        //     std::cout << "Are you sure? (y/n)";
        // }
        std::cout << "Program shutting down.\n";
        return 0;
        
    }   
    
    return 0;
}