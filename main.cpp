#include <bits/stdc++.h>
using namespace std;

#if 0
/// DP + 迭代
class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;
        for (int i = 2; i <= n; ++i)
            x = (x + m) % i;
        return x;
    }
};

#elif 1
/// 递归  (数据较多时,栈空间可能会溢出)
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 1)
            return 0;

        int x = lastRemaining(n - 1, m);
        return (x + m) % n;
    }
};

#endif

int main() {
    Solution solve;
    cout << "res = " << solve.lastRemaining(5, 3) << endl;

    cout << "\nFinish";
    return 0;
}
