#include <iostream>

using namespace std;

int main() {
 
    // Home task 4

    string city[4];
    int AQI[4][28]; 
    float avgAQI[4];
    int total;

    for (int i = 0; i < 4; i++) {
        total = 0;
        cout << "Enter the name of city " << i+1 << ": ";
        cin >> city[i]; 

        for (int j = 0; j < 28; j++) { 
            cout << "Enter the AQI for " << city[i] << " for day " << j+1 << ": ";
            cin >> AQI[i][j]; 
            total += AQI[i][j];
        }
        avgAQI[i] = (float) total / 28;
    }

    cout << "\nMonthly AQI Comparison:\n";
    float weeklyAvg[4][4]; 
    for (int i = 0; i < 4; i++) {
        for (int w = 0; w < 4; w++) {
            int weeklyTotal = 0;
            for (int j = w * 7; j < (w + 1) * 7; j++) {
                weeklyTotal += AQI[i][j];
            }
            weeklyAvg[i][w] = (float) weeklyTotal / 7;
            cout << "Week " << w+1 << " average AQI for " << city[i] << ": " << weeklyAvg[i][w] << endl;
        }
    }

    float maxImprovement = 0;
    int improvedCity = 0;
    for (int i = 0; i < 4; i++) {
        float improvement = weeklyAvg[i][0] - weeklyAvg[i][3];
        if (improvement > maxImprovement) {
            maxImprovement = improvement;
            improvedCity = i;
        }
    }

    cout << "The city with the most improved air quality is " << city[improvedCity] << " with a drop of " << maxImprovement << " AQI points.\n";

    // Home task 5

    cout << "\nFinal Report:\n";
    for (int i = 0; i < 4; i++) {
        cout << "\nCity: " << city[i] << endl;
        cout << "Monthly Average AQI: " << avgAQI[i] << endl;
        cout << "Weekly AQI Averages: ";
        for (int w = 0; w < 4; w++) {
            cout << "Week " << w+1 << ": " << weeklyAvg[i][w] << " ";
        }
        cout << endl;

        cout << "Critical Pollution Days: ";
        bool found = false;
        for (int j = 0; j < 28; j++) {
            if (AQI[i][j] > 150) {
                cout << "Day " << j+1 << " ";
                found = true;
            }
        }
        if (!found) {
            cout << "None";
        }
        cout << endl;

        int highestAQI = AQI[i][0], lowestAQI = AQI[i][0];
        for (int j = 1; j < 28; j++) {
            if (AQI[i][j] > highestAQI) highestAQI = AQI[i][j];
            if (AQI[i][j] < lowestAQI) lowestAQI = AQI[i][j];
        }
        cout << "Highest AQI: " << highestAQI << endl;
        cout << "Lowest AQI: " << lowestAQI << endl;
    }

    return 0;
}
