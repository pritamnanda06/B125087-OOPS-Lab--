#include <iostream>
using namespace std;

class Score {
public:
    int score;
    Score(int s = 0) { score = s; }
    Score operator++() {          // prefix
        score++;
        return *this;
    }
    Score operator++(int) {       // postfix
        Score old = *this;
        score++;
        return old;
    }
};

int main() {
    int s;
    cout << "Enter initial score: ";
    cin >> s;

    Score a(s), b(s);
    Score pre = ++a;
    Score post = b++;
    cout << "Prefix  ++a : a = " << a.score << ", result = " << pre.score << endl;
    cout << "Postfix b++ : b = " << b.score << ", result = " << post.score << endl;
}