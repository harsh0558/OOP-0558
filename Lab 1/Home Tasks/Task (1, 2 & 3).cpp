#include <iostream>

using namespace std;

int main() {

    // Home task 1

    string city[4];
    int AQI[4][7]; 
    float avgAQI[4];
    int total;

    for (int i = 0; i < 4; i++) {
        total = 0;
        cout << "Enter the name of city " << i+1 << ": ";
        cin >> city[i]; 

        for (int j = 0; j < 7; j++) {
            cout << "Enter the AQI for " << city[i] << " for day " << j+1 << ": ";
            cin >> AQI[i][j]; 
            total += AQI[i][j];
        }
        avgAQI[i] = (float) total / 7;
    }

    float highest = avgAQI[0];
    int index = 0;
    
    for (int i = 0; i < 4; i++) {
        cout << "Avg AQI for " << city[i] << " is: " << avgAQI[i] << endl;
        if (avgAQI[i] > highest) {
            highest = avgAQI[i];
            index = i;
        }
    }

    cout << "The city with the worst air quality is " << city[index] << " with an AQI of " << highest << endl;

    // Home task 2
    cout << "\nCritical Pollution Days (AQI > 150):\n";
    for (int i = 0; i < 4; i++) {
        cout << "For " << city[i] << ": ";
        bool found = false;
        for (int j = 0; j < 7; j++) {
            if (AQI[i][j] > 150) {  
                cout << "Day " << j+1 << " (AQI: " << AQI[i][j] << ") ";
                found = true;
            }
        }
        if (found == false) {
            cout << "No critical pollution days.";
        }
        cout << endl;
    }

    // Home task 3
    cout << "\nAQI Data Visualization (* = AQI increment of 50):\n";
    for (int i = 0; i < 4; i++) {
        cout << city[i] << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "Day " << j+1 << ": ";
            int stars = AQI[i][j] / 50; 
            for (int k = 0; k < stars; k++) {
                cout << "*";
            }
            cout << " (" << AQI[i][j] << ")\n";
        }
    }

    return 0;
}
