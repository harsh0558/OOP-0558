#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    int id;
    string name;
    int* scores;
    int numScores;

public:
    Student(int id, string name, int scores[], int numScores) {
        this->id = id;
        this->name = name;
        this->numScores = numScores;
        this->scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            this->scores[i] = scores[i];
        }
    }

    Student(const Student& obj) {
        this->id = obj.id;
        this->name = obj.name;
        this->numScores = obj.numScores;
        this->scores = new int[obj.numScores];
        for (int i = 0; i < obj.numScores; i++) {
            this->scores[i] = obj.scores[i];
        }
    }

    void displayDetails() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Exam Scores: ";
        for (int i = 0; i < numScores; i++) {
            cout << scores[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int scores1[] = {85, 90, 78};
    Student student1(101, "harsh", scores1, 3);
    Student student2(student1);

    cout << "----- Details of Student 1 -----" << endl;
    student1.displayDetails();
    cout << "\n";

    cout << "----- Details of Student 2 (Copy) -----" << endl;
    student2.displayDetails();

    return 0;
}
