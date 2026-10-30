// Q3: Examination Eligibility - Hierarchical Inheritance
#include <iostream>
using namespace std;

class Candidate {
protected:
    int id;
    double att;
public:
    Candidate(int i, double a) : id(i), att(a) {}
};

class RegularCandidate : public Candidate {
public:
    RegularCandidate(int i, double a) : Candidate(i, a) {}
    void check() {
        cout << "Regular ID " << id << " (" << att << "%): "
             << (att >= 75 ? "Eligible" : "Not Eligible") << endl;
    }
};

class ReappearCandidate : public Candidate {
public:
    ReappearCandidate(int i, double a) : Candidate(i, a) {}
    void check() {
        cout << "Reappear ID " << id << " (" << att << "%): "
             << (att >= 60 ? "Eligible" : "Not Eligible") << endl;
    }
};

int main() {
    int id; double a;
    cout << "Regular candidate - enter ID and attendance %: ";
    cin >> id >> a;
    RegularCandidate r(id, a);
    cout << "Reappear candidate - enter ID and attendance %: ";
    cin >> id >> a;
    ReappearCandidate p(id, a);
    cout << endl;
    r.check();
    p.check();
}