#include <iostream>
using namespace std;

class Product{
public:
    string productID;
    string productName;
    float price;
    int stockQuantity;

    Product(string pi, string pn, float p, int sq){
        productID = pi;
        productName = pn;
        price = p;
        stockQuantity = sq;
    }

    void applyDiscount(){
    }

    float calculateTotalPrice(int quantity){
        return price*quantity;
    }

    void displayProductInfo(){
        cout<<"Product ID: "<<productID<<endl;
        cout<<"Product Name: "<<productName<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Stock Quantity: "<<stockQuantity<<endl;
    }

    float operator +(Product p){
        return price+p.price;
    }

};

class Electronics: public Product{
private:
    string warrantyPeriod;
    string brand;
public:

    Electronics(string pi, string pn, float p, int sq,string wp, string b): Product( pi,  pn,  p,  sq){
        warrantyPeriod = wp;
        brand = b;
    }

    void displayProductInfo(){
        cout<<"Product ID: "<<productID<<endl;
        cout<<"Product Name: "<<productName<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Stock Quantity: "<<stockQuantity<<endl;
        cout<<"Warranty Period: "<<warrantyPeriod<<endl;
        cout<<"Stock Quantity: "<<stockQuantity<<endl;
    }
};

class Clothing: public Product{
private:
    int size;
    string color;
    string fabricMaterial;
public:
    Clothing(string pi, string pn, float p, int sq,int s,string c,string fm): Product( pi,  pn,  p,  sq){
        size = s;
        color = c;
        fabricMaterial = fm;
    }

    void applyDiscount(float value){
        price = price*(value/100);
    }
};

class FoodItem: public Product{
private:
    string expirationDate;
    float calories;
public:
    FoodItem(string pi, string pn, float p, int sq,string ed,float c): Product( pi,  pn,  p,  sq){
        expirationDate = ed;
        calories = c;
    }

    float calculateTotalPrice(){
        int quantity;
        float price;
        cout<<"Enter the quantity: ";
        cin>>quantity;
        cout<<"Enter discounted price: ";
        cin>>price;
        return price*quantity;
    }
};

class Book: public Product{
private:
    string author;
    string genre;
public:
    Book(string pi, string pn, float p, int sq,string a, string g): Product( pi,  pn,  p,  sq){
        author = a;
        genre = g;
    }

    void displayProductInfo(){
        cout<<"Product ID: "<<productID<<endl;
        cout<<"Product Name: "<<productName<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Stock Quantity: "<<stockQuantity<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Genre: "<<genre<<endl;
    }
};

