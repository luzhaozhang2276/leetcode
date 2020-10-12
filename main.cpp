#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        bool found = false;
        int row = 0;
        int column = matrix.front().size()-1;

        while (row < matrix.size() && column >=0)
        {
            if (matrix[row][column] == target)
            {
                found = true;
                break;
            } else if (matrix[row][column] > target)
                --column;
            else
                ++row;
        }

        return found;
    }
};

//class Solution {
//public:
//    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//        int i = matrix.size() - 1, j = 0;
//        while(i >= 0 && j < matrix[0].size())
//        {
//            if(matrix[i][j] > target) i--;
//            else if(matrix[i][j] < target) j++;
//            else return true;
//        }
//        return false;
//    }
//};

int main() {
    vector<vector<int> > nums;
    nums.push_back({1,4,7,11,15});
    nums.push_back({2,5,8,12,19});
    nums.push_back({3,6,9,16,22});
    nums.push_back({10,13,14,17,24});
    nums.push_back({18,21,23,26,30});

    Solution s;
    int target = 20;
    cout << s.findNumberIn2DArray(nums, target) << endl;

    cout << "\nFinish" << endl;
    return 0;
}
