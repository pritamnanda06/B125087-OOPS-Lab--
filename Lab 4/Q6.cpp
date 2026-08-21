#include <iostream>
#include <string>
using namespace std;

class Printer {
private:
    string printerName;
    int pagesPrinted;
    int inkLevel; // percentage
    bool powerStatus; // true for ON, false for OFF

public:
    void acceptData() {
        cout << "Enter Printer Name: ";
        cin >> printerName;
        cout << "Enter Pages Printed: ";
        cin >> pagesPrinted;
        cout << "Enter Ink Level (%): ";
        cin >> inkLevel;
        cout << "Enter Power Status (1 for ON, 0 for OFF): ";
        cin >> powerStatus;
    }

    // Declare PrinterManager as a friend class
    friend class PrinterManager;
};

class PrinterManager {
public:
    void displayInfo(const Printer& p) {
        cout << "\n--- Printer Information ---" << endl;
        cout << "Printer Name: " << p.printerName << endl;
        cout << "Pages Printed: " << p.pagesPrinted << endl;
        cout << "Ink Level: " << p.inkLevel << "%" << endl;
        cout << "Power Status: " << (p.powerStatus ? "ON" : "OFF") << endl;
    }

    void turnOn(Printer& p) {
        p.powerStatus = true;
        cout << p.printerName << " is now turned ON." << endl;
    }

    void turnOff(Printer& p) {
        p.powerStatus = false;
        cout << p.printerName << " is now turned OFF." << endl;
    }

    void checkInkLevel(const Printer& p) {
        cout << "Current Ink Level (" << p.printerName << "): " << p.inkLevel << "%" << endl;
    }

    void resetPageCount(Printer& p) {
        p.pagesPrinted = 0;
        cout << "Page count for " << p.printerName << " has been reset to 0." << endl;
    }
};

int main() {
    Printer myPrinter;
    myPrinter.acceptData();
    PrinterManager manager;

    manager.displayInfo(myPrinter);
    manager.turnOn(myPrinter);
    manager.checkInkLevel(myPrinter);
    manager.resetPageCount(myPrinter);
    manager.displayInfo(myPrinter);

    return 0;
}