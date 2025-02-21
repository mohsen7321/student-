#include <iostream>
#include <string>

using namespace std;

struct employee {
    string name;
    int age;
    int id;
    int salary;
    string address;
    string phone_number;
};

void displayEmployee(const employee& emp) {
    cout << "\n--------------------------------------\n";
    cout << "Name: " << emp.name << "\nAge: " << emp.age << "\nID: " << emp.id
         << "\nSalary: " << emp.salary << "\nAddress: " << emp.address << "\nPhone Number: " << emp.phone_number;
    cout << "\n--------------------------------------\n";
}

employee* findEmployeeById(employee employees[], int size, int searchId) {
    for (int i = 0; i < size; i++) {
        if (employees[i].id == searchId) {
            return &employees[i];
        }
    }
    return nullptr;
}

int main() {
    employee employees[] = {
        {"Ahmed", 25, 995, 6500, "Cairo", "01111111111"},
        {"Mohamed", 30, 996, 7800, "Giza", "01111111112"},
        {"Ali", 35, 997, 9000, "Alex", "01111111113"},
        {"Omar", 40, 998, 10000, "Aswan", "01111111114"},
        {"Khaled", 45, 999, 12000, "Luxor", "01111111115"},
        {"Mahmoud", 50, 1000, 15000, "Asyut", "01111111116"}
    };
    int numEmployees = sizeof(employees) / sizeof(employees[0]);
    
    while (true) {
        int searchId;
        cout << "Enter Employee ID (or -1 to exit): ";
        cin >> searchId;
        
        if (searchId == -1) {
            cout << "Exiting program...\n";
            break;
        }
        
        employee* found = findEmployeeById(employees, numEmployees, searchId);
        if (found) {
            displayEmployee(*found);
        } else {
            cout << "\nEmployee not found!\n";
        }
    }
    
    return 0;
}
