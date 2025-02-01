#include <iostream>
using namespace std;

struct Product{
    string name;
    string productId;
    int quantity;
    float price;
};

int main(){
    int numOfProducts;
    float totalValue=0;
    
    cout << "Enter the number of products: ";
    cin >> numOfProducts;

    Product *products = new Product[numOfProducts];

    for(int i=0;i<numOfProducts;i++){
        cout << "Enter product " << i+1 << " name: ";
        cin >> products[i].name;
        cout << "Enter product " << i+1 << " id: ";
        cin >> products[i].productId;
        cout << "Enter product " << i+1 << " quantity: ";
        cin >> products[i].quantity;
        cout << "Enter product " << i+1 << " price: ";
        cin >> products[i].price;
        totalValue += products[i].price * products[i].quantity;
    }

    cout<<"the total value of the inventory is: " << totalValue << endl;    

    delete [] products;

    return 0;
}