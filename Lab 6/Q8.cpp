#include <iostream>
using namespace std;

class Temperature {
    double celsius;
public:
    Temperature(double c = 0) : celsius(c) {}
    void input(const char* name) {
        cout << "Enter temperature of " << name << " (Celsius): ";
        cin >> celsius;
    }
    bool operator>(const Temperature& o) const { return celsius > o.celsius; }
    bool operator<(const Temperature& o) const { return celsius < o.celsius; }
    Temperature operator-() const { return Temperature(-celsius); }
    void display() const { cout << celsius << " C"; }
};

int main() {
    Temperature t1, t2;
    t1.input("Temperature 1");
    t2.input("Temperature 2");
    cout << "\nT1 = "; t1.display();
    cout << "\nT2 = "; t2.display();
    cout << "\n\nT1 > T2 : " << (t1 > t2 ? "true" : "false") << endl;
    cout << "T1 < T2 : " << (t1 < t2 ? "true" : "false") << endl;
    Temperature neg = -t1;
    cout << "-T1     : "; neg.display();
    cout << "\nT1 still: "; t1.display();
    cout << endl;
    return 0;
}