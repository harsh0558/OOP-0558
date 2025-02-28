#include <iostream>
#include <vector>
using namespace std;

class Doctor {
private:
    string name;
    string specialization;
    int experience;

public:
    Doctor(string n, string spec, int exp) {
        name = n;
        specialization = spec;
        experience = exp;
    }

    void details() {
        cout << "Doctor Name: " << name << ", Specialization: " << specialization
             << ", Experience: " << experience << " years" << endl;
    }
};

class Hospital {
private:
    string hospitalName;
    vector<Doctor> doctors;
    int doctorCount;

public:
    Hospital(string name) {
        hospitalName = name;
        doctorCount = 0;
    }

    void addDoctor(Doctor d) {
        doctors.push_back(d);
        doctorCount++; 
    }

    void details() {
        cout << "Hospital Name: " << hospitalName << endl;
        cout << "Doctors Working Here:" << endl;
        
        for (int i = 0; i < doctorCount; i++) {
            doctors[i].details();
        }
        cout << endl;
    }
};

int main() {
    Doctor doc1("harsh", "cardio", 10);
    Doctor doc2("khubaib", "neuro", 8);
    Doctor doc3("taha", "eneral", 12);

    Hospital hospital("agha khan");

    hospital.addDoctor(doc1);
    hospital.addDoctor(doc2);
    hospital.addDoctor(doc3);

    cout << "----- Hospital Details -----" << endl;
    hospital.details();

    return 0;
}
