#include <iostream>
using namespace std;

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter rows for first matrix: ";
    cin >> rows1;
    cout << "Enter cols for first matrix: ";
    cin>> cols1;
    cout << "Enter rows for second matrix: ";
    cin >> rows2;
    cout << "Enter cols for second matrix: ";
    cin>> cols2;

    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible"<< endl;
    }


    int **matrix1 = new int*[rows1];
    int **matrix2 = new int*[rows2];
    int **resultant = new int*[rows1];

    for (int i = 0; i < rows1; i++){
        matrix1[i] = new int[cols1];
    }

    for (int i = 0; i < rows2; i++){
        matrix2[i] = new int[cols2];
    }

    for (int i = 0; i < rows1; i++){
        resultant[i] = new int[cols2];
    }

    cout << "Enter elements of first matrix" << endl;
    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < cols1; j++){
            cout << "Enter element for row " << i+1<< " col "<<j+1<<": ";
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < rows2; i++){
        for (int j = 0; j < cols2; j++){
            cout << "Enter element for row " << i+1<< " col "<<j+1<<": ";
            cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            resultant[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                resultant[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "Resultant Matrix" << endl;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << resultant[i][j] <<" ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows1; i++) delete[] matrix1[i];
    for (int i = 0; i < rows2; i++) delete[] matrix2[i];
    for (int i = 0; i < rows1; i++) delete[] resultant[i];
    delete[] matrix1;
    delete[] matrix2;
    delete[] resultant;

    return 0;
}
