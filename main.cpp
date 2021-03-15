#include <bits/stdc++.h>
using namespace std;

/// 8. 字符串转换整数 (atoi)
// 法一: 状态自动机
// 法二 : 逐个判断
class Solution {
public:
    int myAtoi(string s) {
        // 忽略前导空格
        s.erase(0, s.find_first_not_of(' '));

        int sign = 1, ans = 0, i = 0;

        // while (s[i] == ' ')      // 忽略前导空格
        //     ++i;

        if (s[i] == '+' || s[i] == '-')         // 判断正负
            sign = 1 - 2 * (s[i++] == '-');

        while (s[i] >= '0' && s[i] <= '9') {    // 输入合法
            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i] > '7'))  // 判断溢出
                return sign == 1 ? INT_MAX : INT_MIN;

            ans = ans * 10 + (s[i++] - '0');    // 不加括号会溢出
        }

        return ans * sign;
    }
};

int main() {
    Solution solve;
    cout << "x = " << solve.myAtoi("21474836460") << endl;

    cout << "\nFinish";
    return 0;
}