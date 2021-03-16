#include <bits/stdc++.h>
using namespace std;

/// 16. 最接近的三数之和
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int diff = INT_MAX;
        for (int k = 0; k < nums.size() - 2; ++k) {
            if (k > 0 && nums[k] == nums[k - 1])    // 剪枝 : 重复
                continue;
            int left = k + 1, right = nums.size() - 1;
            while (left < right) {
                int tmp = nums[k] + nums[left] + nums[right] - target;
                diff = (abs(diff) > abs(tmp)) ? tmp : diff;

                if (tmp < 0)
                    while (left < right && nums[left] == nums[++left]);
                else if (tmp > 0)
                    while (left < right && nums[right] == nums[--right]);
                else
                    return target;
            }
        }

        return target + diff;
    }
};

int main() {
    vector<int> nums = {0,0,0};

    Solution solve;
    cout << "res = " << solve.threeSumClosest(nums, 1) << endl;

    cout << "\nFinish";
    return 0;
}