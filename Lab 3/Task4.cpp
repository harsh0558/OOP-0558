#include <iostream>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    int fuelCapacity;
    int currentFuelLevel;

public:
    Car(string brand, string model, int fuelCapacity)
    {
        this->brand = brand;
        this->model = model;
        this->fuelCapacity = fuelCapacity;
        this->currentFuelLevel = 0;
    }

    void refuel(int fuel)
    {
        if (fuel + currentFuelLevel <= fuelCapacity)
        {
            currentFuelLevel += fuel;
        }
        else
        {
            cout << "Fuel tank capacity exceeded!" << endl;
        }
    }

    void checkFuelStatus()
    {
        cout << "Current fuel level: " << currentFuelLevel << endl;
    }

    void drive(int distance)
    {
        int fuelNeeded = distance / 10; // Assuming the car consumes 1 liter of fuel per 10 km
        if (fuelNeeded <= currentFuelLevel)
        {
            currentFuelLevel -= fuelNeeded;
            cout << "You have driven " << distance << " km." << endl;
        }
        else
        {
            cout << "Not enough fuel to drive the distance" << endl;
        }
    }
};

int main()
{
    Car car("Toyota", "Corolla", 50);
    car.refuel(30);
    car.checkFuelStatus();
    car.drive(200);
    car.checkFuelStatus();
    car.drive(500);
    car.checkFuelStatus();

    return 0;
}