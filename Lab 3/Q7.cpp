#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int n;
    cout << "Enter the maximum size of the string: ";
    cin >> n;
    cin.ignore();

    char *str = new char[n];

    cout << "Enter a string: ";
    cin.getline(str, n);

    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } else if (ch >= 'a' && ch <= 'z') {
            consonants++;
        } else if (ch >= '0' && ch <= '9') {
            digits++;
        } else if (ch == ' ') {
            spaces++;
        }
    }

    cout << "\n--- String Analysis ---" << endl;
    cout << "Vowels     : " << vowels << endl;
    cout << "Consonants : " << consonants << endl;
    cout << "Digits     : " << digits << endl;
    cout << "Spaces     : " << spaces << endl;

    delete[] str;
    return 0;
}