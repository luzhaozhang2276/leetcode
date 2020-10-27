#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n ? 1:0;

        int fibNMinusOne(1);
        int finBMinusTwo(0);
        int fibN(0);

        while (n>=2)
        {
            fibN = (fibNMinusOne + finBMinusTwo)%1000000007;
            finBMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
            --n;
        }

        return fibN;
    }
};

int main() {
    Solution s;
    cout << s.fib(1) << endl;

    cout << "\nFinish" << endl;
    return 0;
}
