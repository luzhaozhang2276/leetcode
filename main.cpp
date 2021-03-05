#include <bits/stdc++.h>
using namespace std;

#if 0
/// 字符串切片
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.length()) + s.substr(0, n);
    }
};

#elif 0
/// 字符串遍历拼接
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res;
        for (int i = n; i < s.length(); ++i)
            res += s[i];
        for (int i = 0; i < n; ++i)
            res += s[i];
        return res;
    }
};

#elif 1
/// 三次翻转
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse_string(s, 0, s.length() - 1);
        reverse_string(s, 0, s.length() - n - 1);
        reverse_string(s, s.length() - n, s.length() - 1);
        return s;
    }

private:
    void reverse_string(string &s, int start, int end) {
        for (int i = start; i <= (start + end) / 2; ++i) {
            char tmp = s[i];
            s[i] = s[start + end - i];
            s[start + end - i] = tmp;
        }
    }
};

#endif

int main() {
    string str = "abcdefg";

    Solution solve;
    cout << solve.reverseLeftWords(str, 2) << endl;


    cout << "\nFinish";
    return 0;
}
