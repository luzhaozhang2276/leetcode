#include <bits/stdc++.h>

using namespace std;

/// 76. 最小覆盖子串
// 滑动窗口 + 哈希表
class Solution {
    unordered_map<char, int> win, ori;

    bool check() {
        for (const auto &p : ori) {
            if (win[p.first] < p.second)
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        // initial
        for (const auto &p : t)
            ++ori[p];

        int l = 0, r = -1, start = -1, len = INT_MAX;
        int size = s.size();
        while (r < size) {
            // 右移
            if (ori.find(s[++r]) != ori.end())
                ++win[s[r]];

            // 左移
            while (l <= r && check()) {
                // update
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }

                // remove l in win
                if (ori.find(s[l]) != ori.end())
                    --win[s[l]];

                ++l;
            }
        }

        return start == -1 ? string(): s.substr(start, len);
    }
};


int main() {
    string s = "cabwefgewcwaefgcf";
    string t = "cae";

    Solution solve;
    cout <<"res = " << solve.minWindow(s, t) << endl;

    cout << "\nFinish";
    return 0;
}