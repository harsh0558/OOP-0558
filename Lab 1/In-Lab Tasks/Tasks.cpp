#include <iostream>

using namespace std;

int main() {
    // Lab task 1
    string event1[5];
    string event2[5];
    int count1 = 0, count2 = 0;
    char choice;

    cout << "Register participants for Event 1:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Do you want to enter a participant for Event 1? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') break;
        cout << "Enter the name of the participant: ";
        cin >> event1[count1++];
    }

    cout << "\nRegister participants for Event 2:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Do you want to enter a participant for Event 2? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') break;
        cout << "Enter the name of the participant: ";
        cin >> event2[count2++];
    }

    // Lab task 2
    bool isPresent = false;
    string name;

    cout << "\nEnter the name of the participant to check: ";
    cin >> name;

    for (int i = 0; i < count1; i++) {
        if (name == event1[i]) {
            isPresent = true;
            break;
        }
    }
    for (int i = 0; i < count2; i++) {
        if (name == event2[i]) {
            isPresent = true;
            break;
        }
    }

    if (isPresent) {
        cout << "The participant entered is present" << endl;
    } else {
        cout << "The participant entered is not present" << endl;
    }

    // Lab task 3
    int total = 0;
    int num;
    cout << "\nFOR EVENT 1" << endl;

    for (int i = 0; i < count1; i++) {
        cout << "Enter the amount donated by " << event1[i] << ": ";
        cin >> num;
        total += num;
    }

    cout << "Total donations from Event 1: " << total << endl;

    total = 0;
    cout << "\nFOR EVENT 2" << endl;

    for (int i = 0; i < count2; i++) {
        cout << "Enter the amount donated by " << event2[i] << ": ";
        cin >> num;
        total += num;
    }

    cout << "Total donations from Event 2: " << total << endl;

    // Lab task 4
    cout << "\nParticipants of Event 1 (reversed)" << endl;
    for (int i = count1 - 1; i >= 0; i--) {
        cout << "Participant " << (count1 - i) << ": " << event1[i] << endl;
    }

    cout << "\nParticipants of Event 2 (reversed)" << endl;
    for (int i = count2 - 1; i >= 0; i--) {
        cout << "Participant " << (count2 - i) << ": " << event2[i] << endl;
    }

    // Lab task 5: Event Popularity Bar Chart
    cout << "\nEvent Popularity Bar Chart" << endl;
    cout << "Event 1: ";
    for (int i = 0; i < count1; i++) {
        cout << "*";
    }
    cout << " (" << count1 << " participants)" << endl;

    cout << "Event 2: ";
    for (int i = 0; i < count2; i++) {
        cout << "*";
    }
    cout << " (" << count2 << " participants)" << endl;

    return 0;
}
