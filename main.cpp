#include <bits/stdc++.h>
using namespace std;

#if 1
/// 含手续费
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee = 0) {
        int n = prices.size();
        int sell = 0, buy = -prices[0];
        for (int i = 1; i < n; ++i) {
            sell = max(sell, buy + prices[i] - fee);
            buy = max(buy, sell - prices[i]);
        }
        return sell;
    }
};

#elif 1

/// 含冷冻期
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        // f[i][0]: 手上持有股票的最大收益
        // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};

#elif 1

/// 固定次数买卖
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        vector<int> buy(k, -prices[0]);
        vector<int> sell(k, 0);
        for (int i = 1; i < prices.size(); ++i) {
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for (int j = 1; j < k; ++j) {
                buy[j] = max(buy[j], sell[j-1]-prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k-1];
    }
};
#elif 1
/// 多次买卖
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int curr = prices[i] - prices[i-1];
            if (curr > 0)
                profit += curr;
        }
        return profit;
    }
};
#elif 1
/// 单次买卖
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
#endif

int main() {
    vector<int> prices = {7,1,5,3,6,4};

    Solution solve;
    cout << solve.maxProfit(prices) << endl;

    return 0;
}