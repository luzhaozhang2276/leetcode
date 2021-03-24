#include <bits/stdc++.h>
using namespace std;

/// 剑指 Offer 48. 最长不含重复字符的子字符串

/// 双指针
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int i = -1, res = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (hash.find(s[j]) != hash.end())    // 重复, 更新左指针
                i = max(hash[s[j]], i);

            hash[s[j]] = j;
            res = max(res, j-i);
        }
        return res;
    }
};



int main() {
    Solution solve;

    cout << "\nFinish";
    return 0;
}