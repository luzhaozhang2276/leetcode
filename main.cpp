#include <bits/stdc++.h>

using namespace std;

/// 55. 跳跃游戏
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (end < i)
                return false;
            end = max(end, i + nums[i]);
            if (end >= nums.size() - 1)
                return true;
        }

        return end >= nums.size();
    }
};

int main() {
    vector<int> nums = {3,2,1,0,4};

    Solution solve;
    string res;
    res = solve.canJump(nums) ? "true" : "false";
    cout << "res = " << res << endl;

    cout << "\nFinish";
    return 0;
}