#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    
    cout << "Enter the dimensions of the 3D array"<<endl;

    cout<<"x: ";
    cin >> x;

    cout<<"y: ";
    cin >> y;
    
    cout<<"z: ";
    cin >> z;

    int ***array = new int**[x];
    for (int i = 0; i < x; i++) {
        array[i] = new int*[y];
        for (int j = 0; j < y; j++) {
            array[i][j] = new int[z];
        }
    }

    cout << "Enter elements of the 3D array:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "enter the element for x" << i+1 << " y"<< j+1 << " z"<< k+1 << ": ";
                cin >> array[i][j][k];
            }
        }
    }

    cout << "\n3D Array Elements:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
               cout << "enter the element for x" << i+1 << " y "<< j+1 << " z "<< k+1 << ": " << array[i][j][k] << endl;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
