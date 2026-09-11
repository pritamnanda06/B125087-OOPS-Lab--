#include <iostream>
#include <string>
using namespace std;

class LabSupervisor;

class Instrument {
private:
    int instrumentID;
    string name;
    int accessLevel;

public:
    Instrument(int id, string n, int level)
        : instrumentID(id), name(n), accessLevel(level) {}

    friend class LabSupervisor;
};

class LabSupervisor {
public:
    void display(const Instrument& inst) const {
        cout << "ID: " << inst.instrumentID << " | Name: " << inst.name
             << " | Access Level: " << inst.accessLevel << endl;
    }

    void modifyAccess(Instrument& inst, int newLevel) const {
        inst.accessLevel = newLevel;
        cout << "Access updated to " << newLevel << endl;
    }
};

int main() {
    int id, level, newLevel;
    string name;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter access level: ";
    cin >> level;

    Instrument* inst = new Instrument(id, name, level);
    LabSupervisor supervisor;

    supervisor.display(*inst);

    cout << "Enter new access level: ";
    cin >> newLevel;
    supervisor.modifyAccess(*inst, newLevel);

    supervisor.display(*inst);

    delete inst;
    return 0;
}
