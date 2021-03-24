#include <bits/stdc++.h>
using namespace std;

/// 剑指 Offer 42. 连续子数组的最大和

#if 0
// 双指针
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = INT_MIN, res = INT_MIN;

//        for (int i = 0; i < nums.size(); ++i) {
//            if (curr < 0)
//                curr = max(curr, nums[i]);
//            else
//                curr += nums[i];
//
//            res = max(curr, res);
//        }

        for (auto num : nums) {
            curr = (curr < 0) ? max(curr, num) : curr + num;
            res = max(curr, res);
        }

        return res;
    }
};
#elif 1
/// DP 解法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] > 0)
                nums[i] = nums[i-1] + nums[i];
            res = max(res,nums[i]);
        }
        return res;
    }
};
#elif 1
// DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        vector<int> dp(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i-1] <= 0)
                dp[i] = nums[i];
            else
                dp[i] = dp[i-1] + nums[i];

            res = max(res, dp[i]);

        }

        return res;
    }
};
#endif


int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solve;
    cout << "res = " << solve.maxSubArray(nums) << endl;

    cout << "\nFinish";
    return 0;
}