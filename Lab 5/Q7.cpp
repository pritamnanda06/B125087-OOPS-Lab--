#include <iostream>
#include <cmath>
using namespace std;

int nearValue(int a, int b) {
    return (abs(a) < abs(b)) ? a : b;
}

double nearValue(double a, double b) {
    return (abs(a) < abs(b)) ? a : b;
}

int nearValue(int arr[], int size) {
    int closest = arr[0];
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) < abs(closest)) closest = arr[i];
    }
    return closest;
}

int main() {
    int a, b, size;
    double x, y;

    cout << "Enter 2 integers: ";
    cin >> a >> b;
    cout << "Closer to zero: " << nearValue(a, b) << "\n\n";

    cout << "Enter 2 doubles: ";
    cin >> x >> y;
    cout << "Closer to zero: " << nearValue(x, y) << "\n\n";

    cout << "Enter array size: ";
    cin >> size;
    int arr[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    cout << "Closest in array: " << nearValue(arr, size) << "\n";

    return 0;
}