class Solution {
public:
    int f(int row, int index, vector<vector<int>>& triangle,
          vector<vector<int>>& dp, int n, int m) {

        if (row == n - 1) {
            return triangle[n - 1][index];
        }

        if (dp[row][index] != INT_MAX)
            return dp[row][index];

        return dp[row][index] = triangle[row][index] +
                                min(f(row + 1, index, triangle, dp, n, m),
                                    f(row + 1, index + 1, triangle, dp, n, m));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        return f(0, 0, triangle, dp, n, m);
    }
};