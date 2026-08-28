#include <iostream>
using namespace std;

void convert(int km) {
    cout << km << " kilometers = " << km * 1000 << " meters." << endl;
}

void convert(double m) {
    cout << m << " meters = " << m * 100 << " centimeters." << endl;
}

void convert(float km_f) {
    cout << km_f << " kilometers (float) = " << km_f * 1000.0f << " meters." << endl;
}

int main() {
    int km;
    double m;
    float km_f;

    cout << "Enter distance in kilometers (int): ";
    cin >> km;
    convert(km);

    cout << "Enter distance in meters (double): ";
    cin >> m;
    convert(m);

    cout << "Enter distance in kilometers (float): ";
    cin >> km_f;
    convert(km_f);

    return 0;
}