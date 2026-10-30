// Q2: Digital Image Metadata - Multilevel Inheritance
#include <iostream>
#include <string>
using namespace std;

class Image {
protected:
    int width, height;
public:
    Image(int w, int h) : width(w), height(h) {}
    int pixels() { return (int)width * height; }
};

class CompressedImage : public Image {
protected:
    double ratio;   // percentage
public:
    CompressedImage(int w, int h, double r) : Image(w, h), ratio(r) {}
};

class EncryptedImage : public CompressedImage {
    string algo;
public:
    EncryptedImage(int w, int h, double r, string a) : CompressedImage(w, h, r), algo(a) {}
    void display() {
        cout << "\nSize: " << width << " x " << height << " px"
             << "\nOriginal pixels: " << pixels()
             << "\nCompression: " << ratio << "%"
             << "\nEffective size: " << pixels() * ratio / 100
             << "\nEncryption: " << algo << endl;
    }
};

int main() {
    int w, h; double r; string a;
    cout << "Enter width, height, compression %, algorithm: ";
    cin >> w >> h >> r >> a;
    EncryptedImage img(w, h, r, a);
    img.display();
}