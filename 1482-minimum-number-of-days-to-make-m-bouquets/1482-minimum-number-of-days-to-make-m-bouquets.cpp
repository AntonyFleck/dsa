class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int temp = k;
        for (const auto time : bloomDay) {
            if (time <= day) {
                temp--;
            } else {
                temp = k;
            }
            if (temp == 0) {
                m--;
                temp = k;
            }
        }
        if (m <= 0)
            return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int low = INT_MAX, high = INT_MIN;
        for (auto day : bloomDay) {
            high = max(high, day);
            low = min(low, day);
        }
        int ans = high;
        long long m1 = m;
        long long k1 = k;

        long long n = bloomDay.size();
        long long flowers = m1 * k1;
        if (flowers > n)
            return -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};