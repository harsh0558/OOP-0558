#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
    string contactNumber;
    string address;

    Person(string n, int a, string contact, string addr) {
        name = n;
        age = a;
        contactNumber = contact;
        address = addr;
    }

    void displayInfo() {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Contact: "<<contactNumber<<endl;
        cout<<"Address: "<<address<<endl;
    }

    void updateInfo(string newContact) {
        contactNumber = newContact;
        cout<<"Contact updated"<<endl;
    }
};

class Patient : public Person {
public:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

    Patient(string n, int a, string contact, int id, string history, string doctor, string addr)
        : Person(n, a, contact, addr){
            patientID = id;
            medicalHistory = history;
            doctorAssigned = doctor;
        }

    void displayInfo() {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Contact: "<<contactNumber<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Patient ID: "<<patientID<<endl;
        cout<<"Medical History: "<<medicalHistory<<endl;
        cout<<"Doctor Assigned: "<<doctorAssigned<<endl;
    }
};

class Doctor : public Person {
public:
    string specialization;
    float consultationFee;
    string patientsList;

    Doctor(string n, int a, string contact, string spec, float fee, string patients, string addr)
        : Person(n, a, contact, addr){
            specialization = spec;
            consultationFee = fee;
            patientsList = patients;
        }

    void displayInfo() {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Contact: "<<contactNumber<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Specialization: "<<specialization<<endl;
        cout<<"Consultation Fee: "<<consultationFee<<endl;
        cout<<"Patients List: "<<patientsList<<endl;
    }
};

class Nurse : public Person {
public:
    string assignedWard;
    string shiftTimings;

    Nurse(string n, int a, string contact, string ward, string shift, string addr)
        : Person(n, a, contact, addr){ 
            assignedWard = ward;
            shiftTimings = shift;
        }

    void displayInfo() {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Contact: "<<contactNumber<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Assigned Ward: "<<assignedWard<<endl;
        cout<<"Shift Timings: "<<shiftTimings<<endl;
    }
};

class Administrator : public Person {
public:
    string department;
    float salary;

    Administrator(string n, int a, string contact, string dept, float sal, string addr)
        : Person(n, a, contact, addr){
            department = dept;
            salary = sal;
        }

    void displayInfo() {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Contact: "<<contactNumber<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Salary: "<<salary<<endl;
    }

    void updateInfo(float newSalary) {
        salary = newSalary;
        cout<<"Salary updated"<<endl;
    }
};


