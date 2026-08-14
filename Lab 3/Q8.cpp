#include <iostream>
using namespace std;

void acceptElements(int *arr, int n) {
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int calculateSum(const int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int findSmallest(const int *arr, int n) {
    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

int findLargest(const int *arr, int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

void displayResults(const int *arr, int n) {
    cout << "\n--- Array Processing Results ---\n";
    cout << "Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nSum     : " << calculateSum(arr, n) << endl;
    cout << "Smallest: " << findSmallest(arr, n) << endl;
    cout << "Largest : " << findLargest(arr, n) << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];

    acceptElements(arr, n);
    displayResults(arr, n);

    delete[] arr;
    return 0;
}