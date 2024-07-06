//============================================================================
// Name         : Hotel Finder
// Author       : Jackson Mukeshimana
// Version      : 1.0
// Date Created : 25-11-2023
// Date Modified: 12-12-2023 
// Description  : Hotel Finder Application Program
//============================================================================

#include "hashtable.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

    // Trim leading and trailing spaces from a string
    string trim(const string& str) {
        size_t first = str.find_first_not_of(' ');
        if (string::npos == first) {
            return str;
        }
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }

    // Convert a string to a Hotel object
    Hotel* stringToHotel(const string& details) {
        stringstream sstr(details);
        string name, city, stars, price, country, address;

        getline(sstr, name, ',');
        getline(sstr, city, ',');
        getline(sstr, stars, ',');
        getline(sstr, price, ',');
        getline(sstr, country, ',');
        getline(sstr, address);

        return new Hotel(name, city, stars, price, country, address);
    }

    // Display the list of available commands
    void listCommands() {
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "List of Commands:" << endl;
        cout << "insert <Hotel Details> : Add a new record (format: HotelName,CityName,Stars,Price,CountryName,Address)" << endl;
        cout << "find <HotelName,CityName> : Find a specific hotel in a given city." << endl;
        cout << "findAll <CityName>[,Stars] : Find all hotels in a city, optionally filtered by stars." << endl;
        cout << "delete <HotelName,CityName> : Delete a specific hotel record." << endl;
        cout << "dump <file> : Dump the content of the database to a file." << endl;
        cout << "exit : Quit the program." << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
    }

    // Main function
    int main(int argc, char** argv) {
        HashTable myHashTable(125033); 

        // Read data from a file and populate the hash table
        if (argc == 3 && strcmp(argv[1], "-f") == 0) {
            ifstream fin(argv[2]);
            if (!fin) {
                cerr << "Cannot open the file: " << argv[2] << endl;
                return EXIT_FAILURE;
            }

            string line;
            getline(fin, line); // Skip the first line
            while (getline(fin, line)) {
                if (!line.empty()) {
                    Hotel* hotel = stringToHotel(line);
                    string key = trim(hotel->getName()) + "," + trim(hotel->getCity());
                    myHashTable.insert(key, hotel);
                }
            }
            fin.close();
        }

        // Display hash table statistics and list of commands
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "Hash Table size = " << myHashTable.getSize() << endl;
        cout << "Total number of collisions = " << myHashTable.getCollisions() << endl;
        cout << "% of collisions = " << (myHashTable.getSize() > 0 ? static_cast<float>(myHashTable.getCollisions()) / myHashTable.getSize() * 100 : 0) << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;

        listCommands();  // Display the list of available commands

        // Process user input
        string user_input;
        while (true) {
            cout << ">";
            getline(cin, user_input);
            stringstream sstr(user_input);
            string command, argument1, argument2;

            getline(sstr, command, ' ');
            getline(sstr, argument1, ',');
            getline(sstr, argument2);

            string hotelName = trim(argument1);
            string cityName = trim(argument2);

            // Execute the appropriate command based on user input
            if (command == "find") {
                Hotel* result = myHashTable.find(hotelName + "," + cityName);
                if (result) {
                    result->print();
                } else {
                    cout << "Hotel not found." << endl;
                }
            } else if (command == "findAll") {
                myHashTable.findAll(hotelName, cityName);
                // No hotels found in the specific City 
            } else if (command == "insert") {
                Hotel* existingHotel = myHashTable.find(hotelName + "," + cityName);
                if (existingHotel) {
                    cout << "Existing record has been updated" << endl;
                    existingHotel->print();
                } else {
                    Hotel* hotel = stringToHotel(hotelName + "," + cityName);
                    if (hotel) {
                        myHashTable.insert(hotel->getName() + "," + hotel->getCity(), hotel);
                        cout << "Congratulatory message: New record has been added to the Data Base" << endl;
                    }
                }
            } else if (command == "delete") {
                myHashTable.erase(hotelName + "," + cityName);
            } else if (command == "dump") {
                myHashTable.dump(hotelName);
            } else if (command == "exit") {
                break;
            } else if (command == "help") {
                listCommands();
            } else {
                cout << "Invalid command!" << endl;
            }
        }

        return 0;
    }
