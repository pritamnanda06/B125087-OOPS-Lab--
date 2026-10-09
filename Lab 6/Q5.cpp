#include <iostream>
using namespace std;

class Score {
    int score;
public:
    Score(int s = 0) : score(s) {}
    Score& operator++() {          // prefix: increment, then return new value
        ++score;
        return *this;
    }
    Score operator++(int) {        // postfix: return old value, then increment
        Score old(*this);
        ++score;
        return old;
    }
    int get() const { return score; }
};

int main() {
    int s;
    cout << "Enter initial score: ";
    cin >> s;

    Score a(s);
    Score pre = ++a;
    cout << "\nAfter  pre = ++a :\n";
    cout << "  a   = " << a.get() << "\n  pre = " << pre.get() << "  (new value)\n";

    Score b(s);
    Score post = b++;
    cout << "\nAfter  post = b++ :\n";
    cout << "  b    = " << b.get() << "\n  post = " << post.get() << "  (old value)\n";
    return 0;
}