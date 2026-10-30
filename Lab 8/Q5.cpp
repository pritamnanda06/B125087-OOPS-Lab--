// Q10: Scholarship Selection System
#include <iostream>
using namespace std;

class Scholarship {
public:
    virtual double calculateAward(double marks, double income) { return 0; }
    virtual ~Scholarship() {}
};

class MeritScholarship : public Scholarship {
public:
    double calculateAward(double marks, double income) override {
        return marks >= 90 ? 20000 : marks >= 80 ? 10000 : 0;
    }
};

class NeedBasedScholarship : public Scholarship {
public:
    double calculateAward(double marks, double income) override {
        return (income < 200000 && marks >= 70) ? 25000 : 0;
    }
};

int main() {
    double marks, income;
    cout << "Enter marks and family income (Rs.): ";
    cin >> marks >> income;
    MeritScholarship m; NeedBasedScholarship n;
    Scholarship* s = &m;
    cout << "Merit award     : Rs. " << s->calculateAward(marks, income) << endl;
    s = &n;
    cout << "Need-based award: Rs. " << s->calculateAward(marks, income) << endl;
}