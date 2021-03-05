#include <bits/stdc++.h>
using namespace std;

#if 1
/// 哈希表
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hashmap;

        for (int i : nums)
            ++hashmap[i];

        unordered_map<int, int>::const_iterator itr;
        for (int i : nums) {
            itr = hashmap.find(i);
            if (itr->second == 1)
                return itr->first;
        }

        return -1;
    }
};

#elif 1
/// 有限状态自动机
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int high = 0, low = 0;
        for (int num : nums) {
            low  = low ^ num & ~high;   // 直接对32位都进行了运算
            high = high ^ num & ~low;
        }
        return low;
    }
};

#elif 1
/// 遍历统计
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int counts[32] = {0};
        for (auto num:nums) {
            for (int j = 0; j < 32; ++j) {
                counts[j] += num & 1;   // 更新第 j 位 (判断最低位，下一步右移更新)
                num >>= 1;              // j -> j+1
            }
        }

        int res = 0, m = 3;
        for (int i = 0; i < 32; ++i) {
            res <<= 1;
            res |= counts[31 - i] % m;
        }

        return res;
    }
};
#endif

int main() {
    vector<int> nums = {3,4,3,3};

    Solution solve;
    cout << "res = " << solve.singleNumber(nums) << endl;

    cout << "\nFinish";
    return 0;
}
