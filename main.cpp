#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        if (n < 2)
            return 1;

        int fibNMinusOne(1);
        int finBMinusTwo(1);
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
    cout << s.numWays(7) << endl;

    cout << "\nFinish" << endl;
    return 0;
}
