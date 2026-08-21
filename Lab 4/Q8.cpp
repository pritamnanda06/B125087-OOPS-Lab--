#include <iostream>
#include <string>
using namespace std;

class VehicleService {
private:
    string vehicleNumber;
    string ownerName;
    bool serviceDueStatus;
    double lastServiceKilometres;

public:
    void acceptData() {
        cout << "Enter Vehicle Number: ";
        cin >> vehicleNumber;
        cout << "Enter Owner Name: ";
        cin.ignore();
        getline(cin, ownerName);
        cout << "Enter Service Due Status (1 for Due, 0 for Not Due): ";
        cin >> serviceDueStatus;
        cout << "Enter Last Service Kilometres: ";
        cin >> lastServiceKilometres;
    }

    // Declare ServiceManager as a friend class
    friend class ServiceManager;
};

class ServiceManager {
public:
    void displayInfo(const VehicleService& v) {
        cout << "\n--- Vehicle Service Information ---" << endl;
        cout << "Vehicle Number: " << v.vehicleNumber << endl;
        cout << "Owner Name: " << v.ownerName << endl;
        cout << "Service Due Status: " << (v.serviceDueStatus ? "Service Due" : "Up to Date") << endl;
        cout << "Last Service Kilometres: " << v.lastServiceKilometres << " km" << endl;
    }

    void markServiceCompleted(VehicleService& v) {
        v.serviceDueStatus = false;
        cout << "Service marked as completed for vehicle " << v.vehicleNumber << "." << endl;
    }

    void updateLastServiceKm(VehicleService& v, double km) {
        v.lastServiceKilometres = km;
        cout << "Last service kilometres updated to " << v.lastServiceKilometres << " km." << endl;
    }

    void checkServiceRequirement(const VehicleService& v, double currentKm) {
        if (v.serviceDueStatus || (currentKm - v.lastServiceKilometres >= 10000)) {
            cout << "Vehicle " << v.vehicleNumber << " requires servicing!" << endl;
        } else {
            cout << "Vehicle " << v.vehicleNumber << " does not require servicing yet." << endl;
        }
    }
};

int main() {
    VehicleService vehicle;
    vehicle.acceptData();
    ServiceManager sm;

    sm.displayInfo(vehicle);
    double currentKm;
    cout << "Enter current vehicle kilometres to check service requirement: ";
    cin >> currentKm;
    sm.checkServiceRequirement(vehicle, currentKm);
    sm.markServiceCompleted(vehicle);
    sm.displayInfo(vehicle);

    return 0;
}