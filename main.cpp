#include <bits/stdc++.h>
using namespace std;

/// 200. 岛屿数量

/// DFS
// 外层:遍历表格,对‘1'进行DFS
// 内层:DFS遍历,对当前层置0
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};
/// BFS
// 内层使用queue进行BFS遍历

int main() {
    Solution solve;

    cout << "\nFinish" << endl;
    return 0;
}
