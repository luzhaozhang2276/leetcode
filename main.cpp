#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int BK(int x) {
        int cnt = 0;
        while (x != 0) {
            x = x & (x - 1);
            cnt++;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        /// BK
        //vector<int> res;
        //for (int i = 0; i <= n; ++i) {
        //    res.push_back(BK(i));
        //}

        /// bit
        vector<int> res(n+1);
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i&(i-1)] + 1;
        }

        return res;
    }
};

int main() {
    Solution solve;
    for (const auto &p : solve.countBits(5))
        cout << p << ' ';
    cout << endl;

    return 0;
}