#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int elements[2][2];

public:
    friend class MatrixHelper;

    Matrix2x2(int a, int b, int c, int d) {
        elements[0][0] = a;
        elements[0][1] = b;
        elements[1][0] = c;
        elements[1][1] = d;
    }

    Matrix2x2 operator+(Matrix2x2& other) {
        return Matrix2x2(
            elements[0][0] + other.elements[0][0], elements[0][1] + other.elements[0][1],
            elements[1][0] + other.elements[1][0], elements[1][1] + other.elements[1][1]
        );
    }

    Matrix2x2 operator-(Matrix2x2& other) {
        return Matrix2x2(
            elements[0][0] - other.elements[0][0], elements[0][1] - other.elements[0][1],
            elements[1][0] - other.elements[1][0], elements[1][1] - other.elements[1][1]
        );
    }

    Matrix2x2 operator*(Matrix2x2& other) {
        return Matrix2x2(
            elements[0][0] * other.elements[0][0] + elements[0][1] * other.elements[1][0],
            elements[0][0] * other.elements[0][1] + elements[0][1] * other.elements[1][1],
            elements[1][0] * other.elements[0][0] + elements[1][1] * other.elements[1][0],
            elements[1][0] * other.elements[0][1] + elements[1][1] * other.elements[1][1]
        );
    }

    friend int determinant(Matrix2x2& matrix) {
        return (matrix.elements[0][0] * matrix.elements[1][1]) - 
               (matrix.elements[0][1] * matrix.elements[1][0]);
    }

    friend ostream& operator<<(ostream& os,Matrix2x2& matrix) {
        os << matrix.elements[0][0] << " " << matrix.elements[0][1] << endl;
        os << matrix.elements[1][0] << " " << matrix.elements[1][1] << endl;
        return os;
    }


};

class MatrixHelper {
public:
    static void updateElement(Matrix2x2& matrix, int row, int col, int value) {
        if (row >= 0 && row < 2 && col >= 0 && col < 2) {
            matrix.elements[row][col] = value;
        } else {
            cout << "Invalid index" << endl;
        }
    }
};

int main() {
    Matrix2x2 mat1(1, 2, 3, 4);
    Matrix2x2 mat2(5, 6, 7, 8);

    cout << "Matrix 1:\n" << mat1;
    cout << "Matrix 2:\n" << mat2;

    Matrix2x2 sum = mat1 + mat2;
    cout << "Sum of Matrices:\n" << sum;

    Matrix2x2 diff = mat1 - mat2;
    cout << "Difference of Matrices:\n" << diff;

    Matrix2x2 product = mat1 * mat2;
    cout << "Product of Matrices:\n" << product;

    cout << "Determinant of Matrix 1: " << determinant(mat1) << endl;
    cout << "Determinant of Matrix 2: " << determinant(mat2) << endl;

    MatrixHelper::updateElement(mat1, 0, 1, 10);
    cout << "Matrix 1 after updating element at (0,1) to 10:\n" << mat1;

    return 0;
}
