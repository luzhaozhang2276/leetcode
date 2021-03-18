#include <bits/stdc++.h>

using namespace std;

/// 22. 括号生成
// https://leetcode-cn.com/problems/generate-parentheses/solution/di-gui-he-dong-tai-gui-hua-liang-chong-fang-shi-tu/
#if 0
/// dp
// 此处记录了dp值,无需重复计算,以空间换时间
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0] = {""};

        for (int i = 1; i <= n; ++i) {
            vector<string> cur;
            for (int m = 0; m < i; ++m) {
                int k = i - 1 - m;
                vector<string> str1 = dp[m];
                vector<string> str2 = dp[k];

                for (auto s1 : str1) {
                    for (auto s2 : str2) {
                        string s = "(" + s1 + ")" + s2;
                        // string s;
                        // s.append("("+s1);
                        // s.append(")"+s2);
                        cur.emplace_back(s);
                    }
                }
            }
            dp[i] = cur;
        }
        return dp[n];
    }
};
#elif 0
/// dp + 递归
// 此处递归时,进行了重复计算,并未保存dp的中间值
// 时间换空间
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {""};

        vector<string> res;

        for (int m = 0; m < n; ++m) {
            int k = n - 1 - m;
            vector<string> str1 = generateParenthesis(m);
            vector<string> str2 = generateParenthesis(k);

            for (auto s1 : str1)
                for (auto s2 : str2)
                    res.emplace_back("(" + s1 + ")" + s2);
        }
        return res;
    }
};

#elif 1
/// 递归
// 终止条件: 左,右括号剩余数量均为0
// 剪枝: 1. 左括号小于0; 2. 右括号大于左括号
// 递归调用:
//      1. 选择左括号 (本轮curStr+"(")
//      2. 选择右括号 (本轮curStr+")")
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");
        return res;
    }

private:
    vector<string> res;
    void dfs(int left, int right, string str) {
        if (left == 0 && right == 0) {
            res.emplace_back(str);
            return;
        }

        if (left < 0 || left > right)
            return;

        dfs(left-1, right, str+"(");
        dfs(left, right-1, str+")");
    }
};

#endif

int main() {
    Solution solve;
    for (auto p : solve.generateParenthesis(3))
        cout << p << endl;

    cout << "\nFinish";
    return 0;
}