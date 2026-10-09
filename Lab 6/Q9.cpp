#include <iostream>
using namespace std;

class Matrix {
public:
    int a[2][2];
    Matrix operator+(Matrix m) {
        Matrix r;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                r.a[i][j] = a[i][j] + m.a[i][j];
        return r;
    }
    void show() {
        for (int i = 0; i < 2; i++)
            cout << a[i][0] << " " << a[i][1] << endl;
    }
};

int main() {
    Matrix m1, m2;
    cout << "Enter 4 elements of matrix 1: ";
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) cin >> m1.a[i][j];
    cout << "Enter 4 elements of matrix 2: ";
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) cin >> m2.a[i][j];

    Matrix m3 = m1 + m2;
    cout << "Matrix 1:\n"; m1.show();
    cout << "Matrix 2:\n"; m2.show();
    cout << "Sum:\n";      m3.show();
}