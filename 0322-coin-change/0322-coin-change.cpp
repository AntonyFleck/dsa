class Solution {
public:
    int f(int amount, vector<int>& coins, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        if (dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for (int coin : coins) {
            int res = f(amount - coin, coins, dp);
            if (res != INT_MAX) {
                ans = min(ans, 1 + res);
            }
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = f(amount, coins, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
