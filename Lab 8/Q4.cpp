// Q9: Data Backup Policy
#include <iostream>
using namespace std;

class BackupPolicy {
public:
    virtual double calculateStorage(double mb) { return 0; }
    virtual ~BackupPolicy() {}
};

class FullBackup : public BackupPolicy {
public:
    double calculateStorage(double mb) override { return mb; }
};

class IncrementalBackup : public BackupPolicy {
public:
    double calculateStorage(double mb) override { return 0.25 * mb + 50; }
};

int main() {
    double mb;
    cout << "Enter data size (MB): ";
    cin >> mb;
    FullBackup f; IncrementalBackup i;
    BackupPolicy* p = &f;
    cout << "Full backup        : " << p->calculateStorage(mb) << " MB\n";
    p = &i;
    cout << "Incremental backup : " << p->calculateStorage(mb) << " MB\n";
}