class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                curr[0][j] = max(prices[i] + prev[1][j - 1], prev[0][j]);
                curr[1][j] = max(-prices[i] + prev[0][j], prev[1][j]);
                prev = curr;
            }
        }
        return curr[1][k];
    }
};