#include <iostream>
#include <string>
using namespace std;

class Weather {
private:
    string cityName;
    double temperature;
    string weatherCondition;

public:
    void inputData() {
        cout << "Enter City Name: ";
        getline(cin, cityName);
        cout << "Enter Temperature (°C): ";
        cin >> temperature;
        cin.ignore();
        cout << "Enter Weather Condition: ";
        getline(cin, weatherCondition);
    }

    friend void generateReport(const Weather& w);
};

void generateReport(const Weather& w) {
    cout << "\n--- Weather Report ---" << endl;
    cout << "City Name: " << w.cityName << endl;
    cout << "Temperature: " << w.temperature << " °C" << endl;
    cout << "Weather Condition: " << w.weatherCondition << endl;
    cout << "Classification: ";
    if (w.temperature > 35.0) {
        cout << "Very Hot" << endl;
    } else if (w.temperature >= 20.0 && w.temperature <= 35.0) {
        cout << "Pleasant" << endl;
    } else {
        cout << "Cool" << endl;
    }
}

int main() {
    Weather w;
    w.inputData();
    generateReport(w);
    return 0;
}