#include <bits/stdc++.h>
using namespace std;

#if 0
/// 滑动窗口(双指针)
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int small = 1, big = 2, sum = 3;
        while (small < big) {
            if (sum == target) {
                vector<int> ans;
                for (int i = small; i <= big; ++i)
                    ans.push_back(i);
                res.push_back(ans);
            }

            if (sum >= target) {
                sum -= small;
                ++small;
            } else {
                ++big;
                sum += big;
            }
        }
        return res;
    }

private:
    vector<vector<int>> res;
};

#elif 1
/// 等差数列求和公式
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1;
        double j = 2.0;
        vector<vector<int>> res;
        while (i < j) {
            j = (-1 + sqrt(1 + 4 * (2 * target + (long) i * i - i))) / 2;
            if (j == (int)j) {
                vector<int> ans;
                for (int k = i; k <= j; ++k)
                    ans.push_back(k);
                res.push_back(ans);
            }
            ++i;
        }
        return res;
    }
};
#endif

int main() {

    Solution solve;
    for (auto ex:solve.findContinuousSequence(15)) {
        for (auto in : ex)
            cout << in << ' ';
        cout << endl;
    }


    cout << "\nFinish";
    return 0;
}
