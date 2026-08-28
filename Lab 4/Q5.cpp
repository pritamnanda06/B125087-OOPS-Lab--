    #include <iostream>
    #include <string>
    using namespace std;

    class EventParticipant {
    private:
        string participantName;
        int age;
        string registrationStatus;

    public:
        void acceptData() {
            cout << "Enter Participant Name: ";
            cin.ignore();
            getline(cin, participantName);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Registration Status (active/inactive): ";
            cin >> registrationStatus;
        }

        // Friend function declaration
        friend void verifyParticipant(const EventParticipant& p);
    };

    // Friend function definition
    void verifyParticipant(const EventParticipant& p) {
        cout << "\n--- Event Registration Verification ---" << endl;
        cout << "Participant Name: " << p.participantName << endl;
        cout << "Age: " << p.age << endl;
        cout << "Registration Status: " << p.registrationStatus << endl;
        
        cout << "Verification Result: ";
        if (p.age >= 18 && (p.registrationStatus == "active" || p.registrationStatus == "Active")) {
            cout << "Eligible" << endl;
        } else {
            cout << "Not Eligible" << endl;
        }
    }

    int main() {
        EventParticipant participant;
        participant.acceptData();
        verifyParticipant(participant);
        return 0;
    }