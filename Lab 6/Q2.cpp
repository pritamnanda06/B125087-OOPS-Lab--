#include <iostream>
using namespace std;

class Duration {
public:
    int h, m;
    Duration(int hh = 0, int mm = 0) { h = hh; m = mm; }
    Duration operator+(Duration d) {
        int total = m + d.m;
        return Duration(h + d.h + total / 60, total % 60);
    }
};

int main() {
    int h1, m1, h2, m2;
    cout << "Enter hours and minutes of duration 1: ";
    cin >> h1 >> m1;
    cout << "Enter hours and minutes of duration 2: ";
    cin >> h2 >> m2;

    Duration d1(h1, m1), d2(h2, m2), d3 = d1 + d2;
    cout << "Duration 1: " << d1.h << " hr " << d1.m << " min\n";
    cout << "Duration 2: " << d2.h << " hr " << d2.m << " min\n";
    cout << "Total     : " << d3.h << " hr " << d3.m << " min\n";
}