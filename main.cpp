#include <bits/stdc++.h>
using namespace std;

#if 1
/// 手写快排
class Solution {
public:
    string minNumber(vector<int>& nums) {
        string res;
        vector<string> strs;
        strs.reserve(nums.size());
        for (auto p:nums)
            strs.push_back(to_string(p));

        // 内置函数排序
        // sort(strs.begin(), strs.end(), [](string& s1,string& s2){ return s1 + s2 < s2 + s1;});
        fastSort(strs, 0, strs.size() - 1);
        for (auto s:strs)
            res += s;

        return res;
    }

    void fastSort(vector<string>& strs, int l, int r) {
        if (l >= r)
            return;

        int i = l, j = r;
        string temp;
        while (i < j) {
            while ((strs[j] + strs[l]).compare(strs[l] + strs[j]) >= 0 && i < j)
                j--;
            while ((strs[i] + strs[l]).compare(strs[l] + strs[i]) <= 0 && i < j)
                i++;
            temp = strs[i];
            strs[i] = strs[j];
            strs[j] = temp;
        }

        strs[i] = strs[l];
        strs[l] = temp;
        fastSort(strs, l, i - 1);
        fastSort(strs, i + 1, r);
    }

};

#elif 1
/// 内置函数 快排
class Solution {
public:
    string minNumber(vector<int>& nums) {
        string res;
        vector<string> strs;
        strs.reserve(nums.size());
        for (auto p:nums)
            strs.push_back(to_string(p));

        // 内置函数排序
        sort(strs.begin(), strs.end(), [](string& s1,string& s2){ return s1 + s2 < s2 + s1;});
        for (auto s:strs)
            res += s;

        return res;
    }
};

#endif

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};

    Solution solve;
    string res;
    res = solve.minNumber(nums);
    cout << res << endl;

    cout << "\nFinish";
    return 0;
}
