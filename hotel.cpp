//============================================================================
// Name         : Hotel Finder
// Author       : Jackson Mukeshimana
// Version      : 1.0
// Date Created : 25-11-2023
// Date Modified: 12-12-2023 
// Description  : Hotel Finder Application Program
//============================================================================

#include "hotel.hpp"

// Constructor
Hotel::Hotel(string name, string city, string stars, string price, string country, string address) 
    : name(name), city(city), stars(stars), price(price), country(country), address(address) {}

// Accessor methods
string Hotel::getName() {
    return name;
}

string Hotel::getCity() {
    return city;
}

string Hotel::getStars() {
    return stars;
}

string Hotel::getPrice() {
    return price;
}

string Hotel::getCountry() {
    return country;
}

string Hotel::getAddress() {
    return address;
}

// Converts hotel information to a string
string Hotel::toString() {
    return name + ", " + city + ", " + stars + " stars, " + price + " per night, " + country + ", " + address;
}

// Prints the hotel information to the console
void Hotel::print() {
    cout << toString() << endl;
}

// Alternative print method (customize as needed)
void Hotel::print2() {
    cout << "Hotel: " << name << " | City: " << city << " | Stars: " << stars << " | Price: " << price << " | Country: " << country << " | Address: " << address << endl;
}
