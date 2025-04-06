/*	Group Project - CSCE 3110.001
	By: Manuel Flores (only one)
	Description: Hash table to store student information with 
				 chaining using linked list as collision strategy
				 and modulo as hash function
	
	To complie: need main.cpp and moduloChainLinkedList.h
		g++ main.cpp
		./a.out

*/

#include "moduloChainLinkedList.h"

int main () {

	HashTable hashTable(100);	//hashtable with size of 100

	Node* currStudent;

	enum Choices {Insert = 1, SearchID, SearchNAME, Delete, Update, Output, Quit}; //enum for menu control
	int userChoice;		//user choice for menu control
	Choices enumChoice;	//type change for enum
	
	//menu
	do {
		sleep(1);
		cout << "--------------Menu--------------" << endl;
		cout << "1. Insert a student" << endl;
		cout << "2. Search with student ID" << endl;
		cout << "3. Search with student name" << endl;
		cout << "4. Delete a student" << endl;
		cout << "5. Update a student" << endl;
		cout << "6. Write all data to desired file" << endl;
		cout << "7. Quit" << endl;
		cout << "Enter choice as a number:";
		
		cin >> userChoice;
		enumChoice = static_cast<Choices>(userChoice);
		string userValueStr;
		int userValueInt;

		switch (enumChoice) {
		case Insert: 	//Add student to existing database
			cout << "Enter an ID to insert: ";
			cin >> userValueInt;
			hashTable.insert(userValueInt);
			break;
		
		case SearchID:	//Search for student with ID
			cout << "Enter studentID to search for: ";
			cin >> userValueInt;
			currStudent = hashTable.searchById(userValueInt);
			if(currStudent != nullptr) {
				cout << "Searched Information:" << endl;
				Student& student = currStudent->data;
				cout << "Name: " << student.name << endl;
				cout << "DOB: " << student.dob << endl;
				cout << "Street: " << student.street << endl;
				cout << "City: " << student.city << endl;
				cout << "State: " << student.state << endl;
				cout << "Zip: " << student.zip << endl;
			} else {
				cout << "Student with ID " << userValueInt << " not found." << endl;
			}
			break;

		case SearchNAME:	//Search for student with Name
			cout << "Enter the student's name: ";
			cin.ignore();
			getline(cin, userValueStr);
			currStudent = hashTable.searchByName(userValueStr);
			if(currStudent != nullptr) {
				cout << "Searched Information:" << endl;
				Student& student = currStudent->data;
				cout << "Name: " << student.name << endl;
				cout << "DOB: " << student.dob << endl;
				cout << "Street: " << student.street << endl;
				cout << "City: " << student.city << endl;
				cout << "State: " << student.state << endl;
				cout << "Zip: " << student.zip << endl;
			} else {
				cout << "Student with ID " << userValueInt << " not found." << endl;
			}
			break;

		case Delete:	//Delete a student
			cout << "Enter studentID to delete: ";
			cin >> userValueInt;
			hashTable.remove(userValueInt);
			break;

		case Update:	//Update a student
			cout << "Enter studentID to update: ";
			cin >> userValueInt;
			hashTable.update(userValueInt);
			break;

		case Output:	//Output hash table in a CSV format to file
			cout << "Enter name of file: ";
			cin.ignore();
			getline(cin, userValueStr);
			cout << "Outputting hash table to file..." << endl;
			hashTable.outputToCSV(userValueStr);
			break;

		case Quit:		//Quit program
			cout << "End of program" << endl;
			break;

		default:
			cout << "Invalid Choice. Please try again" << endl;
			break;
		}
		cout << endl;

	} while(enumChoice != 7);
}

