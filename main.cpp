#include <bits/stdc++.h>
using namespace std;

#if 0
/// DP + 哈希表
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;
        int res = 0, tmp = 0;
        for (int j = 0; j < s.length(); ++j) {
            int i = -1;
            if (hashmap.count(s[j]))
                i = hashmap[s[j]];

            hashmap[s[j]] = j;  // 记录新字符的索引(会覆盖掉重复字符索引,覆盖前的索引记录在i中)
            tmp = tmp < j - i ? tmp + 1 : j - i;    // 距离d = j - i, 上一个满足的长度为tmp
                                                    // 重复字符在tmp之外: tmp + 1, 即直接将重复字符附在后边
                                                    // 重复字符在tmp之内: j - i,   即本次长度为较短的长度j-i
            res = max(res, tmp);
        }

        return res;
    }
};

#elif 0
/// DP + 线性遍历
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, tmp = 0;
        for (int j = 0; j < s.length(); ++j) {
            int i = j - 1;
            while (i >= 0 && s[i] != s[j])
                i--;
            tmp = tmp < j - i ? tmp + 1 : j - i;    // 距离d = j - i, 上一个满足的长度为tmp
            // 重复字符在tmp之外: tmp + 1, 即直接将重复字符附在后边
            // 重复字符在tmp之内: j - i,   即本次长度为较短的长度j-i
            res = max(res, tmp);
        }

        return res;
    }
};

#elif 0
/// DP + 哈希表 + 双指针
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;
        int res = 0, i = -1;
        for (int j = 0; j < s.length(); ++j) {
            if (hashmap.count(s[j]))
                i = max(hashmap[s[j]], i);

            hashmap[s[j]] = j;  // 记录新字符的索引(会覆盖掉重复字符索引,覆盖前的索引记录在i中)
            res = max(res, j - i);
        }

        return res;
    }
};

#elif 1
/// 滑动窗口法
// 此方法与上边的哈希表法相似,都是滑动窗口法
// 区别:上边为哈希表查找,本方法为while遍历查找
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> windows;
        int left = 0, res = 0;
        for (auto right:s) {
            while (windows.find(right) != windows.end()) {
                windows.erase(s[left]);
                ++left;
            }
            windows.insert(right);
            // res = res > windows.size() ? res : windows.size();
            res = max(res, int(windows.size()));
        }

        return res;
    }
};

#endif

int main() {
    string s = "abcabcbb";

    Solution solve;
    cout << "size = " << solve.lengthOfLongestSubstring(s) << endl;

    cout << "\nFinish";
    return 0;
}
