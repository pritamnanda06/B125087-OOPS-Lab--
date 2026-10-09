#include <iostream>
using namespace std;

class Matrix {
    double m[2][2];
public:
    Matrix() { for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) m[i][j] = 0; }
    void input(const char* name) {
        cout << "Enter 4 elements of " << name << " (row-wise): ";
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                cin >> m[i][j];
    }
    Matrix operator+(const Matrix& o) const {
        Matrix r;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                r.m[i][j] = m[i][j] + o.m[i][j];
        return r;
    }
    void display(const char* label) const {
        cout << label << endl;
        for (int i = 0; i < 2; i++) {
            cout << "  [ ";
            for (int j = 0; j < 2; j++) cout << m[i][j] << " ";
            cout << "]\n";
        }
    }
};

int main() {
    Matrix a, b;
    a.input("Matrix A");
    b.input("Matrix B");
    Matrix c = a + b;
    cout << endl;
    a.display("Matrix A:");
    b.display("Matrix B:");
    c.display("A + B:");
    return 0;
}