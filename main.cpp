#include <bits/stdc++.h>

using namespace std;

/// 回溯法
class Solution {
    vector<vector<int>> res;
    int size;

    void backtrack(vector<int>& nums, int idx) {
        if (idx == size) {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < size; ++i) {
            swap(nums[i], nums[idx]);
            backtrack(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        backtrack(nums, 0);
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3};

    Solution solve;
    for (const auto &s : solve.permute(nums)) {
        for (const auto &num : s)
            cout << num << ' ';
        cout << endl;
    }


    cout << "\nFinish";
    return 0;
}