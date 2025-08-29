class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        vector<int> dups = bloomDay;
        sort(dups.begin(), dups.end());
        long long m_dash = m, k_dash = k;

        if (bloomDay.size() < m_dash * k_dash)
            return -1;
        long long low = dups[0], done = 0, high = dups[dups.size() - 1], days;
        while (low <= high && low >= dups[0]) {
            long long mid = (low + high) / 2;
            long long i = 0, temp = k, count = 0;
            while (i < bloomDay.size()) {
                if (bloomDay[i] - mid <= 0 && temp >= 0) {
                    temp--;
                    i++;
                    if (temp == 0) {
                        count++;
                        temp = k;
                    }
                    if (count == m) {
                        days = min(days, mid);
                        done = 1;
                        break;
                    }

                } else {
                    temp = k;
                    i++;
                }
            }
            if (done == 0) {
                low = mid + 1;
            } else
                high = mid - 1;
            done = 0;
        }
        return low;
    }
};