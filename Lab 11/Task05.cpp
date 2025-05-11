#include <iostream>
#include <exception>

using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template <class T>
class InventoryItem {
    T stock;
    T maxLimit;

public:
    InventoryItem(T limit) {
        stock = 0;
        maxLimit = limit;
    }

    void setStock(T s) {
        if (s < 0) {
            throw NegativeStockException();
        }
        if (s > maxLimit) {
            throw OverCapacityException();
        }
        stock = s;
        cout << "Stock is now set to " << stock << endl;
    }
};

int main() {
    InventoryItem<int> item(100);

    try {
        cout << "Trying to set stock to -5..." << endl;
        item.setStock(-5);
    } catch (NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try {
        cout << "\nTrying to set stock to 120..." << endl;
        item.setStock(120);
    } catch (OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    return 0;
}
