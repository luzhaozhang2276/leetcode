#include <bits/stdc++.h>
using namespace std;

/// 单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;

        if (nums.empty() || k == 0)
            return res;

        deque<int> maxWindow;
        for (int j = 0, i = 1 - k; j < nums.size(); ++i, ++j) {
            if (i > 0 && maxWindow.front() == nums[i - 1])  // 最大值超出窗口,则删除队列中的最大值(队首出队)
                maxWindow.pop_front();

            while (!maxWindow.empty() && maxWindow.back() < nums[j])    // 保持 deque 单调递减
                maxWindow.pop_back();
            maxWindow.push_back(nums[j]);

            if (i >= 0)     // 记录窗口的最大值
                res.push_back(maxWindow.front());
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,4,7};

    Solution solve;
    for (auto p : solve.maxSlidingWindow(nums, 3))
        cout << p << ' ';


    cout << "\nFinish";
    return 0;
}
