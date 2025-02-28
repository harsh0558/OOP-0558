#include <iostream>
using namespace std;

class AlarmSystem {
private:
    string securityLevel;

public:
    AlarmSystem(string level) {
        securityLevel = level;
    }

    void details() {
        cout << "Alarm System Security Level: " << securityLevel << endl;
    }
};

class SmartHome {
private:
    string homeName;
    AlarmSystem alarm;

public:
    SmartHome(string name, string level) : alarm(level) {
        homeName = name;
    }

    void details() {
        cout << "Smart Home Name: " << homeName << endl;
        alarm.details();
        cout << endl;
    }
};

int main() {
    SmartHome home1("Villa", "High");

    cout << "----- Smart Home Details -----" << endl;
    home1.details();

    return 0;
}
