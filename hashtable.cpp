//============================================================================
// Name         : Hotel Finder
// Author       : Jackson Mukeshimana
// Version      : 1.0
// Date Created : 25-11-2023
// Date Modified: 12-12-2023 
// Description  : Hotel Finder Application Program
//============================================================================


// Include the header file for the HashTable class
#include "hashtable.hpp"
// Include the string library for using string data type
#include <string>
// Constructor for the HashTable class
HashTable::HashTable(int capacity) : size(0), capacity(capacity), collisions(0) {
    // Initialize the buckets array with the given capacity
    buckets = new list<Entry>[capacity];
}

// Destructor for the HashTable class
HashTable::~HashTable() {
    // Deallocate the memory for the buckets array
    delete[] buckets;
}

// Function to generate a hash code for the given key
unsigned long HashTable::hashCode(string key) {
    // Initialize the hash value
    unsigned long hash = 0;
    // Initialize the prime number for hashing
    unsigned long prime = 31;
    // Iterate through each character of the key
    for (char c : key) {
        // Update the hash value using the prime number and the character
        hash = (prime * hash) + c;
    }
    // Return the hash code within the capacity range
    return hash % capacity;
}

// Insert a hotel record into the hash table
void HashTable::insert(string key, Hotel* value) {
    // Generate the hash value for the given key
    unsigned long hashValue = hashCode(key);
    // Get the reference to the bucket at the hash value
    auto& bucket = buckets[hashValue];
    // Initialize a flag to track if the key is found
    bool found = false;
    // Iterate through the entries in the bucket
    for (auto& entry : bucket) {
        // Check if the key already exists in the bucket
        if (entry.key == key) {
            // Update the value of the existing record
            entry.value = value;
            // Set the flag to true as the key is found
            found = true;
            // Exit the loop
            break;
        }
    }
    // If the key is not found in the bucket
    if (!found) {
        // Check if the bucket was not empty before the insertion, indicating a collision
        if (!bucket.empty()) {
            // Increment the collision count
            collisions++;
        }
        // Add a new entry to the bucket with the key and value
        bucket.emplace_back(key, value);
        // Increment the size of the hash table
        size++;
        // Insert the hotel record into the BST for city-wise search
        cityRecords.insert(cityRecords.getRoot(), value->getCity(), value);
    }
}

// Find a hotel by its key
Hotel* HashTable::find(string key) {
    // Generate the hash value for the given key
    unsigned long hashValue = hashCode(key);
    // Initialize the comparison count
    int comparisons = 0;
    // Iterate through the entries in the bucket at the hash value
    for (auto& entry : buckets[hashValue]) {
        // Increment the comparison count
        comparisons++;
        // Check if the key matches the entry key
        if (entry.key == key) {
            // Print the record found message with the comparison count
            cout << "Record found after " << comparisons << " comparison(s)" << endl;
            // Print the city name of the hotel
            cout << "City Name: " << entry.value->getCity() << endl;
            // Print the hotel name
            cout << "Hotel Name: " << entry.value->getName() << endl;
            // Print the price of the hotel
            cout << "Price: " << entry.value->getPrice() << endl;
            // Print the country of the hotel
            cout << "Country: " << entry.value->getCountry() << endl;
            // Print the address of the hotel
            cout << "Address: " << entry.value->getAddress() << endl;
            // Return the hotel record
            return entry.value;
        }
    }
    // Return null if the key is not found
    return nullptr;
}

// Find all hotels in a given city
void HashTable::findAll(string city, string stars) {
    // Search for all hotels in the given city using the BST for efficient search
    cityRecords.find(cityRecords.getRoot(), city, stars);
}

// Erase a hotel record by its key
void HashTable::erase(string key) {
    // Generate the hash value for the given key
    unsigned long hashValue = hashCode(key);
    // Get the reference to the bucket at the hash value
    auto& bucket = buckets[hashValue];
    // Initialize an iterator for the bucket
    auto it = bucket.begin();
    // Iterate through the entries in the bucket
    while (it != bucket.end()) {
        // Check if the key matches the entry key
        if (it->key == key) {
            // Erase the entry from the bucket
            bucket.erase(it);
            // Decrement the size of the hash table
            size--;
            // Print the success message for deleting the hotel record
            cout << "Hotel record with key " << key << " has been successfully deleted" << endl;
            // Exit the loop
            return;
        }
        // Move to the next entry in the bucket
        ++it;
    }
    // Print a message if the hotel record is not found
    cout << "Hotel record with key " << key << " was not found" << endl;
}

// Return the size of the hash table
unsigned int HashTable::getSize() {
    // Return the current size of the hash table
    return size;
}

// Return the number of collisions
unsigned int HashTable::getCollisions() {
    // Return the count of collisions
    return collisions; // This needs to be updated in insert method to reflect actual collisions
}

// Dump the hash table content to a file
void HashTable::dump(string path) {
    // Open a file stream with the given file path
    ofstream file(path);
    // Check if the file is successfully opened
    if (file.is_open()) {
        // Iterate through each bucket in the hash table
        for (unsigned int i = 0; i < capacity; ++i) {
            // Iterate through the entries in the bucket
            for (auto& entry : buckets[i]) {
                // Write the hotel record to the file
                file << entry.value->toString() << endl;
            }
        }
        // Close the file stream
        file.close();
        // Print the success message for dumping the hash table content
        cout << "Hash table content has been successfully dumped to " << path << endl;
    }
}
