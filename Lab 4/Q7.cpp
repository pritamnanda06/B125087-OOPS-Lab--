#include <iostream>
#include <string>
using namespace std;

class Exhibit {
private:
    string exhibitName;
    string exhibitID;
    int visitorCount;
    bool displayStatus; // true for Open, false for Closed

public:
    void acceptData() {
        cout << "Enter Exhibit Name: ";
        cin >> exhibitName;
        cout << "Enter Exhibit ID: ";
        cin >> exhibitID;
        cout << "Enter Initial Visitor Count: ";
        cin >> visitorCount;
        cout << "Enter Display Status (1 for Open, 0 for Closed): ";
        cin >> displayStatus;
    }

    // Declare MuseumManager as a friend class
    friend class MuseumManager;
};

class MuseumManager {
public:
    void displayExhibitInfo(const Exhibit& e) {
        cout << "\n--- Exhibit Information ---" << endl;
        cout << "Exhibit Name: " << e.exhibitName << endl;
        cout << "Exhibit ID: " << e.exhibitID << endl;
        cout << "Visitor Count: " << e.visitorCount << endl;
        cout << "Display Status: " << (e.displayStatus ? "Open" : "Closed") << endl;
    }

    void addVisitors(Exhibit& e, int count) {
        e.visitorCount += count;
        cout << count << " visitors added to " << e.exhibitName << "." << endl;
    }

    void resetVisitorCount(Exhibit& e) {
        e.visitorCount = 0;
        cout << "Visitor count reset to 0 for " << e.exhibitName << "." << endl;
    }

    void setExhibitStatus(Exhibit& e, bool status) {
        e.displayStatus = status;
        cout << e.exhibitName << " is now " << (e.displayStatus ? "Open" : "Closed") << "." << endl;
    }

    void displayStatusCheck(const Exhibit& e) {
        cout << e.exhibitName << " is currently " << (e.displayStatus ? "Open" : "Closed") << "." << endl;
    }
};

int main() {
    Exhibit ex;
    ex.acceptData();
    MuseumManager mm;

    mm.displayExhibitInfo(ex);
    int addCount;
    cout << "Enter number of visitors to add: ";
    cin >> addCount;
    mm.addVisitors(ex, addCount);
    mm.displayStatusCheck(ex);
    mm.displayExhibitInfo(ex);

    return 0;
}