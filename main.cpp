#include <bits/stdc++.h>
using namespace std;

#if 1
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
/// 循环解法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int nCurSum = 0;
        int nGreatestSum = 0x80000000;      // int 最小负数
        for (auto p:nums)
        {
            if (nCurSum <= 0)
                nCurSum = p;
            else
                nCurSum += p;

            if (nCurSum > nGreatestSum)
                nGreatestSum = nCurSum;
        }

        return nGreatestSum;
    }
};
#endif


int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution solve;
    cout << solve.maxSubArray(nums) << endl;

    cout << "\nFinish";
    return 0;
}
