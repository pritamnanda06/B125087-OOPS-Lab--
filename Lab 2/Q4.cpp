#include <iostream>
#include <string>
using namespace std;

// Class to handle hotel room booking and rent calculation
class HotelRoom {
private:
    int roomNumber;
    string guestName;
    int daysStayed;
    double costPerDay;

public:
    // Function to accept booking details
    void acceptBooking() {
        cout << "Enter Room Number: ";
        cin >> roomNumber;
        cin.ignore();
        cout << "Enter Guest Name: ";
        getline(cin, guestName);
        cout << "Enter Number of Days Stayed: ";
        cin >> daysStayed;
        cout << "Enter Cost Per Day: ";
        cin >> costPerDay;
    }

    // Function to calculate total room rent
    double calculateTotalRent() const {
        return daysStayed * costPerDay;
    }

    // Function to display booking details
    void displayBooking() const {
        cout << "\n--- Booking Summary ---" << endl;
        cout << "Room Number : " << roomNumber << endl;
        cout << "Guest Name  : " << guestName << endl;
        cout << "Days Stayed : " << daysStayed << endl;
        cout << "Cost/Day    : " << costPerDay << endl;
        cout << "Total Rent  : " << calculateTotalRent() << endl;
    }
};

int main() {
    HotelRoom room;
    room.acceptBooking();
    room.displayBooking();
    return 0;
}