#include <iostream>
#include <string>
using namespace std;

// Class to store and display car details
class Car {
private:
    string carNumber;
    string brandName;
    int modelYear;

public:
    // Function to accept car details from user
    void acceptDetails() {
        cout << "Enter Car Number: ";
        cin >> carNumber;
        cin.ignore();
        cout << "Enter Brand Name: ";
        getline(cin, brandName);
        cout << "Enter Model Year: ";
        cin >> modelYear;
    }

    // Function to display car details
    void displayDetails() const {
        cout << "\n--- Car Details ---" << endl;
        cout << "Car Number : " << carNumber << endl;
        cout << "Brand Name : " << brandName << endl;
        cout << "Model Year : " << modelYear << endl;
    }
};

int main() {
    Car myCar;
    myCar.acceptDetails();
    myCar.displayDetails();
    return 0;
}