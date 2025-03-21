#include <iostream>
using namespace std;

class Device{
public:
    int deviceID;
    string deviceName;
    bool status;
    string location;

    Device(int id, string name, bool stat, string loc){
        deviceID = id;
        deviceName = name;
        status = stat;
        location = loc;
    }

    void turnOff(){
        status = false; 
    }

    void turnOn(){
        status = true; 
    }

    bool getStatus(){
        return status;
    }

    void displayInfo(){
        cout<<"Device ID: "<<deviceID<<endl;
        cout<<"Device Name: "<<deviceName<<endl;
        cout<<"Status: "<<status<<endl;
        cout<<"Location: "<<location<<endl;
    }
};

class Light: public Device{
private:
    int brightnessLevel;
    string colorMode;
public:
    Light(int id, string name, bool stat, string loc,int bl, string cm):Device( id,  name,  stat,  loc){
        brightnessLevel = bl;
        colorMode = cm;
    }

    void displayInfo(){
        cout<<"Device ID: "<<deviceID<<endl;
        cout<<"Device Name: "<<deviceName<<endl;
        cout<<"Status: "<<status<<endl;
        cout<<"Location: "<<location<<endl;
        cout<<"Brightness Level: "<<brightnessLevel<<endl;
        cout<<"Color Mode: "<<colorMode<<endl;
    }
};

class Thermostat: public Device{
private:
    int temperature;
    string mode;
    int targetTemperature;
public:
    Thermostat(int id, string name, bool stat, string loc,int temp,string m,int targetTemp):Device( id,  name,  stat,  loc){
        temperature = temp;
        mode = m;
        targetTemperature = targetTemp;
    };

    void getStatus(){
        cout<<"Current Temperature: "<<temperature<<endl;
    }
};

class SecurityCamera: public Device{
private:
    int resolution;
    bool recordingStatus;
    bool nightVisionEnabled;
public:
    SecurityCamera(int id, string name, bool stat, string loc, int res, bool rs, bool nv):Device( id,  name,  stat,  loc){
        resolution = res;
        recordingStatus = rs;
        nightVisionEnabled = nv;
    }

    void turnOn(){
        recordingStatus = true;
    };

    void turnOff(){
        recordingStatus = false;
    }
};

class SmartPlug: public Device{
private:
    int powerConsumption;
    string timerSetting;
public:
    SmartPlug(int id, string name, bool stat, string loc,int pc, string ts):Device( id,  name,  stat,  loc){
        powerConsumption = pc;
        timerSetting = ts;
    }

    void turnOff(int value){
        powerConsumption = value;
    }

};