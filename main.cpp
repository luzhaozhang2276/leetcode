#include <bits/stdc++.h>
using namespace std;

/// 4. 寻找两个正序数组的中位数
// 二分法 : 题目要求时间复杂度为 O(log(m+n)), 通常需要使用到二分法
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        if ((m+n)&1)    // 判断奇偶
            return topK(nums1, nums2, (m+n)/2 + 1);     // 奇数
        else
            return (topK(nums1, nums2, (m+n)/2) + topK(nums1, nums2, (m+n)/2 + 1))/2.0;
    }

private:
    int m,n;
    int topK(vector<int>& nums1, vector<int>& nums2, int k) {
        int l1 = 0, l2 = 0;
        while (true) {
            if (l1 == m)    // l1为空
                return nums2[l2 + k - 1];
            if (l2 == n)    // l2为空
                return nums1[l1 + k - 1];
            if (k == 1)     // 返回最小值
                return min(nums1[l1], nums2[l2]);

            int newl1 = min(l1 + k/2 - 1, m-1);     // 防止越界
            int newl2 = min(l2 + k/2 - 1, n-1);
            if (nums1[newl1] <= nums2[newl2]) {     // 判断大小, 剔除小的部分
                k -= newl1 - l1 + 1;
                l1 = newl1 + 1;
            }
            else {
                k -= newl2 - l2 + 1;
                l2 = newl2 + 1;
            }
        }
    }
};


int main() {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    Solution solve;
    cout << "mid = " << solve.findMedianSortedArrays(nums1, nums2) << endl;

    cout << "\nFinish";
    return 0;
}