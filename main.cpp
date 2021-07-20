#include <bits/stdc++.h>

using namespace std;

#if 0
/// 外圈往内圈
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int times = 0; times < n / 2; ++times) {
            int len = n - 2 * times;
            for(int i = 0; i < len - 1; ++i){
                int temp = matrix[times][times + i];
                matrix[times][times + i] = matrix[times + len - i - 1][times];
                matrix[times + len - i - 1][times] = matrix[times + len - 1][times + len - i - 1];
                matrix[times + len - 1][times + len - i - 1] = matrix[times + i][times + len - 1];
                matrix[times + i][times + len - 1] = temp;
            }
        }
    }
};
#else
/// 水平 + 对角线 翻转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }

        // 对角线
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
#endif

int main() {
    vector<vector<int>> matrix;
    matrix.push_back({5,1,9,11});
    matrix.push_back({2,4,8,10});
    matrix.push_back({13,3,6,7});
    matrix.push_back({15,14,12,16});

    Solution solve;
    solve.rotate(matrix);
    for (const auto & nums : matrix) {
        for (const auto & num : nums)
            cout <<num << ' ';
        cout << endl;
    }

    cout << "\nFinish";
    return 0;
}