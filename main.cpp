#include <bits/stdc++.h>
using namespace std;

/// 递归 (与运算作为递归终止条件)
class Solution {
public:
    int sumNums(int n) {
        n  && (n += sumNums(n - 1));
        return n;
    }
};

int main() {
    Solution solve;
    cout << "sum = " << solve.sumNums(3) << endl;

    cout << "\nFinish";
    return 0;
}