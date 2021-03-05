#include <bits/stdc++.h>
using namespace std;

// 异或运算:
//      1. 相同为0,不同为1
//      2. 满足交换律
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0, y = 0, n = 0, m = 1;

        // 1. 遍历异或,得到 x OR y 的结果(二进制)
        for (int num:nums)
            n ^= num;

        // 2. 获取整数 x OR y 首位 1 (即不同的二进制位)
        while ((n & m) == 0)
            m <<= 1;

        // 3. 遍历并分组
        for (int num:nums) {
            if (num & m)    // 根据x y对应的二进制位m不同,能够分成两组,分别组内异或求取x y (不用单独开辟空间保存分组,在原始数据上进行)
                x ^= num;
            else
                y ^=  num;
        }

        return vector<int> {x, y};
    }
};

int main() {
    vector<int> nums = {4,1,4,6};

    Solution solve;
    for (auto p:solve.singleNumbers(nums))
        cout << p << ' ';

    cout << "\nFinish";
    return 0;
}
