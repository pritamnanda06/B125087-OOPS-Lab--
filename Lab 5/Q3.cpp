#include <iostream>
using namespace std;

void check(int n) {
    cout << n << (n > 0 ? " is Positive\n" : n < 0 ? " is Negative\n" : " is Zero\n");
}

void check(char c) {
    cout << c << (c >= 'A' && c <= 'Z' ? " is Uppercase\n" : c >= 'a' && c <= 'z' ? " is Lowercase\n" : " is Non-alphabetic\n");
}

void check(char arr[], int n, char t) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == t) { cout << "'" << t << "' found\n"; return; }
    }
    cout << "'" << t << "' not found\n";
}

int main() {
    int n;
    char c, t;

    cout << "Enter int: "; cin >> n;
    check(n);

    cout << "Enter char: "; cin >> c;
    check(c);

    cout << "Enter array size & elements: "; cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter search target: "; cin >> t;
    check(arr, n, t);
}