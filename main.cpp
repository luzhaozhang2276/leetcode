#include <bits/stdc++.h>

using namespace std;

/// 62. 不同路径  二维DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    Solution solve;
    cout << "res = " << solve.uniquePaths(7, 3) <<endl;

    cout << "\nFinish";
    return 0;
}