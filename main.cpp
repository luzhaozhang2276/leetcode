#include <bits/stdc++.h>
using namespace std;

/// 9. 回文数

#if 0
/// 字符串
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string s = to_string(x);
        auto l = s.begin(), r = s.end() - 1;
        while (l <= r)
            if (*(l++) != *(r--))
                return false;

        return true;
    }
};
#elif 0
/// 直接在数字上判断
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int div = 1;    // 位数
        while (x / div >= 10)
            div *= 10;

        while (x > 0) {
            if (x / div != x % 10)  // 判断首尾
                return false;
            x = (x % div) / 10;     // 去头去尾
            div /= 100;
        }
        return true;
    }
};

#elif 1
/// 翻转数字
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversenum = 0;
        while (x > reversenum) {
            reversenum = reversenum * 10 + x % 10;
            x /= 10;
        }

        return x == reversenum || x == reversenum / 10;
    }
};

#endif

int main() {
    Solution solve;
    cout << "x = " << solve.isPalindrome(121) << endl;

    cout << "\nFinish";
    return 0;
}