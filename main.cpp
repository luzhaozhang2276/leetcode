#include <bits/stdc++.h>
using namespace std;

/// 剑指 Offer 10- I. 斐波那契数列

class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;

        int fminuOne = 1, fminuTwo = 0, res;
        for (int i = 2; i <= n; ++i) {
            res = (fminuOne + fminuTwo) % 1000000007;
            fminuTwo = fminuOne;
            fminuOne = res;
        }

        return res;
    }
};

int main() {
    Solution solve;

    cout << "\nFinish";
    return 0;
}