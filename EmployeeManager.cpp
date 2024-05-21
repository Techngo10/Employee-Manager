#include "Functions.h"
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

// intorduction screen asking for user to input load file/create new - must setup a manager to use password
// password screen
// help command
// need to setup reading user input
// need to create commands, lets start with get info commands and set info
 
int main(){

    //system("clear");
    std::cout << "        BBBBBBq  BBBBBBE    BBBBBBBQ     BBQBi  BQBB     BBBBQBBi     iBBBBBBBBi    BQBQBBBBb\n"
                 "        BBQBBBB  BBBBBBP    QBBBBBBB     BBBBB  BBBB    iBBBQBBB2    rQBBBQQBBBBi   BBBBQBQBZ\n"
                 "        BBBBBBB iBBBBBB5    BBBBBQBB     QBBBB  BBBQ    IBBBBBBBB    BBBBB  BQBBB   BBBBBrrLi\n"
                 "        BBQBBBQ vBBBBBBS   rBBBZUBBBi    BBBBBE BBBB    QBBBYQBBB    BBBBB  BBBBB   BBBBB\n"
                 "        BBBBgBBiqBQMBBB2   SBBB7iBBQX    BBBBQB BBBB    BBBB bBBB    BBBBQ  7iir7   BBBBB\n"
                 "        BBBB7BBgBB2PBBQS   BBBBi BBBB    BBBBBQQQBBB    BBQB KBBBv   BBBQB          BBBBBBBBi\n"
                 "        BBBBigBBBBr5BBBI   BBBB  BBBB    BBQBBBBBBBB   iBQBQ 7BBBD   BBBBB BBQBBB   BBBBBBBB7\n"
                 "        BBBB 5QBBB KQBB5   BBBB  BBBQi   BBBD1BBBBBB   SBBBd iBBBB   BBBBB sQBBBB   QBBBBi i\n"
                 "        BQBQ iBBBB PBBBI  rBBQBQBBBQBJ   BBBQ BBBQBB   BBBBBBBBBBB   BBBBB  BBBBB   BBBBB\n"
                 "        BBBB  BBQB gBBB5  PBBBBBBBBBBB   BBBB 5BBBQB   BQBBBBBQBBBi  BBBBB  BBBBB   BBBBB\n"
                 "        BBBB  BBBg MBQBI  BBBBBi QBBBB   BBBB  QBQBB   BBBBQ iBBBBP  bBBBBi BBBBB   BQBBBBBBB\n"
                 "        BBBBi QBBX BQBQg  QBBBQ  BQBBBi  BBBB  BBBBB  jBBBBZ  BBQBB   QBBBBBBBBBB   QBBBBBBBB\n"
                 "        gPPZ  1bZi udqZr  RqqqK  rEKPDi  DPPE  iEKPg  vEPKEi  dqqPR    rQBBR  PPq   qPqXKKPbP\n\n"
                 "                             Code By: Victor, Elijah, and Kurt\n\n\n\n";
    std::string input;
    std::cout << "Do you want to load a file or start new or exit (l/n/e) : ";
    std::cin >> input;
    
    while (input != "n" && input != "l" && input != "e") {
        std::cout << "Please enter l, n, or e";
        std::cin >> input;
    }

    if (input == "e"){
        //system("clear");
        std::cout << "Program shutting down.\n";
        return 0;
    }

    if (input == "l"){
        std::cout << "Loading your location.\n";
        std::string fileName;
        Location location;
        std::cout << "Please enter your file name: ";
        std::cin >> fileName;
        if (fileName == "e"){
            system("clear");
            std::cout << "Program shutting down.\n";
            return 0;
        }
        while (fileExists(fileName) != true){
            std::cout << "Please enter correct file name: ";
            std::cin >> fileName;
            if (fileName == "e"){
                system("clear");
                std::cout << "Program shutting down.\n";
                return 0;
            }
        }

        bool loaded = false;

        for (int i = 0; i < 5; i++){
            if (!Load(&location,  fileName)){
                std::cout << "Error loading file, either change your file or choose the correct name.\n";
                std::cout<<"You have "<< 4-i << " chances left.\n";
                std::cout << "Please enter your file name: ";
                std::cin >> fileName;
                if (fileName == "e"){
                    system("clear");
                    std::cout << "Program shutting down.\n";
                    return 0;
                }
            } else {loaded = true; break;}
        }

        if (!loaded){
            system("clear");
            std::cout << "Please go back and check your load file is correct.\n";
            return 0;
        } 
        
        std::cout << "File succesfully loaded\n";

        std::cout << "Enter (help) for more commands or enter command:";
        std::cin >> input;
        /////////////////////////////////////////////////
        std::string username;
        cout << "enter your name: " << std::endl;
        cin >> username;
        std::string  password;
        cout << "enter your password: " << std::endl;
        cin >> password;
        if(Access(&location, username, password) == 0){
            std::cout << "Sorry, you can't access. Only manager can log in.\n";
            for(int j = 5 ; j > 0 ; j--){
                std::cout << "you have "<<j<<"chances left.\n";
                std::cout << "Enter the password again: "<< std::endl;
                std::cin >> password;
                 if(Access(&location, username, password) == 1){
                    std::cout <<"Welcome back!\n";
                    break;
                 }
                 system("clear");
                    std::cout << "Program shutting down.\n";
                    return 0;
            }
        } else{
            std::cout <<"Welcome back!\n";
            //break;
        }
        ///////////////////////////////////////////////
    }

    if (input == "n"){
        std::cout << "Create a new Location."<< std :: endl;
        Location location;

        int managerAge = 0; int managerPhone = 0; float managerSalary = 0; float managerHours = 0;
        std::string manager_dateJoined = "none";  std::string managerPosition = "none";
        std::string managerName = "none"; std::string managerAddress = "none";
        std::string managerPassword = "none";
        
        std::cout << "Enter Manager's name: "; std::cin >> managerName;
        std::cout << "Enter Manager's age: "; std::cin >> managerAge;
        std::cout << "Enter Manager's phone: "; std::cin >> managerPhone;
        std::cout << "Enter Manager's salary hourly: "; std::cin >> managerSalary;
        std::cout << "Enter Manager's working hours: "; std::cin >> managerHours;
        std::cout << "Enter Manager's date joined: "; std::cin >> manager_dateJoined;
        std::cout << "Enter Manager's address: "; std::cin >> managerAddress;
        std::cout << "Enter Manager's password: "; std::cin >> managerPassword;
        std::cout << "Enter Manager's position: "; std::cin >> managerPosition;
 
        Manager *manager = new Manager(managerSalary, managerHours, manager_dateJoined, managerAge, managerPhone, managerName, managerAddress, managerPassword, managerPosition);
        location.addPerson(manager);


        runCommand(&location, "set password Kurt");

        // std::string newFileName;
        // std::cout << "Enter the new filename: ";
        // std::cin >> newFileName;

        // Save(&location, newFileName);

        std::cout << "New location created and saved successfully.\n";

        
    }   
    
    return 0;
}