#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    string designation;

public:
    Employee(string name, string designation) {
        this->name = name;
        this->designation = designation;
    }

    void details() {
        cout << "Employee Name: " << name << ", Designation: " << designation << endl;
    }
};

class Project {
private:
    string title;
    string deadline;
    Employee* employees[10];
    int employeeCount;

public:
    Project(string title, string deadline) {
        this->title = title;
        this->deadline = deadline;
        employeeCount = 0;
    }

    void addEmployee(Employee* emp) {
        if (employeeCount < 10) {
            employees[employeeCount++] = emp;
        } else {
            cout << "Cannot add more employees to this project!" << endl;
        }
    }

    void details() {
        cout << "Project Title: " << title << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Assigned Employees: " << endl;
        for (int i = 0; i < employeeCount; i++) {
            employees[i]->details();
        }
        cout << endl;
    }
};

int main() {
    Project project1("AI Development", "30-06-2025");

    Employee emp1("harsh", "Software Engineer");
    Employee emp2("khubaib", "Data Scientist");

    project1.addEmployee(&emp1);
    project1.addEmployee(&emp2);

    cout << "----- Project Details -----" << endl;
    project1.details();

    return 0;
}
