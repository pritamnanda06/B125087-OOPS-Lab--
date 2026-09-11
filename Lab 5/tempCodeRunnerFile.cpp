#include <iostream>
using namespace std;

void inspect(int val) {
    cout << "Inspecting integer value directly: " << val << endl;
}

void inspect(int *ptr) {
    cout << "Inspecting value stored at pointer address: " << *ptr << endl;
}

void inspect(int arr[], int size) {
    cout << "Inspecting array elements using pointer: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int val;
    cout << "Enter an integer variable value: ";
    cin >> val;
    inspect(val);
    inspect(&val);

    int size;
    cout << "Enter size of integer array: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    inspect(arr, size);

    delete[] arr;
    return 0;
}