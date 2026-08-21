#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows (m) and columns (n) for the matrices: ";
    cin >> m >> n;

    // Allocate row pointers and columns for Matrix 1
    int **mat1 = new int*[m];
    for (int i = 0; i < m; i++) {
        mat1[i] = new int[n];
    }

    // Allocate row pointers and columns for Matrix 2
    int **mat2 = new int*[m];
    for (int i = 0; i < m; i++) {
        mat2[i] = new int[n];
    }

    // Allocate row pointers and columns for Result Matrix
    int **sumMat = new int*[m];
    for (int i = 0; i < m; i++) {
        sumMat[i] = new int[n];
    }

    cout << "\nEnter elements of Matrix 1:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Mat1[" << i << "][" << j << "]: ";
            cin >> mat1[i][j];
        }
    }

    cout << "\nEnter elements of Matrix 2:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Mat2[" << i << "][" << j << "]: ";
            cin >> mat2[i][j];
        }
    }

    // Matrix Addition
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sumMat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    cout << "\n--- Resultant Matrix (Matrix 1 + Matrix 2) ---\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << sumMat[i][j] << "\t";
        }
        cout << endl;
    }

    // Deallocate Matrix 1
    for (int i = 0; i < m; i++) {
        delete[] mat1[i];
    }
    delete[] mat1;

    // Deallocate Matrix 2
    for (int i = 0; i < m; i++) {
        delete[] mat2[i];
    }
    delete[] mat2;

    // Deallocate Result Matrix
    for (int i = 0; i < m; i++) {
        delete[] sumMat[i];
    }
    delete[] sumMat;

    return 0;
}