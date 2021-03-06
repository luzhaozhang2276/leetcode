#include <bits/stdc++.h>
using namespace std;

#if 1
/// 集合set + 遍历
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        set<int> repeat;    // 用于查重
        int max = 0, min = 14;

        for (auto num : nums) {
            if (num == 0)
                continue;
            max = max > num ? max : num;
            min = min > num ? num : min;

            if (repeat.find(num) != repeat.end())
                return false;
            repeat.insert(num);
        }

        return max - min < 5;
    }
};

#elif 1
/// 排序 + 遍历
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int joker = 0;  // 王牌的数量
        sort(nums.begin(), nums.end());

        for (int i = 0; i < 4; ++i) {
            if (nums[i] == 0)
                ++joker;
            else if (nums[i] == nums[i + 1])    // 重复提前结束
                return false;
        }

        return nums[4] - nums[joker] < 5;
    }
};

#endif

int main() {
    vector<int> nums = {4,6,7,5,3};

    Solution solve;
    string res = solve.isStraight(nums) ? "True" : "False";
    cout << "straight = " << res << endl;

    cout << "\nFinish";
    return 0;
}
