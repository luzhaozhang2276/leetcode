#include <bits/stdc++.h>
using namespace std;

#if 0
/// DP 动态规划
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0)           // 处理边界
                    continue;
                if (i == 0)
                    grid[i][j] += grid[i][j-1]; // 边界
                else if (j == 0)
                    grid[i][j] += grid[i-1][j]; // 边界
                else
                    grid[i][j] += max(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};

#elif 1
/// DP 预处理边界值
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int i = 1; i < m; ++i)
            grid[i][0] += grid[i-1][0];
        for (int j = 1; j < n; ++j)
            grid[0][j] += grid[0][j-1];

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                    grid[i][j] += max(grid[i][j-1], grid[i-1][j]);

        return grid[m-1][n-1];
    }
};

#endif

int main() {
    vector<vector<int>> grid;
    grid.push_back({1,3,1});
    grid.push_back({1,5,1});
    grid.push_back({4,2,1});

    Solution solve;
    cout << "sum = " << solve.maxValue(grid) << endl;

    cout << "\nFinish";
    return 0;
}
