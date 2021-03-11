#include <bits/stdc++.h>
using namespace std;

/// 哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = hashmap.find(target - nums[i]);
            if (iter != hashmap.end())
                return {iter->second, i};
            hashmap[nums[i]] = i;
        }
        return {};
    }
};


int main() {
    vector<int> nums = {2,7,11,15};

    Solution solve;
    for (auto p:solve.twoSum(nums, 9))
        cout << p << ' ';

    cout << "\nFinish";
    return 0;
}