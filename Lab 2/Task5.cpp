#include <iostream>
using namespace std;

int main(){
    int num;
    
    cout << "Enter the number of elements you want to enter: ";
    cin >> num;
    
    int *numArray = new int[num];

    for(int i = 0; i < num; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> numArray[i];
    }   

    int *ptr = &numArray[0];
    int sum=0;

    cout << "The elements you entered are"<<endl;

    for(int i = 0; i < num; i++){
        cout<<"element "<<i+1<<": " << *ptr << endl;
        sum += *ptr;
        ptr++;
    }

    cout<<"the sum of the entred elements is: "<<sum<<endl;

    delete[] numArray;
    
    return 0;
}