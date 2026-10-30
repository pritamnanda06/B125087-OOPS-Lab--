// Q8: Autonomous Traffic Signal
#include <iostream>
using namespace std;

class TrafficSignal {
public:
    virtual int getGreenDuration(int vehicleCount) { return 0; }
    virtual ~TrafficSignal() {}
};

class UrbanSignal : public TrafficSignal {
public:
    int getGreenDuration(int n) override { return min(10 + 2*n, 60); }
};

class HighwaySignal : public TrafficSignal {
public:
    int getGreenDuration(int n) override { return min(15 + 3*n, 90); }
};

int main() {
    int u, h;
    cout << "Enter vehicle counts for Urban and Highway signals: ";
    cin >> u >> h;
    UrbanSignal us; HighwaySignal hs;
    TrafficSignal* s = &us; 
    cout << "Urban green duration  : " << s->getGreenDuration(u) << " s\n";
    s = &hs; 
    cout << "Highway green duration: " << s->getGreenDuration(h) << " s\n";
}