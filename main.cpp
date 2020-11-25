#include <bits/stdc++.h>
using namespace std;

#if 1       // 动态规划问题
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

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

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        int time3 = n/3;
        if ((n - 3*time3) == 1)
            time3--;

        int time2 = (n - 3*time3) / 2;

        return int(pow(3,time3) * pow(2, time2));
    }
};

#endif

int main() {
    Solution s;
    cout << "max: " << s.cuttingRope(10) << endl;


    cout << "\nFinish" << endl;
    return 0;
}
