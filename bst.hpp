/**
 * @file bst.hpp
 * @author Jackson Mukeshimana
 * @description BST Tree implementation in C++
 * @date 2023-12-12
 */
#pragma once
#include<iostream>
#include<cstdlib>
#include<sstream>
#include<iomanip>
#include<math.h>
#include<queue>
#include<vector>

using namespace std;
template <typename T1, typename T2>
class Node
{
	private:
		T1 key;					//city name
		vector<T2> value;		//list of hotels in the city
		Node<T1,T2>* left;		//left child
		Node<T1,T2>* right;		//right child
		Node<T1,T2>* parent;	//pointer to the parent node
	public:
		Node(T1 key): key(key),left(nullptr),right(nullptr), parent(nullptr) 
		{}
		void print(string stars="")	//print all or only those hotels with specific stars.
		{
			int counter=0;
			cout<<std::left<<setw(50)<<"Name"<<" "<<setw(10)<<"City"<<" "<<setw(5)<<"Stars"<<" "<<setw(10)<<"Price"<<" "<<setw(20)<<"Country"<<" "<<"Address"<<endl;
			cout<<"------------------------------------------------------------------------------------------------------------"<<endl;

			for(auto it:value)
				if(stars=="" or stars==it->getStars())
				{
					it->print2();
					counter++;
				}
			
			cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<counter<<" records found."<<endl;
		}

		template<typename,typename> friend class BST;
};
//=============================================================================
template <typename T1, typename T2>
class BST
{
	private:
		Node<T1,T2> *root;
	public:
		BST();									//constructor
		~BST();									//destructor
		Node<T1,T2>* getRoot();						//returns the root of the Tree
		void insert(Node<T1,T2>* ptr,T1 key, T2 value);			//Insert key into tree/subtree with root ptr
		int height(Node<T1,T2> *ptr);				    //Find the height of a tree/subtree with root ptr
		Node<T1,T2>* find(Node<T1,T2> *ptr,T1 key,string stars);		//Find and returns the node with key
		Node<T1,T2>* findMin(Node<T1,T2> *ptr);				//Find and return the Node<T1,T2> with minimum key value from a tree/subtree with root ptr
		void remove(Node<T1,T2> *ptr,T1 key, T2 value);			//Remove a node with key from the tree/subtree with root

		void destroyTree(Node<T1, T2>* ptr);             // Helper method for destroying thr tree
};
//=====================================================================
//write implementation of all methods below

// Constructor for BST
template <typename T1, typename T2>
BST<T1, T2>::BST() : root(nullptr) {
    // Initialize the root of the tree to nullptr
}

// Destructor for BST
template <typename T1, typename T2>
BST<T1, T2>::~BST() {
    // Call the helper function to destroy the tree
    destroyTree(root);
}

// Helper function to destroy the tree
template <typename T1, typename T2>
void BST<T1, T2>::destroyTree(Node<T1, T2>* ptr) {
    // If the current node is not nullptr
    if (ptr != nullptr) {
        // Recursively destroy the left subtree
        destroyTree(ptr->left);
        // Recursively destroy the right subtree
        destroyTree(ptr->right);
        // Delete the current node
        delete ptr;
    }
}


// Get Root of the Tree
template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::getRoot() {
    // Return the root of the tree
    return root;
}

// Insert Key into Tree/Subtree
template <typename T1, typename T2>
void BST<T1, T2>::insert(Node<T1, T2>* ptr, T1 key, T2 value) {
    // If the current node is nullptr
    if (ptr == nullptr) {
        // Create a new node with the given key
        root = new Node<T1, T2>(key);
        // Add the value to the new node
        root->value.push_back(value);
    } else {
        // If the key is less than the current node's key
        if (key < ptr->key) {
            // If the left child is nullptr
            if (ptr->left == nullptr) {
                // Create a new node with the given key
                ptr->left = new Node<T1, T2>(key);
                // Set the parent of the new node
                ptr->left->parent = ptr;
                // Add the value to the new node
                ptr->left->value.push_back(value);
            } else {
                // Recursively insert the key into the left subtree
                insert(ptr->left, key, value);
            }
        } else if (key > ptr->key) {
            // If the right child is nullptr
            if (ptr->right == nullptr) {
                // Create a new node with the given key
                ptr->right = new Node<T1, T2>(key);
                // Set the parent of the new node
                ptr->right->parent = ptr;
                // Add the value to the new node
                ptr->right->value.push_back(value);
            } else {
                // Recursively insert the key into the right subtree
                insert(ptr->right, key, value);
            }
        } else {
            // If the key already exists, add the value to the existing city node
            ptr->value.push_back(value);
        }
    }
}

// Find Height of Tree/Subtree
template <typename T1, typename T2>
int BST<T1, T2>::height(Node<T1, T2>* ptr) {
    // If the current node is nullptr
    if (ptr == nullptr) {
        // Return 0
        return 0;
    }
    // Return the maximum height of the left and right subtrees plus 1
    return max(height(ptr->left), height(ptr->right)) + 1;
}

// Find Node with Key
template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::find(Node<T1, T2>* ptr, T1 key, string stars) {
    // If the current node is nullptr or the key is found
    if (ptr == nullptr || ptr->key == key) {
        // If the current node is not nullptr and the stars are empty or match the first value's stars
        if (ptr != nullptr && (stars == "" || stars == ptr->value[0]->getStars())) {
            // Print the details of the node
            ptr->print(stars);
        }
        // Return the current node
        return ptr;
    }
    // If the key is less than the current node's key
    if (key < ptr->key) {
        // Recursively search the left subtree
        return find(ptr->left, key, stars);
    } else {
        // Recursively search the right subtree
        return find(ptr->right, key, stars);
    }
}

// Find Minimum Key Node in Tree/Subtree
template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::findMin(Node<T1, T2>* ptr) {
    // While the left child is not nullptr
    while (ptr->left != nullptr) {
        // Move to the left child
        ptr = ptr->left;
    }
    // Return the node with the minimum key value
    return ptr;
}

// Remove Node with Key
template <typename T1, typename T2>
void BST<T1, T2>::remove(Node<T1, T2>* ptr, T1 key, T2 value) {
    // If the current node is nullptr
    if (ptr == nullptr) {
        // Return
        return;
    }
    // If the key is less than the current node's key
    if (key < ptr->key) {
        // Recursively remove the key from the left subtree
        remove(ptr->left, key, value);
    } else if (key > ptr->key) {
        // Recursively remove the key from the right subtree
        remove(ptr->right, key, value);
    } else {
        // Node with only one child or no child
        if (ptr->left == nullptr) {
            // Set the temporary node to the right child
            Node<T1, T2>* temp = ptr->right;
            // If the current node is the root
            if (ptr == root) {
                // Set the root to the temporary node
                root = temp;
            } else {
                // If the current node is the left child of its parent
                if (ptr->parent->left == ptr) {
                    // Set the left child of the parent to the temporary node
                    ptr->parent->left = temp;
                } else {
                    // Set the right child of the parent to the temporary node
                    ptr->parent->right = temp;
                }
            }
            // Delete the current node
            delete ptr;
        } else if (ptr->right == nullptr) {
            // Set the temporary node to the left child
            Node<T1, T2>* temp = ptr->left;
            // If the current node is the root
            if (ptr == root) {
                // Set the root to the temporary node
                root = temp;
            } else {
                // If the current node is the left child of its parent
                if (ptr->parent->left == ptr) {
                    // Set the left child of the parent to the temporary node
                    ptr->parent->left = temp;
                } else {
                    // Set the right child of the parent to the temporary node
                    ptr->parent->right = temp;
                }
            }
            // Delete the current node
            delete ptr;
        } else {
            // Node with two children: Get the inorder successor
            Node<T1, T2>* temp = findMin(ptr->right);
            // Set the current node's key and value to the inorder successor's key and value
            ptr->key = temp->key;
            ptr->value = temp->value;
            // Recursively remove the inorder successor from the right subtree
            remove(ptr->right, temp->key, temp->value);
        }
    }
}
