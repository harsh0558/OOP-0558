#include <iostream>
#include <vector>
#include <exception>
#include <sstream>

using namespace std;

class DimensionMismatchException : public exception
{
private:
    string message;

public:
    DimensionMismatchException(int r1, int c1, int r2, int c2)
    {
        ostringstream oss;
        oss << "DimensionMismatchException - Matrices must have same dimensions ("
            << r1 << "x" << c1 << " vs " << r2 << "x" << c2 << ") !";
        message = oss.str();
    }

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

template <typename T>
class Matrix
{
private:
    vector<vector<T>> data;
    int rows, cols;

public:
    Matrix(int r, int c, T val = T()) : rows(r), cols(c), data(r, vector<T>(c, val)) {}

    void set(int r, int c, T val)
    {
        data[r][c] = val;
    }

    T get(int r, int c) const
    {
        return data[r][c];
    }

    int getRows()
    {
        return rows;
    }
    int getCols()
    {
        return cols;
    }

    Matrix<T> operator+(const Matrix<T> &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    void display() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << data[i][j] << " ";
            }
            cout << '\n';
        }
    }
};

int main()
{
    try
    {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        // Fill A
        A.set(0, 0, 1);
        A.set(0, 1, 2);
        A.set(1, 0, 3);
        A.set(1, 1, 4);

        // Fill B
        int val = 5;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                B.set(i, j, val++);

        Matrix<int> C = A + B;

        C.display();
    }
    catch (const DimensionMismatchException &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
