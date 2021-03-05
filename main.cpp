#include <bits/stdc++.h>
using namespace std;

/// 双指针
class Solution {
public:
    string reverseWords(string s) {
        // 删除首尾空格
        s.erase(s.find_last_not_of(' ') + 1);
        s.erase(0, s.find_first_not_of(' '));

        int j = s.length() - 1, i = j;
        string res;
        while (i >= 0) {
            while (i >= 0 && s[i] != ' ')
                --i;
            res += s.substr(i + 1, j - i) + ' ';
            while (i >= 0 && s[i] == ' ')
                --i;
            j = i;
        }
        return res.substr(0, res.size() - 1);
    }
};


int main() {
    string str = "the sky is blue";

    Solution solve;
    cout << solve.reverseWords(str) << endl;


    cout << "\nFinish";
    return 0;
}
