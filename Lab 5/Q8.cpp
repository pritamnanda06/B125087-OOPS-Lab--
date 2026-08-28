#include <iostream>
using namespace std;

void update(int &v, int a) { v += a; }
void update(float &v, float a) { v += a; }
void update(int arr[], int n, int a) {
    for (int i = 0; i < n; i++) arr[i] += a;
}

int main() {
    int v, a, n;
    float f, fa;

    cout << "Enter int & amt: "; cin >> v >> a;
    cout << "Before: " << v; update(v, a); cout << " | After: " << v << "\n";

    cout << "Enter float & amt: "; cin >> f >> fa;
    cout << "Before: " << f; update(f, fa); cout << " | After: " << f << "\n";

    cout << "Enter array size: "; cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter amt: "; cin >> a;

    cout << "Before: "; for (int i = 0; i < n; i++) cout << arr[i] << " ";
    update(arr, n, a);
    cout << "\nAfter:  "; for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}