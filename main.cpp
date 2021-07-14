#include <bits/stdc++.h>

using namespace std;

/// 33. 搜索旋转排序数组
/// 二分法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }

        }

        return -1;
    }
};

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};

    Solution solve;
    cout << "res = " << solve.search(nums, 8) << endl;


    cout << "\nFinish";
    return 0;
}