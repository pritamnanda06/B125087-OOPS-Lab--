// Q3. Movie Queue Display
#include <iostream>
using namespace std;

class QueueDisplay {
    int queueSize, count;
    int* customerIDs;

public:
    QueueDisplay() : queueSize(0), count(0), customerIDs(nullptr) {}

    void initQueue(int size) {
        queueSize = size;
        count = 0;
        customerIDs = new int[size];
    }

    void insert(int id) {
        if (count < queueSize)
            customerIDs[count++] = id;
    }

    void display() const {
        cout << "Queue (size " << queueSize << "): ";
        for (int i = 0; i < count; i++)
            cout << customerIDs[i] << " ";
        cout << endl;
    }

    friend void exchangeQueues(QueueDisplay& q1, QueueDisplay& q2);

    ~QueueDisplay() { delete[] customerIDs; }
};

void exchangeQueues(QueueDisplay& q1, QueueDisplay& q2) {
    int tSize = q1.queueSize, tCount = q1.count;
    int* tIDs = q1.customerIDs;
    q1.queueSize = q2.queueSize; q1.count = q2.count; q1.customerIDs = q2.customerIDs;
    q2.queueSize = tSize; q2.count = tCount; q2.customerIDs = tIDs;
}

int main() {
    int n;
    cout << "Enter number of queues to create: ";
    cin >> n;

    QueueDisplay* queues = new QueueDisplay[n];

    for (int i = 0; i < n; i++) {
        int size;
        cout << "\nQueue " << (i + 1) << " - size: ";
        cin >> size;
        (queues + i)->initQueue(size);

        cout << "Enter " << size << " customer IDs: ";
        for (int j = 0; j < size; j++) {
            int id;
            cin >> id;
            (queues + i)->insert(id);
        }
    }

    cout << "\n----- Before Exchange -----\n";
    for (int i = 0; i < n; i++) {
        cout << "Queue " << (i + 1) << ": ";
        (queues + i)->display();
    }

    if (n >= 2) {
        int a, b;
        cout << "\nEnter two queue indices (1 to " << n << ") to exchange: ";
        cin >> a >> b;
        exchangeQueues(queues[a - 1], queues[b - 1]);

        cout << "\n----- After Exchange -----\n";
        for (int i = 0; i < n; i++) {
            cout << "Queue " << (i + 1) << ": ";
            (queues + i)->display();
        }
    }

    delete[] queues;
    return 0;
}