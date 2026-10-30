// Q7: Electricity Bill Estimator
#include <iostream>
using namespace std;

class ElectricityPlan {
public:
    virtual double calculateBill(double units) { return 0; }
    virtual ~ElectricityPlan() {}
};

class ResidentialPlan : public ElectricityPlan {
public:
    double calculateBill(double units) override {
        return units <= 100 ? units * 4 : 400 + (units - 100) * 6;
    }
};

class CommercialPlan : public ElectricityPlan {
public:
    double calculateBill(double units) override { return units * 7; }
};

int main() {
    double u;
    cout << "Enter units consumed: ";
    cin >> u;
    ResidentialPlan r; CommercialPlan c;
    ElectricityPlan* p = &r;
    cout << "Residential Bill: Rs. " << p->calculateBill(u) << endl;
    p = &c;  // pointing to commercial plan
    cout << "Commercial Bill : Rs. " << p->calculateBill(u) << endl;
}   