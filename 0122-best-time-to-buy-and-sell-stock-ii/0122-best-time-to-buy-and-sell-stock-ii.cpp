class Solution {
public:
    int f(int index, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {

        if (index >= prices.size())
            return 0;

        if (dp[index][canBuy] != -1)
            return dp[index][canBuy];

        if (canBuy) {
            return dp[index][canBuy] =
                       max(-prices[index] + f(index + 1, 0, prices, dp),
                           f(index + 1, 1, prices, dp));
        }

        return dp[index][canBuy] =
                   max(prices[index] + f(index + 1, 1, prices, dp),
                       f(index + 1, 0, prices, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};