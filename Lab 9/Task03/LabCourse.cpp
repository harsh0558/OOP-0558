#include "LabCourse.h"

LabCourse::LabCourse(string code, int cred){
    courseCode = code;
    credits = cred;
}

void LabCourse::calculateGrade() {
    cout << "Calculating grade for Lab Course: " << courseCode << endl;
    cout << "Grade: 92%"<<endl;
}

void LabCourse::displayInfo() {
    cout << "Lab Course Code: " << courseCode << endl;
    cout << "Credits: " << credits << endl;
}