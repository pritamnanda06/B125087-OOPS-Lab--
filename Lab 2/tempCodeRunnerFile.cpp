#include <iostream>
#include <string>
using namespace std;

// Class to calculate tiered water bill based on slab rates
class WaterBill {
private:
    string consumerNumber;
    string consumerName;
    double consumption; // in litres

public:
    // Function to accept consumer details
    void acceptDetails() {
        cout << "Enter Consumer Number: ";
        cin >> consumerNumber;
        cin.ignore();
        cout << "Enter Consumer Name: ";
        getline(cin, consumerName);
        cout << "Enter Water Consumption (in litres): ";
        cin >> consumption;
    }

    // Function to calculate bill slab-wise
    double calculateBill() const {
        double bill = 0.0;
        double rem = consumption;

        if (rem > 1000) {
            bill += (rem - 1000) * 5.0; // Rate above 1000 litres
            rem = 1000;
        }
        if (rem > 500) {
            bill += (rem - 500) * 3.0;  // Rate for 501-1000 litres
            rem = 500;
        }
        if (rem > 0) {
            bill += rem * 2.0;          // Rate for first 500 litres
        }

        return bill;
    }

    // Function to display complete bill
    void displayBill() const {
        cout << "\n--- Water Bill Statement ---" << endl;
        cout << "Consumer Number  : " << consumerNumber << endl;
        cout << "Consumer Name    : " << consumerName << endl;
        cout << "Consumption (L)  : " << consumption << endl;
        cout << "Total Amount Due : " << calculateBill() << endl;
    }
};

int main() {
    WaterBill bill;
    bill.acceptDetails();
    bill.displayBill();
    return 0;
}