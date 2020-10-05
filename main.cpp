#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> rem;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (rem.find(target - nums[i] ) != rem.end()) {
                res.push_back(rem[target - nums[i]]);
                res.push_back(i);
                break;
            }
            rem[nums[i]] = i;
        }
        return res;
    }
};

int main() {
    vector<int> nums, rems;
    nums.push_back(2);
    nums.push_back(11);
    nums.push_back(12);
    nums.push_back(13);
    nums.push_back(14);
    nums.push_back(7);
    Solution s;
    rems = s.twoSum(nums, 9);

    for (auto &p:rems)
        cout << p << endl;

    cout << "\nFinish" << endl;
    return 0;
}

/**
 * @note unordered_map 哈希表 查找问题
 * https://blog.csdn.net/wangdongwei0/article/details/97035416
 */