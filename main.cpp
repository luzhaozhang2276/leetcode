#include <bits/stdc++.h>
using namespace std;

/// 13. 罗马数字转整数

class Solution {
public:
    int romanToInt(string s) {
//        if (s.empty())
//            return 0;
        unordered_map<char, int> hashmap {{'I',1}, {'V', 5}, {'X',10}, {'L',50},
                                          {'C',100}, {'D',500}, {'M',1000}};

        int ans = 0;
        int i = 0;
        for (i = 0; i < s.size()-1; ++i) {
            if (hashmap[s[i]] < hashmap[s[i+1]]) {   // 逆序对
                if (s[i] == 'I')
                    ans += (s[i+1]=='V') ? 4 : 9;
                if (s[i] == 'X')
                    ans += (s[i+1]=='L') ? 40 : 90;
                if (s[i] == 'C')
                    ans += (s[i+1]=='D') ? 400 : 900;
                i++;
                continue;
            }
            ans += hashmap[s[i]];
        }

        if (i != s.size())
            ans += hashmap[s[i]];

        return ans;
    }
};

int main() {
    Solution solve;
    cout << "res = " << solve.romanToInt("") << endl;

    cout << "\nFinish";
    return 0;
}