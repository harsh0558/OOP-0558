#include <iostream>
using namespace std;

class Car;

class InventoryManager{
public:
    void displayCarDetails(Car & car);
    void updatePrice(Car & car, float newPrice);
};

class Car{
private:
    string model;
    float price;
public:
    friend class InventoryManager;
    friend void comparePrice(Car & c1, Car & c2);

    Car(string m, float p){
        model = m;
        price = p;
    }
};

void InventoryManager::displayCarDetails(Car &car){
    cout<<"Model: "<<car.model<<endl;
    cout<<"Price: "<<car.price<<endl;
}

void InventoryManager::updatePrice(Car & car, float newPrice){
    car.price = newPrice;
}

void comparePrice(Car & c1, Car & c2){
    if(c1.price>c2.price){
        cout<<c1.model<<" is more expensive.\n";
    }else if(c2.price>c1.price){
        cout<<c2.model<<" is more expensive.\n";
    }else{
        cout<<"Both cars have the same price.\n";
    }
}

int main(){
    Car car1("Toyota Corolla", 250000);
    Car car2("Honda Civic", 270000);

    InventoryManager manager;

    cout << "Initial Car Details:\n";
    manager.displayCarDetails(car1);
    manager.displayCarDetails(car2);

    comparePrice(car1, car2);

    manager.updatePrice(car1, 28000);
    
    cout << "\nUpdated Car Details:\n";
    manager.displayCarDetails(car1);

    comparePrice(car1, car2);
    return 0;
}