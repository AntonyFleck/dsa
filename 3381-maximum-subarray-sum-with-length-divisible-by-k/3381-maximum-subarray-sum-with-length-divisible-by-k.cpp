class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> map;
        long long sum = LONG_MIN;
        long long prefix = 0LL;
        map[0] = 0LL;
        for (int i = 1; i <= nums.size(); i++) {
            prefix += nums[i - 1];
            if (map.find(i % k) != map.end()) {
                sum = max(sum, prefix - map[i % k]);
                map[i % k] = min(prefix, map[i % k]);
            } else
                map[i % k] = prefix;
        }
        return sum;
    }
};