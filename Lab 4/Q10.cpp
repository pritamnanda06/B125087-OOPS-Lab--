#include <iostream>
#include <string>
using namespace std;

class Classroom {
private:
    string className;
    int totalStudents;
    int presentStudents;
    string attendanceStatus; // e.g., "Pending", "Completed"

public:
    void acceptData() {
        cout << "Enter Class Name: ";
        cin.ignore();
        getline(cin, className);
        cout << "Enter Total Students: ";
        cin >> totalStudents;
        cout << "Enter Present Students: ";
        cin >> presentStudents;
        cout << "Enter Attendance Status (Pending/Completed): ";
        cin >> attendanceStatus;
    }

    // Declare AttendanceManager as a friend class
    friend class AttendanceManager;
};

class AttendanceManager {
public:
    void displayClassroomInfo(const Classroom& c) {
        cout << "\n--- Classroom Information ---" << endl;
        cout << "Class Name: " << c.className << endl;
        cout << "Total Students: " << c.totalStudents << endl;
        cout << "Present Students: " << c.presentStudents << endl;
        cout << "Attendance Status: " << c.attendanceStatus << endl;
    }

    void updatePresentStudents(Classroom& c, int present) {
        if (present <= c.totalStudents && present >= 0) {
            c.presentStudents = present;
            cout << "Present students updated to " << c.presentStudents << "." << endl;
        } else {
            cout << "Invalid number of present students." << endl;
        }
    }

    void markAttendanceCompleted(Classroom& c) {
        c.attendanceStatus = "Completed";
        cout << "Attendance for " << c.className << " marked as Completed." << endl;
    }

    void calculateAndDisplayAbsents(const Classroom& c) {
        int absentStudents = c.totalStudents - c.presentStudents;
        cout << "\n--- Attendance Summary ---" << endl;
        cout << "Class Name: " << c.className << endl;
        cout << "Total Students: " << c.totalStudents << endl;
        cout << "Present Students: " << c.presentStudents << endl;
        cout << "Absent Students: " << absentStudents << endl;
    }
};

int main() {
    Classroom room;
    room.acceptData();
    AttendanceManager am;

    am.displayClassroomInfo(room);
    int newPresent;
    cout << "Enter updated number of present students: ";
    cin >> newPresent;
    am.updatePresentStudents(room, newPresent);
    am.markAttendanceCompleted(room);
    am.calculateAndDisplayAbsents(room);

    return 0;
}