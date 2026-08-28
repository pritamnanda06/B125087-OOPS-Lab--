#include <iostream>
using namespace std;

int process(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

float process(float arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

int process(int arr[], int size, int k) {
    int sum = 0;
    int limit = (k < size) ? k : size;
    for (int i = 0; i < limit; i++) sum += arr[i];
    return sum;
}

int main() {
    int n1;
    cout << "Enter size of integer array: ";
    cin >> n1;
    int* intArr = new int[n1];
    cout << "Enter " << n1 << " integers: ";
    for (int i = 0; i < n1; i++) cin >> intArr[i];
    cout << "Sum of all integer elements: " << process(intArr, n1) << endl;

    int k;
    cout << "Enter number of initial elements (k) to sum from integer array: ";
    cin >> k;
    cout << "Sum of first " << k << " elements: " << process(intArr, n1, k) << endl;

    int n2;
    cout << "Enter size of floating-point array: ";
    cin >> n2;
    float* floatArr = new float[n2];
    cout << "Enter " << n2 << " floats: ";
    for (int i = 0; i < n2; i++) cin >> floatArr[i];
    cout << "Sum of all floating-point elements: " << process(floatArr, n2) << endl;

    delete[] intArr;
    delete[] floatArr;
    return 0;
}