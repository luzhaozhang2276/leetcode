#include <bits/stdc++.h>
using namespace std;

// 归并排序 递归
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(0, nums.size() - 1, nums, tmp);
    }

private:
    int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
        // 终止条件
        if (l >= r)
            return 0;
        // 递归划分
        int m = (l + r) / 2;    // 中点划分: i(起点,前半部), j(中点,后半部)
        int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
        // 合并阶段
        int i = l, j = m + 1;
        for (int k = l; k <= r; ++k)    // tmp 复制需要排序的子片段,之后进行前后对比,将结果依次存到nums中
            tmp[k] = nums[k];
        for (int k = l; k <= r; ++k) {
            if (i == m + 1)             // 前者已变遍历完,将剩余后者存入nums中
                nums[k] = tmp[j++];
            else if (j == r + 1 || tmp[i] <= tmp[j])    // 不存在逆序对,将前者(小)存入nums中
                nums[k] = tmp[i++];
            else {                      // 存在逆序对,计数更新,并将后者(小)存入nums中
                nums[k] = tmp[j++];
                res += m - i + 1;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {7,5,6,4};
    Solution solve;
    cout << "res = " << solve.reversePairs(nums) << endl;

    cout << "\nFinish";
    return 0;
}
