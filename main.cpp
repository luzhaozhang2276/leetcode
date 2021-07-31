#include <bits/stdc++.h>

using namespace std;

/// 75. 颜色分类  双指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; ++i) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                p2--;
            }

            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0++;
            }
        }
    }
};

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    nums = {1,0,1};

    Solution solve;
    solve.sortColors(nums);
    for (const auto n : nums)
        cout << n << ' ';

    cout << "\nFinish";
    return 0;
}