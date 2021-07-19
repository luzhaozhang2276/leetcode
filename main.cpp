#include <bits/stdc++.h>

using namespace std;


#if 0
/// 暴力法
/// 双层循环
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int max_left = 0, max_right = 0;

            for (int j = i; j >= 0; j--) {
                max_left = max(max_left, height[j]);
            }

            for (int j = i; j < size; j++) {
                max_right = max(max_right, height[j]);
            }

            res += min(max_left, max_right) - height[i];
        }

        return res;
    }
};

#elif 0
/// 单层循环 * 3
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();

        if (size < 3)
            return 0;

        vector<int> maxLefts(size, 0);
        vector<int> maxRights(size, 0);

        maxLefts[0] = height[0];
        for (int i = 1; i < size; ++i)
            maxLefts[i] = max(height[i], maxLefts[i-1]);

        maxRights[size-1] = height[size-1];
        for (int i = size - 2; i >= 0; --i)
            maxRights[i] = max(height[i], maxRights[i + 1]);

        int res = 0;
        for (int i = 1; i < size - 1; ++i)
            res += min(maxLefts[i], maxRights[i]) - height[i];

        return res;
    }
};

#elif 1
/// 双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left_max = 0, right_max = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max)
                    left_max = height[left];
                else
                    res += left_max - height[left];
                left++;
            }
            else {
                if (height[right] >= right_max)
                    right_max = height[right];
                else
                    res += right_max - height[right];

                right--;
            }
        }

        return res;
    }
};

#endif

int main() {
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
//    vector<int> nums = {2,0,9,2};

    Solution solve;
    cout << "res = " << solve.trap(nums) << endl;


    cout << "\nFinish";
    return 0;
}