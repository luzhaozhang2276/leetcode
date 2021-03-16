#include <bits/stdc++.h>
using namespace std;

/// 14. 最长公共前缀
// 纵向查找
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty())
            return res;

        for (int i = 0; i < strs[0].size(); ++i) {
            char tmp = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j].size() < i || strs[j][i] != strs[0][i])
                    return res;
            }
            res += tmp;
        }
        return res;
    }
};

int main() {
    vector<string> strs = {"flower","dlow","flight"};

    Solution solve;
    cout << "res = " << solve.longestCommonPrefix(strs) << endl;

    cout << "\nFinish";
    return 0;
}