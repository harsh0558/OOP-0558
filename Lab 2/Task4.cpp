#include <iostream>
using namespace std;

int main(){
    int numOfStrings;
    cout<<"enter the number of strings: ";
    cin>>numOfStrings;

    string *strings = new string[numOfStrings];

    for(int i=0;i<numOfStrings;i++){
        cout<<"enter the string "<< i+1<<" : ";
        cin>>strings[i];
    }

    bool swap = true;
    int boundary = numOfStrings-1;

    while(swap==true){
        swap =false;
        for(int i=0;i<boundary;i++){
            if(strings[i][0]>strings[i+1][0]){
                string temp = strings[i];
                strings[i] = strings[i+1];
                strings[i+1] = temp;
                swap = true;
            }
        }
        boundary--;
    }

    cout<<"sorted strings"<<endl;

    for(int i=0;i<numOfStrings;i++){
        cout<<strings[i]<<endl;
    }

    delete[] strings;
    
    return 0;
}