#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    // Open input file for reading
    std::ifstream inFile("test.txt");

    if (!inFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1; // Return error code if file opening fails
    }

    std::map<std::string, std::string> data; // Map to store key-value pairs
    std::string line;

    // Read lines from file into memory
    while (std::getline(inFile, line)) {
        size_t pos = line.find(':');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 2); // Skip ':' and space
            data[key] = value;
        }
    }

    inFile.close(); // Close input file

    // Display current content of the file
    std::cout << "Current content of the file:" << std::endl;
    for (const auto& pair : data) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Ask the user if they want to edit the file
    std::string response;
    std::cout << "Do you want to edit the file? (yes/no): ";
    std::cin >> response;

    if (response == "yes") {
        // Prompt the user to change variables
        std::cout << "Enter the new values. Type 'end' to finish." << std::endl;
        std::string key, value;
        std::cin.ignore(); // Ignore the newline character left in the stream
        while (true) {
            std::cout << "Enter key (or 'end' to finish): ";
            std::getline(std::cin, key);
            if (key == "end") {
                break;
            }
            std::cout << "Enter value for " << key << ": ";
            std::getline(std::cin, value);
            data[key] = value;
        }

        // Open the file again for writing (clears existing content)
        std::ofstream outFile("test.txt");

        if (!outFile.is_open()) {
            std::cerr << "Unable to open the file." << std::endl;
            return 1; // Return error code if file opening fails
        }

        // Write modified content back to the file
        for (const auto& pair : data) {
            outFile << pair.first << ": " << pair.second << std::endl;
        }

        outFile.close(); // Close output file

        std::cout << "File edited successfully." << std::endl;
    } else {
        std::cout << "No changes were made to the file." << std::endl;
    }

    return 0;
}
