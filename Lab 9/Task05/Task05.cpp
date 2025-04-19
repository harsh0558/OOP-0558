#include <iostream>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;

};

class AirFreight : public Shipment {
public:
    AirFreight(string tn, float w){
        trackingNumber = tn;
        weight = w;
    }

    void estimateDeliveryTime()  {
        float time = 1 + (weight / 6.5); // own made shipment formula
        cout<<"Estimated Air Delivery Time: "<<time<<" days"<<endl;
    }

    void showDetails(){
        cout<<"Air Shipment"<<endl;
        cout<< "Tracking Number: "<<trackingNumber<<endl;
        cout<<"Weight: "<<weight<<" kg"<<endl;
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string tn, float w){
        trackingNumber = tn;
        weight = w;
    }
    void estimateDeliveryTime() override {
        double time = 3 + (weight / 5); //own made shipment formula
        cout<<"Estimated Ground Delivery Time: "<<time<<" days"<<endl;
    }

    void showDetails(){
        cout<<"Ground Shipment"<< endl;
        cout<<"Tracking Number: "<<trackingNumber<<endl;
        cout<<"Weight: "<< weight<<" kg"<<endl;
    }
};
    

int main(){
    Shipment* shipment1 = new AirFreight("01", 20.5);
    Shipment* shipment2 = new GroundShipment("02", 20.5);

    shipment1->showDetails();
    shipment1->estimateDeliveryTime();
    cout << endl;

    shipment2->showDetails();
    shipment2->estimateDeliveryTime();
    cout << endl;
    return 0;
}