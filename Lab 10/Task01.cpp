#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream in;
    in.open("Vehicels.txt");

    if(in.is_open()){
        string data;
        while(in.eof()==0){
            getline(in,data);
            cout<<data<<endl;
        }
    }else{
        cout<<"sorry the find could not be opened.\n";
    }
}