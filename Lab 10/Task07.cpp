#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream sensorLog("sensor_log.txt");

    if (sensorLog.is_open())
    {
        sensorLog << "Sensor1: 25.5C\n";
        cout << "Write position after Sensor1: " << sensorLog.tellp() << endl;

        sensorLog << "Sensor2: 72.1F\n";
        cout << "Write position after Sensor2: " << sensorLog.tellp() << endl;

        sensorLog << "Sensor3: 1013.2hPa\n";
        cout << "Write position after Sensor3: " << sensorLog.tellp() << endl;

        sensorLog.close();
    }
    else
    {
        cerr << "Failed to open the file." << endl;
    }

    return 0;
}
