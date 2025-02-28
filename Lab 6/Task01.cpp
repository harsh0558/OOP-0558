#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    float salary;

public:
    Employee(string empName, float empSalary) {
        name = empName;
        salary = empSalary;
    }

    void displayDetails() {
        cout << "Employee Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Manager : public Employee {
private:
    float bonus;

public:
    Manager(string mgrName, float mgrSalary, float mgrBonus) 
        : Employee(mgrName, mgrSalary) {
        bonus = mgrBonus;
    }

    void displayDetails()  {
        cout << "Manager Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

int main() {
 
    string name;
    float salary, bonus;

    cout << "Enter Manager's Name: ";
    getline(cin, name);

    cout << "Enter Salary: ";
    cin >> salary;

    cout << "Enter Bonus: ";
    cin >> bonus;

    Manager mgr(name, salary, bonus);

    cout << "\nManager Details:\n";
    mgr.displayDetails();

    return 0;
}
