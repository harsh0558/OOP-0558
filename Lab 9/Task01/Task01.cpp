#include <iostream>
using namespace std;

class Patient{
protected:
    string name;
    string id;
public:
    virtual void displayTreatment(string treatment) = 0;
    virtual float calculateCost(int hours) = 0;
};

class InPatient: public Patient{
public:
    InPatient(string n, string i){
        name = n;
        id = i;
    }

    void displayTreatment(string treatment){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Treatment: "<<treatment<<endl;
    }

    float calculateCost(int hours){
        return 100*hours; // assuming 100rs per hour cost
    }
};

class OutPatient: public Patient{
    public:
        OutPatient(string n, string i){
            name = n;
            id = i;
        }
    
        void displayTreatment(string consultation){
            cout<<"Name: "<<name<<endl;
            cout<<"ID: "<<id<<endl;
            cout<<"consultation: "<<consultation<<endl;
        }
    
        float calculateCost(int hours){
            return 200*hours; // assuming 100rs per hour consultation cost
        }
    };

int main(){

    Patient* p1 = new InPatient("Ali", "01");
    Patient* p2 = new OutPatient("Sara", "02");

    p1->displayTreatment("Surgery");
    cout<<"Total Cost: Rs. "<<p1->calculateCost(5)<<endl;

    p2->displayTreatment("Checkup");
    cout<<"Total Cost: Rs. "<<p2->calculateCost(2)<<endl;


    return 0;
}