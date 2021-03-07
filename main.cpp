#include <bits/stdc++.h>
using namespace std;

#if 0
/// 表格分区 : 双循环 依次遍历下三角和上三角
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> b(a.size(), 1);
//        if (a.empty())
//            return b;
//
//        b[0] = 1;
        for (int i = 1; i < a.size(); ++i)      // 计算下三角
            b[i] = b[i - 1] * a[i - 1];

        int tmp = 1;        // 计算上三角
        for (int i = a.size() - 2; i >= 0; --i) {
            tmp *= a[i + 1];
            b[i] *= tmp;
        }

        return b;
    }
};

#elif 1
/// 改进: 一次循环   两端同时进行
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        vector<int> b(len, 1);
        if (a.empty())
            return b;

        int left = 1, right = 1;
        for (int i = 0; i < len; ++i) {
            b[i] *= left;
            left *= a[i];               // 计算左边乘积

            b[len - i - 1] *= right;
            right *= a[len - i - 1];    // 计算右边乘积
        }
        return b;
    }
};

#endif


int main() {
    vector<int> nums = {1,2,3,4,5};

    Solution solve;
    for (auto sum : solve.constructArr(nums))
        cout << sum << ' ';

    cout << "\nFinish";
    return 0;
}