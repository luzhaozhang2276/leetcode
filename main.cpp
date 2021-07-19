#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], pre = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            pre = max(pre+nums[i], nums[i]);
            res = max(res, pre);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution solve;
    cout << "res = " << solve.maxSubArray(nums) <<endl;


    cout << "\nFinish";
    return 0;
}