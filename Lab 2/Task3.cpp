#include <iostream>
using namespace std;

struct Employee{
    string name;
    int hoursWorked;
    int hourlyRate;
    int totalSalary;
};

int main() {
    int numOfEmployees;
    cout<<"enter the number of employees: ";
    cin>>numOfEmployees;

    Employee *employees = new Employee[numOfEmployees];

    for(int i=0;i<numOfEmployees;i++){
        cout<<"enter the name of the employee "<< i+1<<" : ";
        cin>>employees[i].name;

        cout<<"enter the hours worked by the employee "<< i+1<<" : ";
        cin>>employees[i].hoursWorked;

        cout<<"enter the hourly rate of the employee "<< i+1<<" : ";
        cin>>employees[i].hourlyRate;

        employees[i].totalSalary = employees[i].hoursWorked * employees[i].hourlyRate;
    }

    cout<<"Results"<<endl;
    cout<<"\n";
    
    for(int i=0;i<numOfEmployees;i++){
        cout<<"name: "<<employees[i].name<<endl;
        cout<<"hours worked: "<<employees[i].hoursWorked<<endl;
        cout<<"hourly rate: "<<employees[i].hourlyRate<<endl;
        cout<<"total salary: "<<employees[i].totalSalary<<endl;
        cout<<"\n";
    }

    delete [] employees;


    return 0;
}