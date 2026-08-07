#include <iostream>
#include <string>
using namespace std;

// Class to calculate ticket booking total cost
class MovieTicket {
private:
    string movieName;
    double ticketPrice;
    int numTickets;

public:
    // Function to accept booking details
    void acceptBooking() {
        cout << "Enter Movie Name: ";
        getline(cin, movieName);
        cout << "Enter Ticket Price: ";
        cin >> ticketPrice;
        cout << "Enter Number of Tickets: ";
        cin >> numTickets;
    }

    // Function to calculate total cost
    double calculateTotalCost() const {
        return ticketPrice * numTickets;
    }

    // Function to display booking summary
    void displaySummary() const {
        cout << "\n--- Ticket Booking Summary ---" << endl;
        cout << "Movie Name : " << movieName << endl;
        cout << "Price/Ticket: " << ticketPrice << endl;
        cout << "No. Tickets : " << numTickets << endl;
        cout << "Total Cost  : " << calculateTotalCost() << endl;
    }
};

int main() {
    MovieTicket ticket;
    ticket.acceptBooking();
    ticket.displaySummary();
    return 0;
}