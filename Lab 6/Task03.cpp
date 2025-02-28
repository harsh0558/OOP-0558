#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void setPersonDetails(string n, int a) {
        name = n;
        age = a;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;

public:
    void setTeacherDetails(string sub) {
        subject = sub;
    }

    virtual void displayDetails() override {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : virtual public Person {
protected:
    string researchArea;

public:
    void setResearcherDetails(string area) {
        researchArea = area;
    }

    virtual void displayDetails() override {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    void setProfessorDetails(string n, int a, string sub, string area, int pub) {
        setPersonDetails(n, a);
        setTeacherDetails(sub);
        setResearcherDetails(area);
        publications = pub;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject: " << subject << "\nResearch Area: " << researchArea << "\nPublications: " << publications << endl;
    }
};

int main() {
    Professor prof;
    string name, subject, researchArea;
    int age, publications;

    cout << "Enter Professor's Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Subject: ";
    getline(cin, subject);
    cout << "Enter Research Area: ";
    getline(cin, researchArea);
    cout << "Enter Number of Publications: ";
    cin >> publications;

    prof.setProfessorDetails(name, age, subject, researchArea, publications);
    cout << "\nProfessor Details:\n";
    prof.displayDetails();

    return 0;
}
