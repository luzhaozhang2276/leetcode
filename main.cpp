#include <bits/stdc++.h>
using namespace std;

#if 0
/// 递归
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        return recur(s, 0);
    }

    int recur(string& s, int idx) {
        int n = s.size();
        if(idx == n)
            return 1;

        if (idx == n - 1 || s[idx] == '0' || s.substr(idx, 2) > "25")
            return recur(s, idx + 1);

        return recur(s, idx + 1) + recur(s, idx + 2);
    }
};
#elif 1
/// DP动态规划 字符串遍历
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int a = 1, b = 1;
        for (int i = 2; i <= s.length(); ++i) {
            string temp = s.substr(i - 2, 2);
            int c = temp.compare("10") >= 0 && temp.compare("25") <= 0 ?
                    a + b : a;
            b = a;
            a = c;
        }
        return a;
    }
};

#elif 1
/// DP动态规划 数字取余
class Solution {
public:
    int translateNum(int num) {
        int a = 1, b = 1, x, y = num % 10;
        while (num != 0) {
            num /= 10;
            x = num % 10;
            int tmp = 10 * x + y;
            int c = (tmp >= 10 && tmp <= 25) ? a + b : a;
            b = a;
            a = c;
            y = x;
        }
        return a;
    }
};
#endif

int main() {
    Solution solve;
    cout << "sum = " << solve.translateNum(25) << endl;

    cout << "\nFinish";
    return 0;
}
