#include <iostream>
using namespace std;

// Class to convert temperature from Celsius to Fahrenheit
class Temperature {
private:
    double celsius;
    double fahrenheit;

public:
    // Function to accept temperature in Celsius
    void acceptCelsius() {
        cout << "Enter temperature in Celsius: ";
        cin >> celsius;
    }

    // Function to convert Celsius to Fahrenheit
    void convertToFahrenheit() {
        fahrenheit = (9.0 / 5.0) * celsius + 32;
    }

    // Function to display temperatures
    void displayTemperatures() const {
        cout << "\n--- Temperature Conversion ---" << endl;
        cout << "Celsius    : " << celsius << " C" << endl;
        cout << "Fahrenheit : " << fahrenheit << " F" << endl;
    }
};

int main() {
    Temperature temp;
    temp.acceptCelsius();
    temp.convertToFahrenheit();
    temp.displayTemperatures();
    return 0;
}