#include <bits/stdc++.h>

using namespace std;

/// 96. 不同的二叉搜索树
// DP
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1] * dp[i - j];
            }
        }

        return dp[n];
    }
};

int main() {
    Solution solve;
    cout <<"res = " << solve.numTrees(4) << endl;

    cout << "\nFinish";
    return 0;
}