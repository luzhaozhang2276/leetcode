#include <bits/stdc++.h>

#include <utility>
using namespace std;

/// 17. 电话号码的字母组合
// 回溯法 (全排列可参照剑指offer38)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return res;

        phoneMap = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
                 {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};

        string combine;
        traceback(digits, combine, 0);
        return res;
    }

private:
    unordered_map<char, string> phoneMap;
    vector<string> res;
    void traceback(string s, string combine, int x) {
        if (x == s.size()) {
            res.push_back(combine);       // 添加排列方案
            return;
        }

        for (char c : phoneMap[s[x]]) {
            combine.push_back(c);
            traceback(s, combine, x+1);          // 开始固定第 x+1 位
            combine.pop_back();
        }
    }
};

int main() {
    Solution solve;
    for (auto s : solve.letterCombinations(""))
        cout << s << ' ';

    cout << "\nFinish";
    return 0;
}