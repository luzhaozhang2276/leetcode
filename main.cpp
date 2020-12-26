#include <bits/stdc++.h>
using namespace std;

#if 0
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return res;

        int start = 0;
        while (matrix.size() > 2*start && matrix[0].size() > 2*start)
        {
            int endX = matrix[0].size() - 1 - start;
            int endY = matrix.size() -1 -start;

            // 左右
            for (int i = start; i <= endX; ++i)
                res.push_back(matrix[start][i]);
            // 上下
            if (start < endY) {
                for (int i = start + 1; i <= endY; ++i)
                    res.push_back(matrix[i][endX]);
            }
            // 右左
            if (start < endX && start < endY){
                for (int i = endX-1; i >= start; --i)
                    res.push_back(matrix[endY][i]);
            }
            //下上
            if (start < endX && start < endY - 1) {
                for (int i = endY - 1; i >= start + 1; --i)
                    res.push_back(matrix[i][start]);
            }

            ++start;
        }

        return res;
    }

private:
    vector<int> res;
};

#elif 1
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return res;

        // 左右上下四个边界: l r t b
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        while (true)
        {
            // left to right
            for (int i = l; i <= r; ++i)
                res.push_back(matrix[t][i]);
            if (++t > b)
                break;
            // top to bottom
            for (int i = t; i <= b; ++i)
                res.push_back(matrix[i][r]);
            if (l > --r)
                break;
            // right to left
            for (int i = r; i >= l; --i)
                res.push_back(matrix[b][i]);
            if (t > --b)
                break;
            // bottom to top
            for (int i = b; i >= t; --i)
                res.push_back(matrix[i][l]);
            if (++l > r)
                break;
        }

        return res;
    }

private:
    vector<int> res;
};
#endif

int main() {
    /// 数据生成 ptr
    vector<vector<int> > matrix = {{1,2,3},{4,5,6},{7,8,9}};

    Solution solve;

    for (auto p:solve.spiralOrder(matrix))
        cout << p << " ";

    cout << "\nFinish" << endl;
    return 0;
}
