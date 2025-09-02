class Solution {
public:
    int f(int m, int n, vector<vector<int>>& dp) {

        if (m < 0 || n < 0)
            return 0;
        if (m == 0 || n == 0)
            return 1;

        if (dp[m][n] != -1)
            return dp[m][n];

        dp[m][n] = f(m - 1, n, dp) + f(m, n - 1, dp);
        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp);
    }
};

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         for (int i = 0; i < m; i++)
//             dp[i][0] = 1;
//         for (int i = 0; i < n; i++)
//             dp[0][i] = 1;
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 // int l = 0, r = 0;
//                 // if (i > 0)
//                 //     l = dp[i - 1][j];
//                 // if (j > 0)
//                 //     r = dp[i][j - 1];
//                 // if (i == 0 && j == 0)
//                 //     dp[i][j] = 1;
//                 // else
//                 // dp[i][j] = l + r;
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> dp(n,1);
//         vector<int> row(n, 1);
//         for (int i = 1; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (j == 0)
//                     dp[j] = 1;
//                 else
//                     dp[j] = dp[j - 1] + row[j];
//             }
//             row = dp;
//         }
//         return dp[n - 1];
//     }
// };