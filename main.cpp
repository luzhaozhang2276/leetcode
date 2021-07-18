#include <bits/stdc++.h>

using namespace std;

/// 39. 组合总和
/// 回溯+剪枝
class Solution {
    vector<vector<int>> res;
    vector<int> combine;

    void dfs(vector<int>& candidates, int target, int idx) {
        if (idx == candidates.size()) {
            if (target == 0)
                res.push_back(combine);
            return;
        }

        dfs(candidates, target, idx+1);

        if (target - candidates[idx] >= 0) {
            combine.push_back(candidates[idx]);
            dfs(candidates, target-candidates[idx], idx);   // 可重复 idx， 不可重复 idx+1
            combine.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return res;
    }
};

int main() {
    vector<int> nums = {2, 3, 5, 7};

    Solution solve;
    for (const auto &ps :solve.combinationSum(nums, 7)) {
        for (const auto &num : ps)
            cout << num << ' ';
        cout <<endl;
    }

    cout << "\nFinish";
    return 0;
}