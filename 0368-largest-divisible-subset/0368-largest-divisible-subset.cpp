class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);       // dp[i] = max length ending at i
        vector<int> prev(n, -1);    // prev[i] = previous index in the subset
        int max_idx = 0;            // index of max length subset

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[max_idx]) {
                max_idx = i;
            }
        }

        // Reconstruct the subset
        vector<int> res;
        for (int i = max_idx; i >= 0; i = prev[i]) {
            res.push_back(nums[i]);
            if (prev[i] == -1) break;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
