#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter the number of elements: ";
    cin >> num;

    int *numbers = new int[num];

    for(int i=0;i<num;i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> numbers[i];
    }

    cout<<"the elements are: ";

    for(int i=0;i<num;i++){
        cout << numbers[i] << " ";
    }

    delete [] numbers;
    
    return 0;
}