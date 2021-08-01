#include <bits/stdc++.h>

using namespace std;

/// 79. 单词搜索
// 回溯法  剪枝
class Solution {
    string word_;
    int n, m;
    vector<pair<int, int>> dir = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
    bool check(vector<vector<char>>& board, int i, int j, int k) {
        if (board[i][j] != word_[k])
            return false;
        else if (k == word_.size() - 1)
            return true;

        board[i][j] = '0';
        int bFind = false;
        for (const auto &p : dir) {
            int ni = i + p.first, nj = j + p.second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if (check(board, ni, nj, k + 1)) {
                    bFind = true;
                    break;
                }
            }
        }

        board[i][j] = word_[k];
        return bFind;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        word_ = std::move(word);
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (check(board, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};


int main() {
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    Solution solve;
    cout << "res = " << solve.exist(board, word) << endl;


    cout << "\nFinish";
    return 0;
}