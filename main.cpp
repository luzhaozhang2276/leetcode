#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;

        int l = nums.size() - 2;
        int r = nums.size() - 1;
        while (l >= 0 && nums[l] >= nums[l+1])  // 从后往前找到首个递减的数
            --l;

        if (l >= 0) {
            while (r >=0 && nums[r] <= nums[l]) // 在l后找到首个大的数
                --r;
            swap(nums[l], nums[r]);
        }

        sort(nums.begin() + l + 1, nums.end()); // 后边元素有序(l=-1,则全部重排)
    }
};

int main() {
    vector<int> nums = {1,2,3};

    Solution solve;
    solve.nextPermutation(nums);

    for (const auto &n : nums)
        cout << n << ' ';

    cout << "\nFinish";
    return 0;
}