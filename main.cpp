#include <bits/stdc++.h>

using namespace std;

/// 78. 子集
// 回溯法
class Solution {
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int>& path, int idx) {
        res.push_back(path);
        for (int i = idx; i < nums.size(); ++i) {
            //if (i > idx && nums[i] == nums[i-1])
            //    continue;
            path.push_back(nums[i]);
            backtrack(nums, path, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(nums, path, 0);

        return res;
    }
};


int main() {
    vector<int> nums = {1,2,3};

    Solution solve;
    for (const auto &ps : solve.subsets(nums)) {
        for (const auto &p : ps)
            cout << p << ' ';
        cout << endl;
    }

    cout << "\nFinish";
    return 0;
}