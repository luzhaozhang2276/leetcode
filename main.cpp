#include <bits/stdc++.h>
using namespace std;

#if 0
/// 哈希表
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, bool> hashmap;
        for (auto c:s)
            hashmap[c] = hashmap.find(c) == hashmap.end();
        for (auto c:s)
            if (hashmap[c])
                return c;
        return ' ';
    }
};

#elif 0
/// 有序哈希表
class Solution {
public:
    char firstUniqChar(string s) {
        vector<char> keys;
        unordered_map<char, bool> hashmap;
        for (auto c:s) {
            if (hashmap.find(c) == hashmap.end())   // 记录每个字符抽次出现的次序
                keys.push_back(c);
            hashmap[c] = hashmap.find(c) == hashmap.end();

        }
        for (auto c:keys)       // 遍历出现过的字符(重复也只访问一次),查看该字符是否重复
            if (hashmap[c])
                return c;
        return ' ';
    }
};

#elif 1
/// 数组模拟哈希表
class Solution {
public:
    char firstUniqChar(string s) {
        int count[26] = {0};
        for (auto c:s)
            count[c-'a']++;

        for (auto c:s)
            if (count[c-'a'] == 1)
                return c;

        return ' ';
    }
};
#endif

int main() {
    string s = "abaccdeff";
    Solution solve;
    cout << "res = " << solve.firstUniqChar(s) << endl;

    cout << "\nFinish";
    return 0;
}
