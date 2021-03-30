#include <bits/stdc++.h>
using namespace std;

/// 20. 有效的括号
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hash = {{'[',']'}, {'(',')'}, {'{','}'}, {'?', '?'}};
        stack<char> symbol;
        for (auto c : s) {
            if (hash.find(c) != hash.end())   // found left
                symbol.push(c);
            else {  // found right
                if (symbol.empty() || hash[symbol.top()] != c)     // unmatched
                    return false;
                symbol.pop();
            }
        }

        return symbol.empty();
    }
};

int main() {
    Solution solve;

    cout << "\nFinish" << endl;
    return 0;
}
