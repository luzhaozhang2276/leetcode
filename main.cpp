#include <bits/stdc++.h>

using namespace std;

/// 20. 有效的括号
#if 1
// 栈 + 哈希表 + 剪枝(奇数false)
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if ((n & 1) == 1)
            return false;

        // 此处 key 的选取与下边if判断有关;
        // 若 key 为右括号,则if判断右括号; 反之亦然
        unordered_map<char, char> pairs = {{')','('}, {'}','{'}, {']','['}};
        stack<char> sta;    // 可初始化一个'?',且哈希表增加{'?','?'},则下边不需要判断栈空 (栈空变成 ? )

        for (char c : s) {
            if (pairs.count(c)) {           /// 右括号
                if (sta.empty() || sta.top() != pairs[c])   // 栈为空 or 与栈顶的左括号不匹配 : false
                    return false;
                sta.pop();
            } else
                sta.push(c);                /// 左括号
        }

        return sta.empty();
    }
};

#elif 1
// 栈 + 结束字符(? or #)
class Solution {
public:
    bool isValid(string s) {
        s.push_back('?');
        stack<char> sta;
        sta.push('?');
        for (auto c : s) {
            if (sta.empty() || (c == '(' || c == '{' || c == '[')) {
                sta.push(c);
                continue;
            }

            if (sta.top() == '?')
                return c == '?';

            if (sta.top() == '(' && c!=')' ||
                sta.top() == '{' && c!='}' ||
                sta.top() == '[' && c!=']')
                return false;

            sta.pop();
        }
        return false;
    }
};

#endif

int main() {

    Solution solve;
    cout << "res = " << solve.isValid("{[]}))") << endl;

    cout << "\nFinish";
    return 0;
}