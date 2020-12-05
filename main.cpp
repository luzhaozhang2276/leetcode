#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, long int n) {
        double base = 1;
        int plus_n = 1;
        n = floor(n);
        if (n == 0)
            return 1;
        if (n < 0)
        {
            // if (x == 0)
            //     return 0;
            plus_n = -1;
        }

        /// 循环求幂  超出时间限制
        // for (int i = 0; i < plus_n * n; ++i)
        //     base *= x;

        /// 二分求幂
        base = computePow(x,plus_n * n);

        return plus_n == 1 ? base : 1/base;
    }

    double computePow(double x, long int e) {
        double base = 1;
        if (e == 1)
            return x;
        base = computePow(x, e>>1); // 右移除2
        if ((e & 0x1) == 1)     // 判断奇偶
            return x * base*base;
        return base*base;
    }
};

int main() {
    Solution s;
    cout << "result = " << s.myPow(1,-2147483648) << endl;

    cout << "\nFinish" << endl;
    return 0;
}
