#include <iostream>
#include <string>
using namespace std;

// Class to manage mobile recharge and plan deductions
class MobileRecharge {
private:
    string mobileNumber;
    string customerName;
    double currentBalance;

public:
    // Function to accept customer details
    void acceptDetails() {
        cout << "Enter Mobile Number: ";
        cin >> mobileNumber;
        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, customerName);
        cout << "Enter Initial Balance: ";
        cin >> currentBalance;
    }

    // Function to add funds
    void recharge(double amount) {
        if (amount > 0) {
            currentBalance += amount;
            cout << "Recharged successfully! Added: " << amount << endl;
        }
    }

    // Function to deduct balance for plan selection
    void deductBalance(double planCost) {
        if (planCost <= currentBalance) {
            currentBalance -= planCost;
            cout << "Plan purchased successfully! Deducted: " << planCost << endl;
        } else {
            cout << "Error: Plan cost exceeds available balance!" << endl;
        }
    }

    // Function to display updated balance
    void displayBalance() const {
        cout << "\n--- Account Summary ---" << endl;
        cout << "Mobile Number   : " << mobileNumber << endl;
        cout << "Customer Name   : " << customerName << endl;
        cout << "Current Balance : " << currentBalance << endl;
    }
};

int main() {
    MobileRecharge user;
    user.acceptDetails();

    double topUp, planCost;
    cout << "\nEnter amount to recharge: ";
    cin >> topUp;
    user.recharge(topUp);

    cout << "Enter cost of plan to select: ";
    cin >> planCost;
    user.deductBalance(planCost);

    user.displayBalance();
    return 0;
}