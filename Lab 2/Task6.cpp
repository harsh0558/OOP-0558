#include <iostream>
using namespace std;

struct Student{
    string name;
    string rollNumber;
    int marks[3];
    float average=0;
};

int main(){
    int numOfStudents;
    
    cout<<"enter the number of students: ";
    cin>>numOfStudents;

    Student *students = new Student[numOfStudents];

    for(int i = 0; i <numOfStudents; i++){
        cout<<"Enter the name of student "<<i+1<<": ";
        cin>>students[i].name;
        cout<<"Enter the roll number of student "<<i+1<<": ";
        cin>>students[i].rollNumber;
        cout<<"enter the marks for subject 1: ";
        cin>>students[i].marks[0];
        cout<<"enter the marks for subject 2: ";
        cin>>students[i].marks[1];
        cout<<"enter the marks for subject 3: ";
        cin>>students[i].marks[2];
        students[i].average = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2])/3.0;
    }

    for(int i=0; i<numOfStudents; i++){
        cout<<"Average marks of "<<students[i].name<<" are: "<<students[i].average<<endl;
    }

    delete[] students;
    return 0;
}