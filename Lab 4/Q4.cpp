#include <iostream>
#include <string>
using namespace std;

class ElectricMeter {
private:
    string meterNumber;
    string consumerName;
    double unitsConsumed;

public:
    void acceptData() {
        cout << "Enter Meter Number: ";
        cin >> meterNumber;
        cout << "Enter Consumer Name: ";
        cin.ignore();
        getline(cin, consumerName);
        cout << "Enter Units Consumed: ";
        cin >> unitsConsumed;
    }

    // Friend function declaration
    friend void checkUsage(const ElectricMeter& em);
};

// Friend function definition
void checkUsage(const ElectricMeter& em) {
    cout << "\n--- Electricity Usage Alert ---" << endl;
    cout << "Meter Number: " << em.meterNumber << endl;
    cout << "Consumer Name: " << em.consumerName << endl;
    cout << "Units Consumed: " << em.unitsConsumed << endl;
    cout << "Usage Category: ";
    if (em.unitsConsumed < 100) {
        cout << "Low Usage" << endl;
    } else if (em.unitsConsumed >= 100 && em.unitsConsumed <= 300) {
        cout << "Moderate Usage" << endl;
    } else {
        cout << "High Usage" << endl;
    }
}

int main() {
    ElectricMeter meter;
    meter.acceptData();
    checkUsage(meter);
    return 0;
}