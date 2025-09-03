class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int n = nums.size();
        if (sum % 2 != 0)
            return false;

        vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < sum / 2 + 1; j++) {
                bool take = false;
                if (nums[i] <= j)
                    take = dp[i - 1][j - nums[i]];

                dp[i][j] = take || dp[i - 1][j];
            }
        }

        return dp[n - 1][sum / 2];
    }
};