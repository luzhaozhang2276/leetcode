#include <bits/stdc++.h>
using namespace std;

/// 11. 盛最多水的容器
// 双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int head = 0, tail = height.size() - 1, res = 0;
        while (head < tail)
            res = height[head] > height[tail] ?
                  max(res, (tail-head) * height[tail--]):
                  max(res, (tail-head) * height[head++]);
        return res;
    }
};

int main() {
    vector<int> nums = {1,8,6,2,5,4,8,3,7};

    Solution solve;
    cout << "res = " << solve.maxArea(nums) << endl;

    cout << "\nFinish";
    return 0;
}