#include <iostream>

using namespace std;

int main(){

    // Lab task 1

    string event1[5];
    string event2[5];

    for(int i=0;i<5;i++){
        cout << "enter the name of the participant of event 1: ";
        cin >> event1[i];

        cout << "enter the name of the participant of event 2 : ";
        cin >> event2[i];
    }

    // lab task 2
    bool isPresent;

    string name;

    cout<< "enter the name of the participant: ";
    cin>>name;


    for(int i=0;i<5;i++){
        if(name==event1[i] || name==event2[i]){
            isPresent =true;
            break;
        }
    }

    if(isPresent==true){
        cout<<"the participant entered is present"<<endl;
    }else{
        cout<<"the participant entered is not present"<<endl;
    }

    // lab task 3

    int total=0;
    int num;
    cout<<"FOR EVENT 1"<< endl;

    for(int i=0;i<5;i++){
        cout<<"enter the amount donated by "<<event1[i]<<": ";
        cin>>num;
        total +=num+10;
    }

    cout<< "total donations from event 1: "<<total <<endl;

    total=0;
    cout<<"FOR EVENT 2"<< endl;

    for(int i=0;i<5;i++){
        cout<<"enter the amount donated by "<<event2[i]<<": ";
        cin>>num;
        total +=num+10;
    }

    cout<< "total donations from event 2: "<<total<< endl;

    // lab task 4

    cout<<"participants of event 1 (reversed)"<<endl;

    string revString1[5];
    string revString2[5];

    for(int i=0;i<5;i++){
        int length = event1[i].length();
        int rev = length-1;
        string temp = "";
        for(int j=0;j<length;j++){
            temp = temp + event1[i][rev];
            rev--;
        }
         revString1[i] =temp;
        cout<<"participant "<< i+1 <<":"<< revString1[i]<<endl;
    }

    cout<<"participants of event 2 (reversed)"<<endl;
    for(int i=0;i<5;i++){
        int length = event2[i].length();
        int rev = length-1;
        string temp = "";
        for(int j=0;j<length;j++){
            temp = temp + event2[i][rev];
            rev--;
        }
         revString1[i] =temp;
        cout<<"participant "<< i+1 <<":"<< revString1[i]<<endl;
    }
}
