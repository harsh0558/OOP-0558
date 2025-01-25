#include <iostream>

using namespace std;

int main(){
    string event1[5];
    string event2[5];

    for(int i=0;i<5;i++){
        cout << "enter the name of the participant of event 1: ";
        cin >> event1[i];

        cout << "enter the name of the participant of event 2 : ";
        cin >> event2[i];
    }
}