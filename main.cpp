#include <bits/stdc++.h>
using namespace std;

#if 0
// hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> Imap;
        for (int i = 0; i < nums.size(); ++i) {
            if (Imap.find(nums[i]) == Imap.end())
                Imap.insert(pair<int, int>(nums[i], 1));
            else {
                int temp = Imap[nums[i]];
                if (2*(temp+1) > nums.size())
                    return nums[i];
                Imap.erase(nums[i]);
                Imap.insert(pair<int, int>(nums[i], temp+1));
            }
        }

        for (auto &p:Imap)
            cout << p.first << " : " << p.second << endl;

        return Imap.begin()->first;
    }
};

#elif 1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0, votes = 0;
        for (int num : nums)
        {
            if (votes == 0)
                x = num;
            votes += (num == x ? 1 : -1);
        }
        // return x;
        // 验证 x 是否为众数
        int count = 0;
        for(int num : nums)
            if(num == x) count++;
        return count > nums.size() / 2 ? x : 0; // 当无众数时返回 0
    }
};
#endif

int main() {
    vector<int> nums = {3};

    Solution solve;
    cout << solve.majorityElement(nums) << endl;

    cout << "\nFinish";
    return 0;
}
