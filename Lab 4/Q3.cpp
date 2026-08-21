#include <iostream>
#include <string>
using namespace std;

class Camera {
private:
    string brand;
    string model;
    double megapixels;
    int storageCapacity; // in GB

public:
    void acceptData(int camNum) {
        cout << "Enter details for Camera " << camNum << ":" << endl;
        cout << "  Brand: ";
        cin >> brand;
        cout << "  Model: ";
        cin >> model;
        cout << "  Megapixels: ";
        cin >> megapixels;
        cout << "  Storage Capacity (GB): ";
        cin >> storageCapacity;
    }

    // Friend function declaration
    friend void compareCamera(const Camera& c1, const Camera& c2);
};

// Friend function definition
void compareCamera(const Camera& c1, const Camera& c2) {
    cout << "\n--- Camera Comparison ---" << endl;
    cout << "Camera 1: " << c1.brand << " " << c1.model << " (" << c1.megapixels << " MP, " << c1.storageCapacity << " GB)" << endl;
    cout << "Camera 2: " << c2.brand << " " << c2.model << " (" << c2.megapixels << " MP, " << c2.storageCapacity << " GB)" << endl;
    
    cout << "Better Camera: ";
    if (c1.megapixels > c2.megapixels) {
        cout << c1.brand << " " << c1.model << " (Higher Megapixels)" << endl;
    } else if (c2.megapixels > c1.megapixels) {
        cout << c2.brand << " " << c2.model << " (Higher Megapixels)" << endl;
    } else {
        if (c1.storageCapacity > c2.storageCapacity) {
            cout << c1.brand << " " << c1.model << " (Higher Storage Capacity)" << endl;
        } else if (c2.storageCapacity > c1.storageCapacity) {
            cout << c2.brand << " " << c2.model << " (Higher Storage Capacity)" << endl;
        } else {
            cout << "Both cameras have equal specifications." << endl;
        }
    }
}

int main() {
    Camera cam1, cam2;
    cam1.acceptData(1);
    cam2.acceptData(2);
    compareCamera(cam1, cam2);
    return 0;
}