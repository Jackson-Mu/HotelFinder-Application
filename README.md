
# Hotel Finder Application

Welcome to the Hotel Finder Application repository! This project, `hotelFinder`, helps you search for hotels in specific cities using a combination of efficient data structures. It is developed in C++ and is designed to be highly efficient and scalable.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Commands](#commands)
- [Data Structures](#data-structures)
- [Files](#files)
- [Contact](#contact)

## Overview
The Hotel Finder application manages hotel records, allowing you to store, retrieve, and delete records. Each record includes the hotel name, city name, stars, price, country name, and address. You can interact with the application through various commands, either from the terminal or by reading from a text file.

## Features
- **Find hotels by name and city**
- **Find all hotels in a city**
- **Find all hotels in a city with a specific star rating**
- **Add new hotel records**
- **Delete hotel records**
- **Dump all records to a file**
- **Efficient data storage and retrieval using hash tables and binary search trees**

## Requirements
- **Operating System**: Unix/Linux/MacOS/FreeBSD
- **Compiler**: g++

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/hotelFinder.git
   cd hotelFinder
   ```
2. Compile the project:
   ```bash
   make
   ```

## Usage
Invoke the application from the terminal as follows:
```bash
./hotelFinder -f <filename>
```
Where `<filename>` contains records to be inserted into your data structure(s).

## Commands
- `find <k>`: Find and display the hotel record with key `k`.
- `findAll <city>`: Find all hotels in the specified `city`.
- `findAll <city,stars>`: Find all hotels in the specified `city` with the given `stars`.
- `add s`: Add a new hotel record from the string `s`.
- `delete <k>`: Delete the hotel record with key `k`.
- `dump f`: Dump all hotel records to the file `f`.
- `exit`: Terminate the program gracefully.

## Data Structures
### HashTable Class
- **findAll**: Searches for all hotels in a given city.
- **erase**: Removes a hotel record by its key.
- **getSize**: Returns the size of the hash table.
- **getCollisions**: Returns the number of collisions.
- **dump**: Writes the hash table content to a file.
- **hashCode**: Generates a hash code for a given key.
- **insert**: Inserts a hotel record into the hash table.

### BST Class
- **insert**: Inserts a key into the tree.
- **height**: Finds the height of the tree/subtree.
- **find**: Searches for a node with a specific key.
- **findMin**: Finds the node with the minimum key value.
- **remove**: Removes a node with a specific key.
- **destroyTree**: Recursively destroys the tree.
- **constructor/destructor**: Initializes and destroys the tree.

### Hotel Class
- **constructor**: Initializes the hotel object with the provided information.
- **accessor methods**: Retrieves specific information about the hotel.
- **toString**: Converts the hotel information to a string.
- **print/print2**: Prints the hotel information to the console.

## Files
- `hashtable.hpp`: Header file for the HashTable class.
- `bst.hpp`: Header file for the BST class.
- `hotels.hpp`: Header file for the Hotel class.
- `hashtable.cpp`: Implementation file for the HashTable class.
- `main.cpp`: Main file to run the application.
- `Makefile`: Makefile for compiling the project.
- `hotels.csv`, `hotels100k.csv`, `hotels2.csv`: Example data files.

## Contact
For questions or feedback, please contact:
- **Name**: Jackson 
- **Email**: mukesjackson02@gmail.com
  
