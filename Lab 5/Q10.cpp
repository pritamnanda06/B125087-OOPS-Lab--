#include <iostream>
using namespace std;

double evaluate(int a, int b) { return (a + b) / 2.0; }
double evaluate(int a, int b, int c) { return (a + b + c) / 3.0; }
double evaluate(double a, double b) { return (a + b) / 2.0; }
double evaluate(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}
double evaluate(int *a, int *b) { return (*a + *b) / 2.0; }

int main() {
    int a, b, c, n;
    double x, y;

    cout << "Enter 2 ints: "; cin >> a >> b;
    cout << "Avg 2 ints: " << evaluate(a, b) << "\n";

    cout << "Enter 3 ints: "; cin >> a >> b >> c;
    cout << "Avg 3 ints: " << evaluate(a, b, c) << "\n";

    cout << "Enter 2 doubles: "; cin >> x >> y;
    cout << "Avg 2 doubles: " << evaluate(x, y) << "\n";

    cout << "Enter array size & elements: "; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Avg array: " << evaluate(arr, n) << "\n";

    cout << "Enter 2 ints for pointers: "; cin >> a >> b;
    cout << "Avg via pointers: " << evaluate(&a, &b) << "\n";
}