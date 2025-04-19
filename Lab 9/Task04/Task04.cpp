#include <iostream>
using namespace std;

class WeatherSensor{
public:
    virtual void readData() = 0;
    virtual void displayReport() =0;

};

class Thermometer: public WeatherSensor{
public:
    void readData(){
        cout<<"reading temperature..."<<endl;
    }

    void displayReport(){
        cout<<"the temperature reading is: 100 F";
    }

};

class Barometer: public WeatherSensor{
public:

    void readData(){
        cout<<"reading pressure..."<<endl;
    }

    void displayReport(){
        cout<<"the pressure reading is: 100000 Pa";
    }
};

int main(){
    WeatherSensor* sensor1 = new Thermometer();
    WeatherSensor* sensor2 = new Barometer();

    sensor1->readData();
    sensor1->displayReport();
    cout << endl;

    sensor2->readData();
    sensor2->displayReport();
    cout << endl;
    return 0;
}