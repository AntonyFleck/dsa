class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        long long low = 1, high = piles[piles.size() - 1],hours=0, k = INT_MAX;
        // if (h == piles.size())
        //     return piles[piles.size() - 1];
        while (low <= high) {
            long long mid = (low + high) / 2;
            for(int y=0;y<piles.size();y++){
                    hours+=(int)ceil((double)piles[y]/mid);
            }
            if (hours<=h) {
                k = min(k, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
            hours=0;
        }
        return k;
    }
};