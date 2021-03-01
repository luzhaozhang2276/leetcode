#include <bits/stdc++.h>
using namespace std;

#if 1

class Solution {
public:
    int countDigitOne(int n) {
        long int digit = 1;
        int res = 0, high = n / 10, cur = n % 10, low = 0;

        while (high != 0 || cur != 0) {
            if (cur == 0)
                res += high * digit;
            else if (cur == 1)
                res += high * digit + low + 1;
            else
                res += (high + 1) * digit;

            low += cur * digit;     // 将cur加入low,进行下一层循环
            cur = high % 10;        // 下一层的cur是本轮high的最低位
            high /= 10;             // 将最低位删除,成为新的high
            digit *= 10;            // 位因子每次*10
        }

        return res;
    }
};
#endif

int main() {
    Solution solve;
    cout << solve.countDigitOne(1410065408) << endl;

    cout << "\nFinish";
    return 0;
}
