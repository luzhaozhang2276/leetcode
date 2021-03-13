#include <bits/stdc++.h>
using namespace std;

/// 5. 最长回文子串

#if 0
// dp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false)); // 只利用上三角
        string res;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0)
                    dp[i][j] = true;
                else if (l == 1)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = dp[i+1][j-1] && s[i] == s[j];

                if (dp[i][j] && res.size() < j-i+1)
                    res = s.substr(i, j-i+1);
            }
        }
        return res;
    }
};

#elif 1
// center expand
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [l1, r1] = expand(s, i, i);        // C++ 17
            auto [l2, r2] = expand(s, i, i+1);

            if (r1 - l1 > end - start) {
                start = l1;
                end = r1;
            }

            if (r2 - l2 > end - start) {
                start = l2;
                end = r2;
            }
        }

        return res = s.substr(start, end-start+1);
    }

private:
    pair<int, int> expand(string &s, int left, int right) {
        while (left >=0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left+1, right-1};
    }
};

#endif

int main() {
    Solution solve;
    cout << "str = " << solve.longestPalindrome("") << endl;

    cout << "\nFinish";
    return 0;
}