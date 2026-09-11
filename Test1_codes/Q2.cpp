// Q2. Drone Battery Monitor
#include <iostream>
using namespace std;

class Drone {
    int droneID;
    float batteryPercentage, flightHours;

public:
    Drone() : droneID(0), batteryPercentage(0), flightHours(0) {}

    void setID(int id) { droneID = id; }

    void update(float battery) {                     // overload 1
        batteryPercentage = battery;
    }

    void update(float battery, float hours) {         // overload 2
        batteryPercentage = battery;
        flightHours = hours;
    }

    void display() const {
        cout << "Drone ID: " << droneID << " | Battery: " << batteryPercentage
             << "% | Flight Hours: " << flightHours << endl;
    }

    friend void compareBattery(const Drone& d1, const Drone& d2);
};

void compareBattery(const Drone& d1, const Drone& d2) {
    cout << "\nComparing Drone " << d1.droneID << " and Drone " << d2.droneID << ":\n";
    if (d1.batteryPercentage > d2.batteryPercentage)
        cout << "Drone " << d1.droneID << " has higher battery.\n";
    else if (d2.batteryPercentage > d1.batteryPercentage)
        cout << "Drone " << d2.droneID << " has higher battery.\n";
    else
        cout << "Both drones have equal battery levels.\n";
}

int main() {
    int n;
    cout << "Enter number of drones: ";
    cin >> n;

    Drone* drones = new Drone[n];

    for (int i = 0; i < n; i++) {
        drones[i].setID(i + 1);
        int choice;
        float battery, hours;
        cout << "\nDrone " << (i + 1) << " - Enter 1 (battery only) or 2 (battery + hours): ";
        cin >> choice;
        cout << "  Battery %: ";
        cin >> battery;

        if (choice == 1) {
            (drones + i)->update(battery);
        } else {
            cout << "  Flight hours: ";
            cin >> hours;
            (drones + i)->update(battery, hours);
        }
    }

    cout << "\n----- Drone Status -----\n";
    for (int i = 0; i < n; i++)
        (drones + i)->display();

    if (n >= 2) {
        int a, b;
        cout << "\nEnter two drone indices (1 to " << n << ") to compare: ";
        cin >> a >> b;
        if (a >= 1 && a <= n && b >= 1 && b <= n)
            compareBattery(drones[a - 1], drones[b - 1]);
    }

    delete[] drones;
    return 0;
}