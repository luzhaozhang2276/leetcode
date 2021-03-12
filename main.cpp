#include <bits/stdc++.h>
using namespace std;

/// 3. 无重复字符的最长子串
// 哈希表 + 双指针 + 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = -1, r = 0, maxLength = 0;
        unordered_map<char, int> hashmap;   // 哈希表用于查找重复字符, 键值: 当前字符最后一次出现的索引
        for (; r < s.length(); ++r) {
            if (hashmap.find(s[r]) != hashmap.end())
                l = max(l, hashmap[s[r]]);  // 滑窗起点
            hashmap[s[r]] = r;
            maxLength = max(maxLength, r - l);  // 实时维护最大量
        }
        return maxLength;
    }
};


int main() {
    string s = "abcabcbb";

    Solution solve;
    cout << "res = " << solve.lengthOfLongestSubstring(s) << endl;

    cout << "\nFinish";
    return 0;
}