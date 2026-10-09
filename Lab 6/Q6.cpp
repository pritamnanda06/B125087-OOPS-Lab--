#include <iostream>
using namespace std;

class Date {
    int day, month, year;
public:
    void input(const char* name) {
        cout << "Enter day month year of " << name << " (dd mm yyyy): ";
        cin >> day >> month >> year;
    }
    bool operator==(const Date& o) const {
        return day == o.day && month == o.month && year == o.year;
    }
    bool operator!=(const Date& o) const {
        return !(*this == o);
    }
    void display() const {
        cout << day << "/" << month << "/" << year;
    }
};

int main() {
    Date d1, d2;
    d1.input("Date 1");
    d2.input("Date 2");
    cout << "\nDate 1: "; d1.display();
    cout << "\nDate 2: "; d2.display();
    cout << "\n\nd1 == d2 : " << (d1 == d2 ? "true" : "false") << endl;
    cout << "d1 != d2 : " << (d1 != d2 ? "true" : "false") << endl;
    return 0;
}