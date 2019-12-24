#include <string>

const unsigned long long B = 1000000007;
// const unsigned long long B = 10000000000000061ULL;

bool contain(std::string a, std::string b) {
    int al = a.length(), bl = b.length();
    if (al > bl) {
        return false;
    }

    unsigned long long t = 1;
    for (int i = 0; i < al; i++) {
        t *= B;
    }

    unsigned long long ah = 0, bh = 0;
    for (int i = 0; i < al; i++) {
        ah = ah * B + a[i];
    }
    for (int i = 0; i < al; i++) {
        bh = bh * B + b[i];
    }

    for (int i = 0; i + al <= bl; i++) {
        if (ah == bh) {
            return true;
        }
        if (i + al < bl) {
            bh = bh * B + b[i + al] - b[i] * t;
        }
    }

    return false;
}

int overlap(std::string a, std::string b) {
    int al = a.size(), bl = b.size();
    unsigned long long ah = 0, bh = 0, t = 1;
    int ans = 0;
    for (int i = 0; i < std::min(al, bl); i++) {
        ah = ah + a[al - i - 1] * t;
        bh = bh * B + b[i];
        if (ah == bh) {
            ans = i + 1;
        }
        t *= B;
    }
    return ans;
}