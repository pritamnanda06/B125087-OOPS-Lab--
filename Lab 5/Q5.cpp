#include <iostream>
using namespace std;

void swapData(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapData(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

void swapData(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int i1, i2;
    cout << "Enter two integers for reference swap: ";
    cin >> i1 >> i2;
    cout << "Before swap: i1 = " << i1 << ", i2 = " << i2 << endl;
    swapData(i1, i2);
    cout << "After swap: i1 = " << i1 << ", i2 = " << i2 << endl;

    float f1, f2;
    cout << "Enter two floats for reference swap: ";
    cin >> f1 >> f2;
    cout << "Before swap: f1 = " << f1 << ", f2 = " << f2 << endl;
    swapData(f1, f2);
    cout << "After swap: f1 = " << f1 << ", f2 = " << f2 << endl;

    int p1, p2;
    cout << "Enter two integers for pointer swap: ";
    cin >> p1 >> p2;
    cout << "Before swap: p1 = " << p1 << ", p2 = " << p2 << endl;
    swapData(&p1, &p2);
    cout << "After swap: p1 = " << p1 << ", p2 = " << p2 << endl;

    return 0;
}