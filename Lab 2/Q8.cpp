#include <iostream>
#include <string>
using namespace std;

// Class to manage hostel fee and late fine logic
class HostelFee {
private:
    string studentName;
    string hostelID;
    double monthlyFee;
    int numMonths;
    bool isDelayed;

public:
    // Function to accept student details
    void acceptDetails() {
        cout << "Enter Student Name: ";
        getline(cin, studentName);
        cout << "Enter Hostel ID: ";
        cin >> hostelID;
        cout << "Enter Monthly Fee: ";
        cin >> monthlyFee;
        cout << "Enter Number of Months: ";
        cin >> numMonths;

        char choice;
        cout << "Is the payment delayed? (y/n): ";
        cin >> choice;
        isDelayed = (choice == 'y' || choice == 'Y');
    }

    // Function to calculate final amount payable
    double calculateFinalAmount() const {
        double total = monthlyFee * numMonths;
        if (isDelayed) {
            total += 500.0; // Apply 500 late fine
        }
        return total;
    }

    // Function to display final statement
    void displayFeeDetails() const {
        cout << "\n--- Hostel Fee Statement ---" << endl;
        cout << "Student Name : " << studentName << endl;
        cout << "Hostel ID    : " << hostelID << endl;
        cout << "Base Fee     : " << (monthlyFee * numMonths) << endl;
        cout << "Late Fine    : " << (isDelayed ? "500 (Applied)" : "0 (Not Applied)") << endl;
        cout << "Total Payable: " << calculateFinalAmount() << endl;
    }
};

int main() {
    HostelFee student;
    student.acceptDetails();
    student.displayFeeDetails();
    return 0;
}