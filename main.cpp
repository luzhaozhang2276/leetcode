#include <bits/stdc++.h>
using namespace std;

/// 1. 两数之和

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> set;
        for (auto num : nums) {
            auto ptr = set.find(target - num);
            if (ptr != set.end())
                return {num, *ptr};
            set.insert(num);
        }

        return {};
    }
};

int main() {
    vector<int> nums = {3,6,1,4,2,8,9};

    Solution solve;
    for (auto num : solve.twoSum(nums, 14))
        cout << num << ' ';

    cout << "\nFinish";
    return 0;
}