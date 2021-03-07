#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, maxdif = 0;
        for (auto price : prices) {
            cost = min(cost, price);
            maxdif = max(maxdif, price - cost);
        }
        return maxdif;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};

    Solution solve;
    cout << "profit = " << solve.maxProfit(prices) << endl;

    cout << "\nFinish";
    return 0;
}
