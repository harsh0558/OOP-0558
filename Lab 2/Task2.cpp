#include <iostream>
using namespace std;

int main(){
    int dimentions;

    cout<<"enter the dimentions of the matrices: ";
    cin>>dimentions;

    int **matrix1 = new int*[dimentions];
    int **matrix2 = new int*[dimentions];
    int **resultant = new int*[dimentions];

    for(int i=0;i<dimentions;i++){
        matrix1[i] = new int [dimentions];
        matrix2[i] = new int [dimentions];
        resultant[i] = new int [dimentions];
    }

    cout<<"Input elements for matrix 1"<<endl;

    for(int i=0;i<dimentions;i++){
        for(int j=0;j<dimentions;j++){
            cout<<"enter element for row "<<i+1<<" and col "<<j+1<<": ";
            cin>>matrix1[i][j];
        }
    }

    cout<<"Input elements for matrix 2"<<endl;

    for(int i=0;i<dimentions;i++){
        for(int j=0;j<dimentions;j++){
            cout<<"enter element for row "<<i+1<<" and col "<<j+1<<": ";
            cin>>matrix2[i][j];
        }
    }

    for(int i=0;i<dimentions;i++){
        for(int j=0;j<dimentions;j++){
            resultant[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    cout<<"the added matrix is"<<endl;
    cout<<"\n";

    for(int i=0;i<dimentions;i++){
        cout<<"|";
        for(int j=0;j<dimentions;j++){
            cout<<resultant[i][j]<<"|";
        }
        cout<<"\n";
    }

    for(int i=0;i<dimentions;i++){
        for(int j=0;j<dimentions;j++){
            resultant[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    cout<<"the subtracted matrix is"<<endl;
    cout<<"\n";

    for(int i=0;i<dimentions;i++){
        cout<<"|";
        for(int j=0;j<dimentions;j++){
            cout<<resultant[i][j]<<"|";
        }
        cout<<"\n";
    }

    for(int i = 0; i < dimentions; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] resultant[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] resultant;

    return 0;
}