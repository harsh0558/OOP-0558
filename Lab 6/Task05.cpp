#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status; 

public:
    void setDeviceDetails(int id, bool stat) {
        deviceID = id;
        status = stat;
    }

    void displayDetails() {
        cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "ON" : "OFF") << endl;
    }
};

class SmartPhone :  public virtual Device {
protected:
    float screenSize;

public:
    void setSmartPhoneDetails(float size) {
        screenSize = size;
    }

    void displayDetails()  {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch :  public virtual Device {
protected:
    bool heartRateMonitor; 

public:
    void setSmartWatchDetails(bool hrMonitor) {
        heartRateMonitor = hrMonitor;
    }

    void displayDetails()  {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " ;
        if(heartRateMonitor){
            cout<<"avaliable"<<endl;
        }else{
            cout<<"not avaliable"<<endl;
        }
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;

public:
    void setSmartWearableDetails(int id, bool stat, float size, bool hrMonitor, int steps) {
        Device::setDeviceDetails(id, stat);
        setSmartPhoneDetails(size);
        setSmartWatchDetails(hrMonitor);
        stepCounter = steps;
    }

    void displayDetails()  {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches\n";
        cout << "Heart Rate Monitor: " ;
        if(heartRateMonitor){
            cout<<"avaliable"<<endl;
        }else{
            cout<<"not avaliable"<<endl;
        }
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    SmartWearable wearable;

    int deviceID, stepCounter;
    bool status, heartRateMonitor;
    float screenSize;

    cout << "Enter Device ID: ";
    cin >> deviceID;
    cout << "Enter Status (1 for ON, 0 for OFF): ";
    cin >> status;
    cout << "Enter Screen Size (in inches): ";
    cin >> screenSize;
    cout << "Does it have a Heart Rate Monitor? (1 for Yes, 0 for No): ";
    cin >> heartRateMonitor;
    cout << "Enter Step Counter value: ";
    cin >> stepCounter;

    wearable.setSmartWearableDetails(deviceID, status, screenSize, heartRateMonitor, stepCounter);
    cout << "\n--- Smart Wearable Device Details ---\n";
    wearable.displayDetails();

    return 0;
}
