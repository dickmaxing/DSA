// Assignment 11 : Basic Hash Table Implementation

#include <iostream>
#include <string>
using namespace std;

// Class to represent employee details
class Employee {
    int empID;
    string name;
    string contact;
    bool occupied;

public:
    Employee() {
        empID = -1;
        name = "";
        contact = "";
        occupied = false;
    }

    // Set employee data
    void setEmployee(int id, const string &n, const string &cont) {
        empID = id;
        name = n;
        contact = cont;
        occupied = true;
    }

    // Clear employee data (used to delete employee)
    void clearEmployee() {
        empID = -1;
        name = "";
        contact = "";
        occupied = false;
    }

    // Check if the slot is occupied
    bool isOccupied() const {
        return occupied;
    }

    // Display employee information
    void displayEmployee() const {
        if (occupied) {
            cout << "Employee ID: " << empID << endl;
            cout << "Name: " << name << endl;
            cout << "Contact: " << contact << endl;
        } else {
            cout << "Empty slot" << endl;
        }
    }

    // Get the ID of the employee
    int getID() const {
        return empID;
    }
};

class HashTable {
    int size;               // Size of the hash table
    Employee* table;        // Array to store employee data

public:
    // Constructor to initialize the hash table
    HashTable(int s) : size(s) {
        table = new Employee[size];
    }

    // Simple hash function to calculate index
    int hash(int id) const {
        return id % size;
    }

    // Add a new employee to the hash table
    void addEmployee(int empID, const string &name, const string &contact) {
        int index = hash(empID);

        // Insert only if the slot is unoccupied
        if (!table[index].isOccupied()) {
            table[index].setEmployee(empID, name, contact);
            cout << "Employee added at index " << index << endl;
        } else {
            cout << "Error: Slot already occupied. Try a different ID." << endl;
        }
    }

    // Display all employees in the hash table
    void displayAll() const {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            table[i].displayEmployee();
        }
    }

    // Find an employee by ID
    void findEmployee(int empID) const {
        int index = hash(empID);

        if (table[index].getID() == empID && table[index].isOccupied()) {
            table[index].displayEmployee();
        } else {
            cout << "Employee not found in the hash table." << endl;
        }
    }

    // Delete an employee by ID
    void deleteEmployee(int empID) {
        int index = hash(empID);

        if (table[index].getID() == empID && table[index].isOccupied()) {
            table[index].clearEmployee();
            cout << "Employee removed from index " << index << endl;
        } else {
            cout << "Employee not found." << endl;
        }
    }

    // Destructor to free up memory
    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable table(10); // Create a hash table of size 10
    int choice, empID;
    string name, contact;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Find Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> empID;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Contact: ";
            getline(cin, contact);
            table.addEmployee(empID, name, contact);
            break;

        case 2:
            table.displayAll();
            break;

        case 3:
            cout << "Enter Employee ID to find: ";
            cin >> empID;
            table.findEmployee(empID);
            break;

        case 4:
            cout << "Enter Employee ID to delete: ";
            cin >> empID;
            table.deleteEmployee(empID);
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
}
