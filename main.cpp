#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int row_;
    int col_;
    int x_;
    int y_;
    int path_;
    inline bool inMatrix(int i, int j) const {
        return !(i < 0 || i >= row_ || j < 0 || j >= col_);
    }

    bool dfs(vector<vector<int>> &matrix, int i, int j) {
        if (i == x_ && j == y_)
            return true;

        if (!inMatrix(i, j) || matrix[i][j] != 1)
            return false;

        // 访问标记
        matrix[i][j] = 0;
        path_++;

        if (dfs(matrix, i, j - 1) ||
            dfs(matrix, i, j + 1) ||
            dfs(matrix, i - 1, j) ||
            dfs(matrix, i + 1, j))
            return true;

        // 回退
        matrix[i][j] = 1;
        path_--;

        return false;
    }

public:
    int solve(vector<vector<int>> &matrix, int a, int b, int x, int y)
    {
        row_ = matrix.size();
        col_ = matrix[0].size();
        x_ = x;
        y_ = y;
        path_ = 0;

        if (matrix[a][b] == 0 || matrix[x][y] == 0)
            return -1;

        if (dfs(matrix, a, b))
            return path_;

        return -1;
    }
};

int main() {
    vector<vector<int>> matrix = {{0, 1, 0, 0},
                                  {1, 1, 0, 0},
                                  {0, 1, 1, 0},
                                  {0, 0, 1, 1}};

    Solution ans;
    cout << ans.solve(matrix, 3, 3, 1, 1) << endl;


    return 0;
}
