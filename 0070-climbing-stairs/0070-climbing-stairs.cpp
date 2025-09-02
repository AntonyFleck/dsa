class Solution {
public:
    int f(int index, int n, vector<int>& dp) {
        if (index >= n)
            return 1;
        if (dp[index] != -1)
            return dp[index];
        return dp[index] = f(index + 1, n, dp) + f(index + 2, n, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return f(1, n, dp);
    }
};