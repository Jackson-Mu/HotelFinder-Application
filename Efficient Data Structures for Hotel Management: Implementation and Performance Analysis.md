# Methods Explanation of Implementation and Efficiency

## Binary Search Tree (BST) Class Methods:

1. **Insert Method:**
   - Inserts a key into the tree, maintaining the BST property.
   - **Time Complexity:** O(log n) for balanced trees, O(n) for unbalanced trees.

2. **Height Method:**
   - Finds the height of the tree/subtree.
   - **Time Complexity:** O(log n) for balanced trees, O(n) for unbalanced trees.

3. **Find Method:**
   - Searches for a node with a specific key.
   - **Time Complexity:** O(log n) for balanced trees, O(n) for unbalanced trees.

4. **FindMin Method:**
   - Finds the node with the minimum key value.
   - **Time Complexity:** O(log n) for balanced trees, O(n) for unbalanced trees.

5. **Remove Method:**
   - Removes a node with a specific key from the tree.
   - **Time Complexity:** O(log n) for balanced trees, O(n) for unbalanced trees.

6. **DestroyTree Method:**
   - Recursively destroys the tree.
   - **Time Complexity:** O(n).

7. **Constructor and Destructor:**
   - Initialize and destroy the tree respectively.
   - **Time Complexity:** O(1) and O(n) average respectively.

These methods are designed for efficiency and maintain the BST property. Recursive implementations ensure modularity and clarity. The use of BST facilitates efficient searches, promoting scalability and performance.

## HashTable Class Methods:

1. **FindAll Method:**
   - Searches for all hotels in a given city using a BST for efficient search.
   - **Time Complexity:** O(log n) for balanced trees, O(n) for unbalanced trees.

2. **Erase Method:**
   - Removes a hotel record by its key from the hash table.
   - **Time Complexity:** O(1) average, O(n) worst-case.

3. **GetSize Method:**
   - Returns the size of the hash table.
   - **Time Complexity:** O(1).

4. **GetCollisions Method:**
   - Returns the number of collisions.
   - **Time Complexity:** O(1).

5. **Dump Method:**
   - Writes the hash table content to a file.
   - **Time Complexity:** O(n).

6. **HashCode Method:**
   - Generates a hash code for the given key.
   - **Time Complexity:** O(k) where k is the length of the key.

7. **Insert Method:**
   - Inserts a hotel record into the hash table.
   - **Time Complexity:** O(1) average, O(n) worst-case.

These methods ensure efficiency and scalability. Use of a hash table for main data storage and a BST for efficient searches aligns with performance requirements. The modular implementation supports easy understanding and maintenance.

## Hotel Class Methods:

1. **Constructor:**
   - Initializes a hotel object with provided information.
   - **Time Complexity:** O(1).

2. **Accessor Methods:**
   - Retrieves specific information about the hotel.
   - **Time Complexity:** O(1) each.

3. **ToString Method:**
   - Converts hotel information to a string.
   - **Time Complexity:** O(1).

4. **Print Methods:**
   - Prints hotel information to the console.
   - **Time Complexity:** O(1) each.

These methods provide easy access and printing of hotel information with constant time complexity, ensuring efficient data management.

## Main Function:

- Reads data from a file, populates the hash table, and displays hash table statistics and available commands.
- Processes user input to execute corresponding commands efficiently.

The design choices facilitate user-friendly interaction and efficient data manipulation. Operations are optimized for handling a large volume of data effectively.
