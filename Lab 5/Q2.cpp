#include <iostream>
using namespace std;

void area(double side) {
    cout << "Area of the square: " << side * side << endl;
}

void area(double length, double breadth) {
    cout << "Area of the rectangle: " << length * breadth << endl;
}

void area(double radius, char s) {
    cout << "Area of the circle: " << 3.1416 * radius * radius << endl;
}

int main() {
    double side, length, breadth, radius;

    cout << "Enter side of the square: ";
    cin >> side;
    area(side);

    cout << "Enter length and breadth of the rectangle: ";
    cin >> length >> breadth;
    area(length, breadth);

    cout << "Enter radius of the circle: ";
    cin >> radius;
    area(radius,'c');

    return 0;
}