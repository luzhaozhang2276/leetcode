#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /// 查找第一个比target大的数
    int findFirst(vector<int>& nums, int target) {
        if (nums.empty() || target > nums[nums.size()-1])
            return -1;

        int l = 0, r = nums.size() - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = findFirst(nums, target);
        int r = findFirst(nums, target + 1);

        if (l == -1 || nums[l] != target)   // 超出范围 or 不存在target
            return {-1, -1};
        if (r == -1)        // 最后一个数为target
            r = nums.size();

        return {l, r-1};
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
//    vector<int> nums = {1};

    Solution solve;

    cout << solve.findFirst(nums, 11) <<endl;

    for (const auto &p : solve.searchRange(nums, 1))
        cout << p << ' ';


    cout << "\nFinish";
    return 0;
}