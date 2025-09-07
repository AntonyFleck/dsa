class Solution {
public:
    int f(int index, int canBuy, int transaction, vector<int>& prices,
          vector<vector<vector<int>>>& dp) {
        if (index >= prices.size() || transaction == 0)
            return 0;

        if (dp[index][canBuy][transaction] != -1)
            return dp[index][canBuy][transaction];

        if (canBuy) {
            return dp[index][canBuy][transaction] =
                       max(-prices[index] +
                               f(index + 1, 0, transaction, prices, dp),
                           f(index + 1, 1, transaction, prices, dp));
        }
        return dp[index][canBuy][transaction] = max(
                   prices[index] + f(index + 1, 1, transaction - 1, prices, dp),
                   f(index + 1, 0, transaction, prices, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};