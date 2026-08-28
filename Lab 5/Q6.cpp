#include <iostream>
#include <cstring>
using namespace std;

int information(char arr[]) {
    return strlen(arr);
}

int information(char arr[], char target) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == target) count++;
    }
    return count;
}   

int information(char arr[], char target, int k) {
    int count = 0;
    int len = strlen(arr);
    int limit = (k < len) ? k : len;
    for (int i = 0; i < limit; i++) {
        if (arr[i] == target) count++;
    }
    return count;
}

int main() {
    char str[100];
    char target;
    int k;

    cout << "Enter a string: ";
    cin >> str;

    cout << "Length of string: " << information(str) << endl;

    cout << "Enter a character to count occurrences: ";
    cin >> target;
    cout << "Total occurrences of '" << target << "': " << information(str, target) << endl;

    cout << "Enter value of k (positions to examine): ";
    cin >> k;
    cout << "Occurrences of '" << target << "' in first " << k << " positions: " << information(str, target, k) << endl;

    return 0;
}