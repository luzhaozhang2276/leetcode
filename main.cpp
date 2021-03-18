#include <bits/stdc++.h>

using namespace std;

/// 26. 删除有序数组中的重复项
// 双指针 (快慢指针)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int i = 0;
        for (int j = 1; j < nums.size(); ++j)
            if (nums[j] != nums[i])
                nums[++i] = nums[j];

        return i + 1;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution solve;
    cout << "res = " << solve.removeDuplicates(nums) << endl;

    for (auto num : nums)
        cout << num << ' ';

    cout << "\nFinish";
    return 0;
}