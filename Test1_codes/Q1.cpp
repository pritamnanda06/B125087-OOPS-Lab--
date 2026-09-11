// Q1. Smart Locker Allocation
#include <iostream>
#include <cstring>
using namespace std;

class Locker {
    int lockerNumber, codeLength;
    bool occupied;
    char* accessCode;

public:
    Locker() : lockerNumber(0), codeLength(0), occupied(false), accessCode(nullptr) {}

    void init(int num, int len) {
        lockerNumber = num;
        codeLength = len;
        accessCode = new char[len + 1];
        strcpy(accessCode, string(len, '0').c_str());
    }

    void setCode(const char* code) {          // overload 1: full code
        strcpy(accessCode, code);
        occupied = true;
    }

    void setCode(int pos, char digit) {       // overload 2: single position
        if (pos >= 0 && pos < codeLength)
            accessCode[pos] = digit;
    }

    void display() const {
        cout << "Locker " << lockerNumber << " | Occupied: " << (occupied ? "Yes" : "No")
             << " | Code: " << accessCode << endl;
    }

    ~Locker() { delete[] accessCode; }
};

int main() {
    int n, len;
    cout << "Number of lockers: ";
    cin >> n;
    cout << "Access code length: ";
    cin >> len;

    Locker* lockers = new Locker[n];
    for (int i = 0; i < n; i++)
        lockers[i].init(i + 1, len);

    char code[50];
    for (int i = 0; i < n; i++) {
        cout << "Code for Locker " << (i + 1) << ": ";
        cin >> code;
        (lockers + i)->setCode(code);
    }

    int pos; char ch;
    cout << "Position to change in Locker 1: ";
    cin >> pos;
    cout << "New character: ";
    cin >> ch;
    lockers->setCode(pos, ch);

    cout << "\n--- Locker Status ---\n";
    for (int i = 0; i < n; i++)
        (lockers + i)->display();

    delete[] lockers;
    return 0;
}