class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
        unordered_map<int, int> freq;
        freq[0] = 1; // base case: one way to have prefixSum = 0
        int prefix = 0, ans = 0;
        for (int x : nums) {
            prefix += x;
            // want prefix_j so that prefix - prefix_j = K ⇒ prefix_j = prefix -
            // K
            if (auto it = freq.find(prefix - K); it != freq.end())
                ans += it->second;
            // record current prefix
            freq[prefix]++;
        }
        return ans;
    }
};