#include <iostream>
using namespace std;

class Duration {
    int hours, minutes;
public:
    Duration(int h = 0, int m = 0) : hours(h), minutes(m) {}
    void input(const char* name) {
        cout << "Enter hours and minutes of " << name << ": ";
        cin >> hours >> minutes;
    }
    Duration operator+(const Duration& o) const {
        int totalMin = minutes + o.minutes;
        return Duration(hours + o.hours + totalMin / 60, totalMin % 60);
    }
    void display() const {
        cout << hours << " hr " << minutes << " min";
    }
};

int main() {
    Duration d1, d2;
    d1.input("Duration 1");
    d2.input("Duration 2");
    Duration result = d1 + d2;
    cout << "\nDuration 1 : "; d1.display();
    cout << "\nDuration 2 : "; d2.display();
    cout << "\nTotal      : "; result.display();
    cout << endl;
    return 0;
}