#include <iostream>
#include <exception>

using namespace std;

class InvalidTemperatureException : public exception
{
};

template <typename T>
T convertToFahrenheit(T celsius)
{
    double ABSOLUTE_ZERO = -273.15;
    if (celsius < ABSOLUTE_ZERO)
    {
        throw InvalidTemperatureException();
    }
    return (celsius * 9.0 / 5.0) + 32;
}

int main()
{
    try
    {
        double temp = -300.0;
        cout << "Attempting to convert " << temp << "C ..." << endl;
        double fahrenheit = convertToFahrenheit(temp);
        cout << "Fahrenheit: " << fahrenheit << "F" << endl;
    }
    catch (const InvalidTemperatureException &e)
    {
        cerr << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    return 0;
}
