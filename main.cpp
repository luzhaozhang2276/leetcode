#include <bits/stdc++.h>
using namespace std;

#if 0       // 动态规划问题
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n-1;

        int* ans = new int[n+1];
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 2;
        ans[3] = 3;

        int max;
        for (int i = 4; i <= n; ++i)
        {
            max = 0;
            for (int j = 1; j <= i/2; ++j)
            {
                max = (ans[j]*ans[i-j] > max) ? ans[j]*ans[i-j] : max;
                ans[i] = max;
            }
        }
        max = ans[n];
        delete[] ans;

        return max;
    }
};

#else   // 贪婪算法
// 大数取余
//    1. 循环取余
//    2. 快速幂取余

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3)
            return n-1;
        if (n == 4)
            return 4;

        long res = 1;
        while (n > 4)
        {
            res *= 3;
            res %= 1000000007;
            n -= 3;
        }

        return res * n % 1000000007;
    }
};

#endif

int main() {
    Solution s;
    cout << "max: " << s.cuttingRope(4) << endl;


    cout << "\nFinish" << endl;
    return 0;
}
