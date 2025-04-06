/*	Group Project - CSCE 3110.001
	By: Manuel Flores (only one)
	Description: Hash table to store student information with 
				 chaining using linked list as collision strategy
				 and modulo as hash function
	
	To complie: need main.cpp and moduloChainLinkedList.h
		g++ main.cpp
		./a.out

*/

#ifndef MODULOCHAINLINKEDLIST_H
#define MODULOCHAINLINKEDLIST_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

//struct to represent a Student
struct Student {
    string name;
    string dob;
    string street;
    string city;
    string state;
    string zip;
};

//node structure for linked list
struct Node {
    int key;  //student ID
    Student data;
    Node* next;
    
    Node(int k, const Student& s) : key(k), data(s), next(nullptr) {}
};

//hash table implementation using chaining
class HashTable {
private:
    vector<Node*> table;
    int capacity;

    //hash function using modulo
    int hash(int key) {
        return key % capacity;
    }

public:
    //resize hash table
    HashTable(int cap) : capacity(cap) {
        table.resize(capacity, nullptr);
    }

    //insert a student record into the hash table
    void insert(int key) {
        Student newStudent;
        cout << "Enter name: ";
        cin.ignore(); 	//consume newline character left in the stream
        getline(cin, newStudent.name);
        cout << "Enter DOB: ";
        getline(cin, newStudent.dob);
        cout << "Enter street: ";
        getline(cin, newStudent.street);
        cout << "Enter city: ";
        getline(cin, newStudent.city);
        cout << "Enter state: ";
        getline(cin, newStudent.state);
        cout << "Enter zip: ";
        getline(cin, newStudent.zip);

        int index = hash(key);
        Node* newNode = new Node(key, newStudent);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            //collision occurred, add to the linked list
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        
        //student has been added
        cout << "Student added" << endl;
    }

    //search for a student record by ID in the hash table
    Node* searchById(int key) {
        int index = hash(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return current;
            }
            current = current->next;
        }

        //student not found
        return nullptr;
    }

	//search for a student record by name in the hash table
    Node* searchByName(const string& name) {
        for (Node* current : table) {
            while (current != nullptr) {
                if (current->data.name == name) {
                    return current;
                }
                current = current->next;
            }
        }

        //student not found
        return nullptr;
    }

    //delete a student record by ID
    void remove(int key) {
        int index = hash(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    //if the node to be deleted is the head of the list
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Student with ID " << key << " deleted" << endl;    //student deleted successfully
                return;
            }
            prev = current;
            current = current->next;
        }
        
        //student not found
        cout << "Student with ID " << key << " not found." << endl;
    }

    //update a student record by ID
    void update(int key) {
        Node* studentNode = searchById(key);
        if (studentNode != nullptr) {
            //display current information
            cout << "Current Information:" << endl;
            Student& student = studentNode->data;
            cout << "Name: " << student.name << endl;
            cout << "DOB: " << student.dob << endl;
            cout << "Street: " << student.street << endl;
            cout << "City: " << student.city << endl;
            cout << "State: " << student.state << endl;
            cout << "Zip: " << student.zip << endl;

            //allow the user to modify information
            cout << "Enter new name: ";
            cin.ignore();	 // consume newline character left in the stream
            getline(cin, student.name);
            cout << "Enter new DOB: ";
            getline(cin, student.dob);
            cout << "Enter new street: ";
            getline(cin, student.street);
            cout << "Enter new city: ";
            getline(cin, student.city);
            cout << "Enter new state: ";
            getline(cin, student.state);
            cout << "Enter new zip: ";
            getline(cin, student.zip);

            cout << "Information updated successfully." << endl;
        } else {
            cout << "Student with ID " << key << " not found." << endl;
        }
    }

	//output hash table contents to a CSV file
    void outputToCSV(const string& filename) {
        ofstream outfile(filename);

        //try to open file; error if unsucessful
        if (!outfile.is_open()) {
            cout << "Error: Unable to open file for writing." << endl;
            return;
        }

        //header
        outfile << "StudentID,Name,DOB,Street,City,State,Zip" << endl;

        //write data
        for (Node* node : table) {
            while (node != nullptr) {
                outfile << node->key << ",";
                outfile << node->data.name << ",";
                outfile << node->data.dob << ",";
                outfile << node->data.street << ",";
                outfile << node->data.city << ",";
                outfile << node->data.state << ",";
                outfile << node->data.zip << endl;
                node = node->next;
            }
        }

        //close file and output confirmation message
        outfile.close();
        cout << "Data has been written to " << filename << " successfully." << endl;
    }

    //destructor
    ~HashTable() {
        for (int i = 0; i < capacity; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

#endif