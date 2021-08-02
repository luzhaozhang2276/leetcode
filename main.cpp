#include <bits/stdc++.h>

using namespace std;

/// 84. 柱状图中最大的矩形
// 单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left(n), right(n);

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        st = stack<int>();
        for (int i = n-1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {2,1,5,6,2,3};

    Solution solve;
    cout <<"res = " << solve.largestRectangleArea(nums) << endl;

    cout << "\nFinish";
    return 0;
}