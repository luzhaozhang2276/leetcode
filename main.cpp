#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == m)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
};

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,9};

    Solution solve;
    cout << "num = " << solve.missingNumber(nums) << endl;

    cout << "\nFinish";
    return 0;
}
