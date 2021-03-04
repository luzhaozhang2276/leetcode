#include <bits/stdc++.h>
using namespace std;

#if 1
// 二分法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return findright(nums, target) - findright(nums, target - 1);
    }

private:
    int findright(vector<int>& nums, int target) {
        // 找右边界
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int middle = (l + r) / 2;
            if (nums[middle] <= target)
                l = middle + 1;
            else
                r = middle - 1;
        }
        return l;
    }
};
#elif 1
// 二分法 (代码冗余)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left, right;
        // 找右边界
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int middle = (l + r) / 2;
            if (nums[middle] <= target)
                l = middle + 1;
            else
                r = middle - 1;
        }
        right = l;

        // 找左边界
        l = 0, r = nums.size() - 1;
        while (l <= r) {
            int middle = (l + r) / 2;
            if (nums[middle] < target)
                l = middle + 1;
            else
                r = middle - 1;
        }
        left = r;

        return right - left - 1;
    }
};
#endif

int main() {
    vector<int> nums = {5,7,7,8,8,10};

    Solution solve;
    cout << "num = " << solve.search(nums, 8) << endl;

    cout << "\nFinish";
    return 0;
}
