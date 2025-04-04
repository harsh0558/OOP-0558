#include <iostream>
using namespace std;

class Vector2D{
private:
    float x;
    float y;
public:
    friend float dotProduct(Vector2D &v1, Vector2D &v2);

    Vector2D(float a, float b){
        x = a;
        y = b;
    }

    Vector2D operator+(Vector2D &vector){
        Vector2D temp(0,0);
        temp.x = x + vector.x;
        temp.y = y + vector.y;
        return temp;
    }

    Vector2D operator-(Vector2D &vector){
        Vector2D temp(0,0);
        temp.x = x - vector.x;
        temp.y = y - vector.y;
        return temp;
    }

    Vector2D operator*(float num){
        return Vector2D(x*num,y*num);
    }

    friend ostream& operator<<(ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};


float dotProduct(Vector2D &v1, Vector2D &v2){
    return ((v1.x*v2.x)+(v1.y*v2.y));
}

int main(){
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;

    Vector2D sum = v1 + v2;
    cout << "Addition: " << sum << endl;

    Vector2D diff = v1 - v2;
    cout << "Subtraction: " << diff << endl;

    Vector2D scaled = v1 * 2;
    cout << "Scalar Multiplication (v1 * 2): " << scaled << endl;

    float dot = dotProduct(v1, v2);
    cout << "Dot Product: " << dot << endl;
    return 0;
}