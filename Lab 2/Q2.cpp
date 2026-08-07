#include <iostream>
using namespace std;

// Class to calculate area and perimeter of a square
class Square {
private:
    double side;

public:
    // Function to read side length
    void readSide() {
        cout << "Enter the side length of the square: ";
        cin >> side;
    }

    // Function to calculate area
    double calculateArea() const {
        return side * side;
    }

    // Function to calculate perimeter
    double calculatePerimeter() const {
        return 4 * side;
    }

    // Function to display results
    void displayResults() const {
        cout << "\n--- Square Results ---" << endl;
        cout << "Side Length : " << side << endl;
        cout << "Area        : " << calculateArea() << endl;
        cout << "Perimeter   : " << calculatePerimeter() << endl;
    }
};

int main() {
    Square sq;
    sq.readSide();
    sq.displayResults();
    return 0;
}