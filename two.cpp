#include <iostream>
#include <string>

using namespace std;


class Employee {
public:
    int empID;
    string empName;
    double empSalary;

    Employee(){
        this->empID = 0;
        this->empName = "";
        this->empSalary = 0.0; 
    }
    Employee(int id, string name, double salary){
        this->empID = id;
        this->empName = name;
        this->empSalary = salary;
    }

    public:
    
    void print() {
        cout << "EMP-ID: " << empID << ", EMP-Name: " << empName << ", EMP-Salary: " << empSalary << endl;
    }
};


// Function to print an array of employees
void printEmployees(Employee employees[], int size) {
    for (int i = 0; i < 8; ++i) {
        employees[i].print();
    }
}

//------------------------------------------------------------------------------------------

// Quick Sort functions
int partition(Employee arr[], int low, int high) {
    int pivot = arr[high].empID;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j].empID <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//------------------------------------------------------------------------------------------

// Merge Sort functions
void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].empName <= R[j].empName) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//------------------------------------------------------------------------------------------

int main() {
    // Sample Employee data
    Employee employees[8] = {
        Employee(103, "Alice", 55000),
        Employee(101, "Bob", 60000),
        Employee(105, "Carol", 52000),
        Employee(104, "Dave", 65000),
        Employee(102, "Eve", 58000),
        Employee(110, "Frank", 57000),
        Employee(109, "Grace", 63000),
        Employee(107, "Helen", 62000)
    };

    // Sort by EMP-ID using Quick Sort
    cout << "Employees sorted by EMP-ID (ascending):" << endl;
    quickSort(employees, 0, 8 - 1);
    printEmployees(employees, 8);

    cout << endl;

    // Sort by EMP-Name using Merge Sort
    cout << "Employees sorted by EMP-Name (alphabetical):" << endl;
    mergeSort(employees, 0, 8 - 1);
    printEmployees(employees, 8);

    return 0;
}