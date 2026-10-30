// Q1: Railway Ticket Fare - Single Inheritance
#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    string name;
    double distance;
public:
    Ticket(string n, double d) : name(n), distance(d) {}
};

class RailwayTicket : public Ticket {
    double rate;
public:
    RailwayTicket(string n, double d, double r) : Ticket(n, d), rate(r) {}
    void display() {
        double fare = distance * rate;
        if (distance > 300) fare *= 0.9;   // 10% discount
        cout << "\nPassenger: " << name << "\nDistance: " << distance
             << " km\nFinal Fare: Rs. " << fare << endl;
    }
};

int main() {
    string name; double d, r;
    cout << "Enter name, distance (km), fare per km: ";
    cin >> name >> d >> r;
    RailwayTicket t(name, d, r);
    t.display();
}