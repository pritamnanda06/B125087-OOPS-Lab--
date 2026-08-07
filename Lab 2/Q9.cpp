#include <iostream>
#include <string>
using namespace std;

// Class to calculate player average and classify performance
class CricketPlayer {
private:
    string playerName;
    int matchesPlayed;
    int totalRuns;

public:
    // Function to accept player details
    void acceptDetails() {
        cout << "Enter Player Name: ";
        getline(cin, playerName);
        cout << "Enter Matches Played: ";
        cin >> matchesPlayed;
        cout << "Enter Total Runs Scored: ";
        cin >> totalRuns;
    }

    // Function to calculate batting average
    double calculateBattingAverage() const {
        if (matchesPlayed == 0) return 0.0;
        return static_cast<double>(totalRuns) / matchesPlayed;
    }

    // Function to classify performance grade
    string classifyPerformance() const {
        double avg = calculateBattingAverage();
        if (avg >= 50.0) return "Excellent";
        if (avg >= 35.0) return "Good";
        if (avg >= 20.0) return "Average";
        return "Poor";
    }

    // Function to display report
    void displayReport() const {
        cout << "\n--- Player Performance Report ---" << endl;
        cout << "Player Name     : " << playerName << endl;
        cout << "Matches Played  : " << matchesPlayed << endl;
        cout << "Total Runs      : " << totalRuns << endl;
        cout << "Batting Average : " << calculateBattingAverage() << endl;
        cout << "Performance     : " << classifyPerformance() << endl;
    }
};

int main() {
    CricketPlayer player;
    player.acceptDetails();
    player.displayReport();
    return 0;
}