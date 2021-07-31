#include <bits/stdc++.h>

using namespace std;

/// 72. 编辑距离    二维dp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int tmp1 = (word1[i-1] == word2[j-1]) ? dp[i-1][j-1] : dp[i-1][j-1] + 1;
                int tmp2 = min(dp[i][j-1], dp[i-1][j]) + 1;
                dp[i][j] = min(tmp1, tmp2);
            }
        }

        return dp[n][m];
    }
};

int main() {
    string str1 = "horse";
    string str2 = "ros";
    Solution solve;
    cout << "res = " << solve.minDistance(str1, str2) <<endl;

    cout << "\nFinish";
    return 0;
}