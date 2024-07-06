# Define the compiler
CXX = g++

# Define the output target
TARGET = hotelFinder

# Define source files
SOURCES = main.cpp hotel.cpp hashtable.cpp

# Define header files
HEADERS = hotel.hpp hashtable.hpp bst.hpp

# Default target to build the project
all: $(TARGET)

# Rule to link the program
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(SOURCES) -o $(TARGET)

# Define a clean target to remove compiled files
clean:
	rm -f $(TARGET) *.o
