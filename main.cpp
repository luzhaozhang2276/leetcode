#include <bits/stdc++.h>

using namespace std;

/// 56. 合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (L <= res.back()[1])
                res.back()[1] = max(res.back()[1], R);
            else
                res.push_back(intervals[i]);
        }

        return res;
    }
};

int main() {
    vector<vector<int>> intervals;
    // intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    intervals = {{1,3}, {8,10}, {2,6}, {15,18}};

    Solution solve;
    for (const auto &nums : solve.merge(intervals))
        cout << nums[0] << ',' << nums[1] << endl;

    cout << "\nFinish";
    return 0;
}