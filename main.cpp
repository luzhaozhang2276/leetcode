#include <bits/stdc++.h>
using namespace std;

/// 215. 数组中的第K个最大元素

#if 1
/// 优先队列
struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // priority_queue<int, vector<int>, less<int> > heap;       // 大顶堆(默认)
        // priority_queue<int, vector<int>, greater<int> > heap;    // 小顶堆


        priority_queue<int, vector<int>, cmp> heap;   // 默认大顶堆, 此处应为小顶堆
        for (int i = 0; i < k; ++i)
            heap.push(nums[i]);

        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();

    }
};

#elif 1

#endif

int main() {
    vector<int> nums = {3,6,1,4,2,8,9};

    Solution solve;
    cout << "num = " << solve.findKthLargest(nums, 4);

    cout << "\nFinish";
    return 0;
}