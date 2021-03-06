#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<double> dicesProbability(int n) {
        double p = 1.0 / 6.0;
        vector<double> dp(6, p);    // 此处模拟为二维数组, 但新状态只与前一个状态有关,此处可用一维实现
        for (int i = 2; i <= n; ++i) {
            vector<double> tmp(5 * i + 1, 0);
            for (int j = 0; j < dp.size(); ++j)
                for (int k = 0; k < 6; ++k)
                    tmp[j + k] += dp[j] / 6.0;

            dp = tmp;
        }
        return dp;
    }
};


int main() {
    Solution solve;
    for (auto p : solve.dicesProbability(2))
        cout << p << ' ';

    cout << "\nFinish";
    return 0;
}
