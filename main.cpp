#include <bits/stdc++.h>

using namespace std;

/// sort + hashmap
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (string &s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            // cout << key << " , " << s << endl;
            map[key].emplace_back(s);
        }

        vector<vector<string>> res;
        for (auto &p : map) {
            res.emplace_back(p.second);
        }

        return res;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution solve;
    for (const auto &p : solve.groupAnagrams(strs)) {
        for (const auto &s : p)
            cout << s << ' ';
        cout <<endl;
    }

    cout << "\nFinish";
    return 0;
}