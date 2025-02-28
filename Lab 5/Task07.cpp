#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;

public:
    Product(int i, string n, int q) {
        id = i;
        name = n;
        quantity = q;
    }

    string getName(){
        return name;
    }
    int getId(){
        return id;
    }

    void details()  {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

class Warehouse {
private:
    vector<Product> inventory;
    int productCount; 

public:
    Warehouse(){
        productCount =0;
    }

    void addProduct(Product p) {
        inventory.push_back(p);
        productCount++; 
    }

    void sortProducts() {
        for (int i = 0; i < productCount - 1; i++) {
            for (int j = 0; j < productCount - i - 1; j++) {
                if (inventory[j].getName() > inventory[j + 1].getName()) {
                    swap(inventory[j], inventory[j + 1]);
                }
            }
        }
    }

    void searchProduct(int searchId) {
        for (int i = 0; i < productCount; i++) { 
            if (inventory[i].getId() == searchId) {
                cout << "Product Found: ";
                inventory[i].details();
                return;
            }
        }
        cout << "Product with ID " << searchId << " not found." << endl;
    }

    void displayInventory() {
        cout << "Warehouse Inventory:" << endl;
        for (int i = 0; i < productCount; i++) { 
            inventory[i].details();
        }
        cout << endl;
    }
};

int main() {
    Warehouse warehouse;

    warehouse.addProduct(Product(101, "Laptop", 10));
    warehouse.addProduct(Product(102, "Chair", 25));
    warehouse.addProduct(Product(103, "Apple", 50));

    warehouse.sortProducts();

    cout << "----- Sorted Inventory -----" << endl;
    warehouse.displayInventory();

    cout << "----- Searching for Product with ID 102 -----" << endl;
    warehouse.searchProduct(102);

    return 0;
}
