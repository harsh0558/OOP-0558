#include "LectureCourse.h"

LectureCourse::LectureCourse(string code, int cred){
    courseCode = code;
    credits = cred;
}

void LectureCourse::calculateGrade() {
    cout << "Calculating grade for Lecture Course: " << courseCode << endl;
    cout << "Grade: 85%"<<endl;
}

void LectureCourse::displayInfo() {
    cout << "Lecture Course Code: " << courseCode << endl;
    cout << "Credits: " << credits << endl;
}
