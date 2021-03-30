#include <bits/stdc++.h>
using namespace std;

/// 695. 岛屿的最大面积

/// DFS
// 外层:遍历表格,对‘1'进行DFS
// 内层:DFS遍历,对当前层置0
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, currArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    currArea = dfs(grid, i, j);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;

        return 1 + dfs(grid, i-1, j) + dfs(grid, i+1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
    }
};
/// BFS
// 内层使用queue进行BFS遍历

int main() {
    Solution solve;

    cout << "\nFinish" << endl;
    return 0;
}
