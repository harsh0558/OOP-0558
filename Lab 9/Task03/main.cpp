#include "LectureCourse.h"
#include "LabCourse.h"

int main() {
    Course* courses[2];

    courses[0] = new LectureCourse("PF", 3);
    courses[1] = new LabCourse("PFLab", 1);

    for (int i = 0; i < 2; ++i) {
        courses[i]->displayInfo();
        courses[i]->calculateGrade();
        cout << "----------------------\n";
    }

    for (int i = 0; i < 2; ++i) {
        delete courses[i];
    }

    return 0;
}
