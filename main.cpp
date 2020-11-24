#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    bool exist(vector<vector<char>>& board, const string& word) {
        //cout << board.size() << "*" << board[0].size() << " , " << word.size() << endl;
        rows = board.size();
        cols = board[0].size();
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col) {
                if (dfs(board, word, row, col, 0))
                    return true;
            }
        }

        return false;
    }

private:
    int rows;
    int cols;
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int k)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[k])
            return false;
        if (k == word.size()-1)
            return true;


        board[r][c] = '\0';
        bool res = dfs(board, word, r-1, c, k+1) || dfs(board, word, r+1, c, k+1)
                || dfs(board, word, r, c-1, k+1) || dfs(board, word, r, c+1, k+1);

        board[r][c] = word[k];

//        if(res)
//            cout << board[r][c] << endl;
        return res;
    }
};
//    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
//    vector<vector<char>> board = {{'A','B','C'},{'S','F','C'},{'A','D','E'}};
//    string word = "ABCCED";
//    string word = "ABCCFSAD";
//    word = '\0';

//    Solution s;
//    cout << s.exist(board, word);

*/

class Solution {
public:
    int rows;
    int cols;
    int k_;
    int count = 0;
    bool vis[100][100] = {};

    int movingCount(int m, int n, int k) {
        rows = m;
        cols = n;
        k_ = k;

        dfs(0, 0);
        return count;
    }

    static int getsum(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    bool dfs(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols || (getsum(r) + getsum(c) > k_) || vis[r][c])
            return false;

//        cout << "[" << r << "," << c << "]" << endl;

        vis[r][c] = true;
        count++;

        dfs(r-1, c) + dfs(r+1, c) + dfs(r, c-1) + dfs(r, c+1);
        return true;
    }
};

int main() {
    Solution s;
    cout << s.movingCount(3,2,17) << endl;


    cout << "\nFinish" << endl;
    return 0;
}
