#include <iostream>
#include <fstream>
#include <sstream>
#include "Location.h"
#include "Software.h"

// Password checking function
bool Access(Location* location, std::string& perms, const std::string& username, const std::string& password) {
    // Implement password checking logic here
}

// Save data
void Save(Location* location, const std::string& file) {
    std::ofstream saveFile(file);

    if (saveFile.is_open()) {
        saveFile.close();
    } else {
        std::cerr << "Unable to open file for saving." << std::endl;
    }
}

// Load data from the file
void Load(Location* location, const std::string& file) {
    std::ifstream saveFile(file);
    std::string line;

    if (saveFile.is_open()) {
        std::string address;
        int curr_size;

        // Load location information
        std::getline(saveFile, line); // Read location_address
        address = line.substr(line.find(": ") + 2);
        location->set_address(address);

        std::getline(saveFile, line); // Read curr_size
        curr_size = std::stoi(line.substr(line.find(": ") + 2));

        // Load people information
        for (int i = 0; i < curr_size; i++) {
            std::getline(saveFile, line); // Read type line
            std::string type = line.substr(line.find("type: ") + 6);

            if (type == "software") {
                // Read and parse software information directly
                Software* software = new Software();

                // Read and set software attributes
                std::getline(saveFile, line); software->set_age(std::stoi(line.substr(line.find(": ") + 2)));
                std::getline(saveFile, line); software->set_phone(std::stoi(line.substr(line.find(": ") + 2)));
                std::getline(saveFile, line); software->set_name(line.substr(line.find(": ") + 2));
                std::getline(saveFile, line); software->set_address(line.substr(line.find(": ") + 2));
                std::getline(saveFile, line); software->set_ID(std::stoi(line.substr(line.find(": ") + 2)));
                std::getline(saveFile, line); software->set_salary_hourly(std::stoi(line.substr(line.find(": ") + 2)));
                std::getline(saveFile, line); software->set_hours_weekly(std::stoi(line.substr(line.find(": ") + 2)));
                std::getline(saveFile, line);
                for (int j = 0; j < 7; j++) {
                    if (line.find(std::to_string(i) + "software_attendance" + std::to_string(j)) != std::string::npos) {
                        software->set_attendance(std::stoi(line.substr(line.find(": ") + 2)), j);
                    }
                }
                std::getline(saveFile, line); software->set_date_joined(line.substr(line.find(": ") + 2));
                std::getline(saveFile, line); software->set_performance(std::stoi(line.substr(line.find(": ") + 2)));
                std::getline(saveFile, line); software->set_position(line.substr(line.find(": ") + 2));
                std::getline(saveFile, line); software->set_language(line.substr(line.find(": ") + 2));
                std::getline(saveFile, line); software->set_finished(line.substr(line.find(": ") + 2));
                std::getline(saveFile, line); software->set_projects_current(line.substr(line.find(": ") + 2));

                // Add software person to the location
                location->addPerson(software);
            }
        }

        saveFile.close();
    } else {
        std::cerr << "Unable to open file for loading." << std::endl;
    }
}
