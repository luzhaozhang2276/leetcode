#include <bits/stdc++.h>
using namespace std;

/// 不必像书中那样重新顺序查找
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high]) {
                high = pivot;
            }
            else if (numbers[pivot] > numbers[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return numbers[low];
    }
};


int main() {
//    vector<int> nums{3,4,5,1,2};
//    vector<int> nums{2,2,2,0,1};
//    vector<int> nums{1,2,3,4,5};
//    vector<int> nums{10,1,10,10,10};
    vector<int> nums{10,10,10,1,10};
    Solution s;
    cout << "min: " << s.minArray(nums) << endl;

    cout << "\nFinish" << endl;
    return 0;
}
