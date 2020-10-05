#include <bits/stdc++.h>

using namespace std;

/// 法一:哈希表
//class Solution {
//public:
//    int findRepeatNumber(vector<int>& nums) {
//        unordered_map<int, bool> map;
//        for(int num : nums) {
//            if(map[num]) return num;
//            map[num] = true;
//        }
//        return -1;
//    }
//};

/// 法二:原地交换
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i=0;
        while (i < nums.size())
        {
            if(nums[i] == i)
            {
                i++;
                continue;
            }

            else if(nums[nums[i]] == nums[i])
                return nums[i];
            else
                swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    Solution s;
    cout << s.findRepeatNumber(nums) << endl;

    cout << "\nFinish" << endl;
    return 0;
}

/**
 * @note unordered_map 哈希表 查找问题
 * https://blog.csdn.net/wangdongwei0/article/details/97035416
 */