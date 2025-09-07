class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        int sum = 0;
        long long minstart = INT_MAX;
        long long maxi = INT_MIN;
        int mini = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            dp[i + 1] = sum;
            if (nums[i] <= 0)
                mini = max(mini, nums[i]);
        }

        if (n == 1)
            return nums[0];

        for (int i = 0; i <= n; i++) {
            if (dp[i] < minstart) {
                minstart = dp[i];
            } else {
                maxi = max(maxi, dp[i] - minstart);
            }
        }
        if (maxi == INT_MIN) {
            return mini;
        }
        return maxi;
    }
};