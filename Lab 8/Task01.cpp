#include <iostream>
#include <cmath>
using namespace std;

class Complex{
private:
    float real;
    float imag;
public:
    Complex(float a, float b){
        real = a;
        imag = b;
    }

    friend float magnitude(Complex & complex);

    Complex operator+(Complex & other){
        Complex temp(0,0);
        temp.real = real + other.real;
        temp.imag = imag + other.imag;
        return temp;
    }

    Complex operator-(Complex & other){
        Complex temp(0,0);
        temp.real = real - other.real;
        temp.imag = imag - other.imag;
        return temp;
    }

    Complex operator*(Complex& other) {
        double newReal = (real * other.real) - (imag * other.imag);
        double newImag = (real * other.imag) + (imag * other.real);
        return Complex(newReal, newImag);
    }

    Complex operator/(Complex& other) {
        Complex temp(0,0);
        float denominator = (other.real * other.real) + (other.imag * other.imag);
        if (denominator == 0) {
            cout<<"Division by zero not possiable.\n";
        }
        float newReal = ((real * other.real) + (imag * other.imag)) / denominator;
        float newImag = ((imag * other.real) - (real * other.imag)) / denominator;
        temp.real = newReal;
        temp.imag = newImag;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << "(" << c.real;
        if (c.imag >= 0) 
            out << " + " << c.imag << "i)";
        else
            out << " - " << -c.imag << "i)";
        return out;
    }

};

float magnitude(Complex & complex){
    return sqrt((complex.real * complex.real) + (complex.imag * complex.imag));
}

int main() {
    Complex c1(3, 4);  
    Complex c2(1, -2);  

    cout << "Complex Number 1: " << c1 << endl;
    cout << "Complex Number 2: " << c2 << endl;

    Complex sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    Complex diff = c1 - c2;
    cout << "Difference: " << diff << endl;

    Complex product = c1 * c2;
    cout << "Product: " << product << endl;

    Complex quotient = c1 / c2;
    cout << "Quotient: " << quotient << endl;

    cout << "Magnitude of c1: " << magnitude(c1) << endl;
    cout << "Magnitude of c2: " << magnitude(c2) << endl;

    return 0;
}
