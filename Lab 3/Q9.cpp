#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int empID;
    string empName;
    double salary;

public:
    void accept() {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, empName);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() const {
        cout << "ID: " << empID << " | Name: " << empName << " | Salary: $" << salary << endl;
    }

    double getSalary() const {
        return salary;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee *employees = new Employee[n];

    cout << "\nEnter details for " << n << " employees:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        employees[i].accept();
    }

    cout << "\n--- Employee Records ---\n";
    double totalSalary = 0.0;
    int highestIndex = 0;

    for (int i = 0; i < n; i++) {
        cout << "Employee " << i + 1 << ": ";
        employees[i].display();
        totalSalary += employees[i].getSalary();

        if (employees[i].getSalary() > employees[highestIndex].getSalary()) {
            highestIndex = i;
        }
    }

    cout << "\n--- Summary Report ---\n";
    cout << "Highest Salary Employee:\n";
    employees[highestIndex].display();

    cout << "Average Salary: $" << (totalSalary / n) << endl;

    delete[] employees;
    return 0;
}