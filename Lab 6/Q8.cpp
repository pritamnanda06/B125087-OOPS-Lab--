#include <iostream>
using namespace std;

class Temperature {
public:
    double c;
    Temperature(double x = 0) { c = x; }
    bool operator>(Temperature t) { return c > t.c; }
    bool operator<(Temperature t) { return c < t.c; }
    Temperature operator-() { return Temperature(-c); }
};

int main() {
    double x, y;
    cout << "Enter temperature 1 (Celsius): ";
    cin >> x;
    cout << "Enter temperature 2 (Celsius): ";
    cin >> y;

    Temperature t1(x), t2(y), neg = -t1;
    cout << "T1 > T2 : " << (t1 > t2 ? "true" : "false") << endl;
    cout << "T1 < T2 : " << (t1 < t2 ? "true" : "false") << endl;
    cout << "-T1     : " << neg.c << " C (T1 is still " << t1.c << " C)\n";
}