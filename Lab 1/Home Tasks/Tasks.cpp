#include <iostream>

using namespace std;

int main(){

    // Home task 1

    string city[4];
    int AQI[4][7]; 
    float avgAQI[4];
    int total;

    for(int i=0;i<4;i++){
        total=0;
        cout<<"enter the name of city "<< i+1<<": ";
        cin >> city[i];
        for(int j=0;j<7;j++){
            cout<<"enter the AQI for "<<city[i]<<" for day "<<j+1<<": ";
            cin>>AQI[i][j]; 
            total += AQI[i][j];
        }
        float avg = (float)total/7;
        avgAQI[i] = avg;
    }

    float highest =0;
    int index;
    for(int i=0;i<4;i++){
        cout<<"Avg AQI for "<<city[i]<<" is: "<< avgAQI[i]<<endl;
        if(avgAQI[i]>highest){
            highest = avgAQI[i];
            index = i;
        }
    }

    cout<<"the highest AQI is "<< highest<<" of city "<<city[index]<<endl;

    // Home task 2

    cout<<"critical pollution days"<<endl;
    for(int i=0;i<4;i++){
        cout<<"for "<<city[i]<<":"<<endl;
        for(int j=0;j<7;j++){
            if(AQI[i][j]>150){  
                cout<<"on day "<<j+1<<" the AQI was "<<AQI[i][j]<<endl;
            }
        }
    }

    return 0;
}
