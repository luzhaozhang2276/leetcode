#include <bits/stdc++.h>
using namespace std;

#if 0
/// 递归:超出时间限制
class Solution {
public:
    bool isMatch(string s, string p) {
        // if (s.empty() || p.empty())
            // return false;
        return matchRecursion(s, p);
    }

    bool matchRecursion(string s, string p)
    {
        /// 终止条件
        if (s.empty() && p.empty())
            return true;
        if (!s.empty() && p.empty())
            return false;

        if (p[1] == '*')
        {
            if (s[0] == p[0] ||(p[0] == '.' && !s.empty()))
                return matchRecursion(s.substr(1), p.substr(2)) ||
                       matchRecursion(s.substr(1), p.substr(0)) ||
                       matchRecursion(s.substr(0), p.substr(2));
            else
                return matchRecursion(s.substr(0), p.substr(2));
        }

        if (s[0] == p[0] ||(p[0] == '.' && !s.empty()))
            return matchRecursion(s.substr(1), p.substr(1));

        return false;
    }
};

#elif 1
/// 动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        /// 初始化
        dp[0][0] = true;    // 字符串与模板均为空,匹配成功
        for(int j = 2; j < n; j += 2)   // 字符串为空,模板非空,且偶数位为*
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';

        /// DP计算
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = p[j - 1] == '*' ?
                           dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'):
                           dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
#endif

int main() {
    string s = "aab";
    string p = "c*a*b*";

    Solution solve;
    string result = solve.isMatch(s, p) ? "true" : "false";
    cout << "match: " << result << endl;

    cout << "\nFinish" << endl;
    return 0;
}
