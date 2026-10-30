// Q5: Smart Agriculture - Hybrid Inheritance (virtual inheritance)
#include <iostream>
using namespace std;

class Sensor {
protected:
    int id;
public:
    Sensor(int i = 0) : id(i) {}
};

class Temperature : virtual public Sensor {
protected:
    double temp;
public:
    Temperature(double t) : temp(t) {}
};

class Humidity : virtual public Sensor {
protected:
    double hum;
public:
    Humidity(double h) : hum(h) {}
};

class FarmMonitor : public Temperature, public Humidity {
public:
    // most-derived class initialises the single shared Sensor
    FarmMonitor(int i, double t, double h) : Sensor(i), Temperature(t), Humidity(h) {}
    void display() {
        cout << "\nSensor ID: " << id << "\nTemperature: " << temp
             << " C\nHumidity: " << hum << " %\n";
        if (temp > 35) cout << "WARNING: Temperature above 35 C!!!!!!\n";
        if (hum > 80)  cout << "WARNING: Humidity above 80%!!!!!\n";
    }
};

int main() {
    int id; double t, h;
    cout << "Enter sensor ID, temperature (C), humidity (%): ";
    cin >> id >> t >> h;
    FarmMonitor f(id, t, h);
    f.display();
}