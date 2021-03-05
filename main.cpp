#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int ahead = 0, behind = nums.size() - 1;

        while (ahead <= behind) {
            long sum = nums[ahead] + nums[behind];
            if (sum == target)
                return vector<int>{nums[ahead], nums[behind]};
            else if (sum < target)
                ahead++;
            else
                behind--;
        }
        return vector<int>{};
    }
};

int main() {
    vector<int> nums = {1,2,4,7,11,15};

    Solution solve;
    for (auto p:solve.twoSum(nums, 15))
        cout << p << ' ';

    cout << "\nFinish";
    return 0;
}
