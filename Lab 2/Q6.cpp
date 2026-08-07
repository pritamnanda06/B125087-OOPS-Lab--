#include <iostream>
using namespace std;

// Class to store and add two time values
class Time {
private:
    int hours;
    int minutes;

public:
    // Function to input time values
    void inputTime() {
        cout << "Enter Hours: ";
        cin >> hours;
        cout << "Enter Minutes: ";
        cin >> minutes;
    }

    // Function to add two time objects
    Time addTime(const Time& t2) const {
        Time result;
        result.minutes = minutes + t2.minutes;
        result.hours = hours + t2.hours + (result.minutes / 60);
        result.minutes %= 60;
        return result;
    }

    // Function to display resulting time
    void displayTime() const {
        cout << hours << " hr " << minutes << " min" << endl;
    }
};

int main() {
    Time t1, t2, t3;
    cout << "Enter First Time Value:" << endl;
    t1.inputTime();

    cout << "\nEnter Second Time Value:" << endl;
    t2.inputTime();

    t3 = t1.addTime(t2);

    cout << "\nTotal Time: ";
    t3.displayTime();
    return 0;
}