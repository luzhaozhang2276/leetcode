#include <bits/stdc++.h>
using namespace std;

#if 0
/// 双指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty())
            return nums;
        return reorder(nums, isEven);
    }

    vector<int> reorder(vector<int>& nums, bool (*func)(int))
    {
        auto begin = nums.begin();
        auto end = nums.end()-1;

        while (begin <= end)
        {
            while (begin < end && !func(*begin))
                begin++;

            while (begin < end && func(*end))
                end--;

            if (begin < end)
            {
                int temp = *begin;
                *begin = *end;
                *end = temp;
            }
        }
        return nums;
    }

    static bool isEven(int n)
    {
        return (n & 0x1) == 0;
    }
};

#elif 1
/// 快慢双指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        auto fast = nums.begin();
        auto slow = nums.begin();

        while (fast != nums.end())
        {
            if (*fast & 1)  // odd
            {
                swap(*fast, *slow);
                slow++;
            }
            fast++;
        }
        return nums;
    }
};

#endif


int main() {
    vector<int> nums = {1,2,4,3};
    for (const auto &p:nums)
        cout << p << " ";
    cout << endl;

    Solution solve;
    for (auto &p:solve.exchange(nums))
        cout << p << " ";


    cout << "\nFinish" << endl;
    return 0;
}
